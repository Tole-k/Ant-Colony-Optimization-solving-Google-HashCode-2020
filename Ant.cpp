#include "Ant.h"
#include <iostream>

double pow(double base, int exponent)
{
	double res = 1;
	for (int i = 0; i < exponent; i++)
	{
		res *= base;
	}
	return res;
}

/*int Ant::pickBest(std::vector<std::pair<double, int>> &probabilities)
{
	sort(probabilities.begin(), probabilities.end());
	return probabilities.back().second;
}*/

Ant::Ant(int deadline, int numberOfLibraries)
	: m_signedIn(numberOfLibraries), m_deadline(deadline)
{
	m_totalValue = 0;
}

int Ant::mutate(std::vector<Library> &libraries, int deadline)
{
	int bestValue = totalValue(libraries, deadline);
	std::cerr << "best val at the begg: " << bestValue << std::endl;
	auto bestPath = m_path;
	int iterations = 0;
	for (int i = 0; i < 500 && iterations < 20; i++)
	{
		auto m_path_copy = m_path;
		int deadline_copy = deadline;
		int idx1 = rand() % m_path.size();
		int idx2 = rand() % m_path.size();
		std::swap(m_path[idx1], m_path[idx2]);
		// if (m_path == m_path_copy)
		// {
		// 	// std::cout << "lipa jest" << std::endl;
		// 	continue;
		// }

		int total{};
		std::unordered_set<int> scanned;
		for (auto &lib : m_path)
		{
			int signedIn = libraries[lib.first].getNumberOfBooksScanned(deadline);
			deadline -= libraries[lib.first].GetSignUpTime();
			int scannedFromThisLib{};
			for (auto &[bookIdx, bookValue] : libraries[lib.first].GetAllBooks())
			{
				if (!scanned.count(bookIdx))
				{
					scanned.insert(bookIdx);
					total += bookValue;
					if (++scannedFromThisLib >= signedIn)
						break;
				}
			}
		}

		if (total > bestValue)
		{
			bestValue = total;
			bestPath = m_path;
			m_path_copy = m_path;
			++iterations;
			i = 0;
			std::cerr << "new best Value: " << bestValue << std::endl;
		}
		m_path = m_path_copy;
		deadline = deadline_copy;
	}
	totalValue(libraries, deadline);
	return bestValue;
}

int Ant::totalValue(std::vector<Library> &libraries, int deadline)
{
	int total{};
	std::unordered_set<int> scanned;
	// std::cerr << "totalValue " << deadline << " " << m_path[0].first << " " << m_path[0].second << std::endl;
	for (auto &lib : m_path)
	{
		int signedIn = libraries[lib.first].getNumberOfBooksScanned(deadline);
		deadline -= libraries[lib.first].GetSignUpTime();
		int scannedFromThisLib{};
		for (auto &[bookIdx, bookValue] : libraries[lib.first].GetAllBooks())
		{
			if (!scanned.count(bookIdx))
			{
				scanned.insert(bookIdx);
				total += bookValue;
				if (++scannedFromThisLib >= signedIn)
					break;
			}
		}
	}
	m_totalValue = total;
	return m_totalValue;
}

void Ant::calculatePheromonesDeltas(std::vector<Library> &libraries, int bestValue)
{
	int totalValue = getTotalValue();
	for (size_t i = 0; i < m_path.size() - 1; i++)
	{
		deltaPheromones[std::make_pair(i, m_path[i + 1].first)] += (1 / (1 + (double)(bestValue - totalValue) / totalValue));
		bookDeltaPheromones[m_path[i].first] += (1 / (1 + (double)(bestValue - totalValue) / totalValue)) / 7;
	}
}

void Ant::clear(int deadline)
{
	m_deadline = deadline;
	for (auto &it : m_signedIn)
		it = 0;
	m_path.clear();
	m_totalValue = 0;
	deltaPheromones.clear();
	for (auto &it : bookDeltaPheromones)
		it = 0;
}

std::vector<int> Ant::GetPath()
{
	std::vector<int> toReturn(m_path.size());
	for (size_t i = 0; i < m_path.size(); i++)
		toReturn[i] = m_path[i].first;
	return toReturn;
}

// int Ant::m_alfa = 5.0;
// int Ant::m_beta = 1.0;
// int Ant::m_gamma = 1.0;
std::map<std::pair<int, int>, std::pair<double, int>> Ant::pheromones;
std::map<std::pair<int, int>, double> Ant::deltaPheromones;
// std::default_random_engine Ant::generator;

std::vector<std::pair<double, int>> Ant::bookPheromones;
std::vector<double> Ant::bookDeltaPheromones;
