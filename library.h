#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"

class Library
{
    std::vector<Book> m_books;
    std::vector<int> m_prefixSums;
	std::vector<double> m_pheromonesPrefixSums;
    int m_numberOfBooks;
    int m_totalValue;
    int m_signUpTime;
    int m_totalTime;
    int m_booksPerDay;
    int m_lastBook;
	int m_maxTime;

public:
	Library();
    Library(int n, int scanTime, int perDay);
    void addBook(int number, int value);
    void sort();
    void calculateTotalTime();
    void calculatePrefixSums();
	void calculatePheromonesPrefixSums();
    double getApproxValue(int time, int type);
	double getBookPheromones(int time);
    std::vector<Book> getBooks(int numberOfBooksToReturn);
    int getNumberOfBooksScanned(int deadline);

    inline int GetSignUpTime() { return m_signUpTime; }
    inline int GetTotalTime() { return m_totalTime; }
	inline int getBooksPerDay() { return m_booksPerDay; }
    inline std::vector<Book> GetAllBooks() { return m_books; }
};

#endif
