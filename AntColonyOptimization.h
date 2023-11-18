#ifndef ANT_COLONY_OPTIMIZATION_H
#define ANT_COLONY_OPTIMIZATION_H
#include <vector>
#include <array>
#include "Ant.h"


class ACO
{
	int m_numberOfIterations;
	int m_numberOfAnts;
	double m_p;
	std::vector<Ant> m_ants;
	int m_deadline;
	int m_best;
	std::vector<int> m_bestPath;
	std::array<std::pair<int, Ant>, 10> m_bests;
	Ant m_bestAnt;

public:
	ACO(int numberOfAnts, int deadline, double p, int numberOfLibraries, int numberOfIterations);
	void createAnts(int numberOfLibraries);
	void calculateBestValue(std::vector<Library> &libraries);

public:
	void calculatePheromones(std::vector<Library> &libraries, int iter, bool type);
	void normalize();
	int iteration(std::vector<Library> &libraries, int index);
	void mutate(std::vector<Library> &libraries, int iter);
	std::vector<int> GetBestPath() { return m_bestPath; }
	int getBest() { return m_best; }
	Ant getBestAnt() { return m_bestAnt; }
};

#endif
