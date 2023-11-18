//
// Created by anatol on 14.11.23.
//
#include "Ant.h"
#include "GreedyAnt.h"

int GreedyAnt::nextLibrary(std::vector<Library> &libraries, int iter, int p) {

    int bestIdx = -1;
    double bestValue{};
	double previous{};
	for (size_t i = 0; i < libraries.size(); i++)
	{
		if (!m_signedIn[i])
		{
			double approxValue = libraries[i].getApproxValue(m_deadline);
			if (approxValue == -1.0)
				continue;
			
			if (approxValue > bestValue) {
				bestValue = approxValue;
				bestIdx = i;
			}
		}
	}

	if (bestIdx == -1) {
		return -1;
	}	

	int pickedLibrary = bestIdx;

	m_signedIn[pickedLibrary] = libraries[pickedLibrary].getNumberOfBooksScanned(m_deadline);
	m_deadline -= libraries[pickedLibrary].GetSignUpTime();
	m_path.push_back({pickedLibrary, iter});

	return pickedLibrary;
}

GreedyAnt::GreedyAnt(int deadline, int numberOfLibraries) : Ant(deadline, numberOfLibraries)
{}