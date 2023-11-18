#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <random>
#include <unordered_set>
#include "Library.h"

class Ant
{
protected:
	int m_deadline;
	std::vector<std::pair<int, int>> m_path;
	std::vector<int> m_signedIn;
	int m_totalValue;

public:
	// static int m_alfa, m_beta, m_gamma;
	// static std::default_random_engine generator;

	// double calculateProbability(Library &lib, int idx, int iter, int p);
	// int pickLibrary(std::vector<std::pair<double, int>> &probabilities);
	static std::map<std::pair<int, int>, std::pair<double, int>> pheromones;
	static std::map<std::pair<int, int>, double> deltaPheromones;
	static std::vector<std::pair<double, int>> bookPheromones;
	static std::vector<double> bookDeltaPheromones;

	Ant(){};
	Ant(int deadline, int numberOfLibraries);
	virtual int nextLibrary(std::vector<Library> &libraries, int iter, int p);
	int mutate(std::vector<Library> &libraries, int deadline);
	int totalValue(std::vector<Library> &libraries, int deadline);
	void calculatePheromonesDeltas(std::vector<Library> &libraries, int bestValue);
	void clear(int deadline);
	std::vector<int> GetPath();
	inline int getTotalValue() { return m_totalValue; };
	inline bool operator<(const Ant &ant) const { return m_deadline > ant.m_deadline; }
};

#endif
