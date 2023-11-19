#include "Library.h"
#include <algorithm>
#include <iostream>
#include "Ant.h"
Library::Library() : m_numberOfBooks(0),
					 m_totalValue(0),
					 m_totalTime(0),
					 m_signUpTime(0),
					 m_booksPerDay(0),
					 m_lastBook(0),
					 m_maxTime(0)
{
}

Library::Library(int n, int scanTime, int perDay) : m_numberOfBooks(n),
													m_totalValue(0),
													m_totalTime(0),
													m_signUpTime(scanTime),
													m_booksPerDay(perDay),
													m_lastBook(0),
													m_maxTime(0)
{
}

void Library::addBook(int number, int value)
{
	m_books.push_back({number, value});
	m_totalValue += value;
	m_lastBook++;
}

void Library::sort()
{
	std::sort(m_books.begin(), m_books.end());
}

void Library::calculateTotalTime()
{
	m_totalTime = (int)m_books.size() / m_booksPerDay + (int)((m_books.size() % m_booksPerDay) != 0) + m_signUpTime;
}

void Library::calculatePrefixSums()
{
	sort();
	int previous = 0;
	for (int i = 0; i < m_numberOfBooks; i += m_booksPerDay)
	{
		int sum{};
		for (int j = 0; j < m_booksPerDay && i + j < m_numberOfBooks; j++)
		{
			sum += m_books[i + j].value;
		}
		m_prefixSums.push_back(sum + previous);
		previous = m_prefixSums.back();
		m_pheromonesPrefixSums.push_back(1);
	}
	m_maxTime = m_numberOfBooks / m_booksPerDay + (m_numberOfBooks % m_booksPerDay > 0);
}

void Library::calculatePheromonesPrefixSums()
{
	double previous = 0;
	for (int i = 0; i < m_numberOfBooks; i += m_booksPerDay)
	{
		double sum{};
		for (int j = 0; j < m_booksPerDay && i + j < m_numberOfBooks; j++)
		{
			sum += Ant::bookPheromones[i + j].first;
		}
		m_pheromonesPrefixSums[i / m_booksPerDay] = sum + previous;
		previous += sum;
	}
	//std::cerr << "previous: " << previous << std::endl;
}

double Library::getApproxValue(int time)
{
	if (time <= m_signUpTime)
		return -1.0;

	double res;
	res = (double)m_prefixSums[std::min(time - m_signUpTime - 1, m_maxTime - 1)] / m_signUpTime;
	return res;
}

double Library::getBookPheromones(int time)
{
	return m_pheromonesPrefixSums[std::min(time - m_signUpTime - 1, m_maxTime - 1)];
}

std::vector<Book> Library::getBooks(int numberOfBooksToReturn)
{
	std::vector<Book> toReturn(numberOfBooksToReturn);
	for (int i = 0; i < numberOfBooksToReturn; i++)
		toReturn[i] = m_books[i];

	return toReturn;
}

int Library::getNumberOfBooksScanned(int deadline)
{
	return (int)std::min((long long)m_numberOfBooks, (long long)(deadline - m_signUpTime) * m_booksPerDay);
}
