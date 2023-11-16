//
// Created by anatol on 14.11.23.
//
#include "ant.h"
#include "GreedyAnt.h"

int nextLibrary(std::vector<Library> &libraries, int iter, int p) {

    /*int bestIdx;
    double bestValue{};
	double previous{};
	for (int i = 0; i < libraries.size(); i++)
	{
		if (!m_signedIn[i])
		{
			double prob = this.calculateProbability(libraries[i], i, iter, p);
			if (prob == -1.0)
				continue;

			probabilities.push_back({(prob + previous), i});
			previous = probabilities.back().first;
		}
	}
	if (probabilities.size() == 1)
		return -1;

	int pickedLibrary = pickLibrary(probabilities);
//	if (pickedLibrary == -1) {
//		for(auto & it : probabilities)
//			std::cerr << it.first << ' ' << it.second << std::endl;
//		std::cerr << " --------------- ERROR -------------------- " << std::endl;
//	}
//    int pickedLibrary = bestIdx;

	m_signedIn[pickedLibrary] = libraries[pickedLibrary].getNumberOfBooksScanned(m_deadline);
	m_deadline -= libraries[pickedLibrary].GetSignUpTime();
	m_path.push_back({pickedLibrary, iter});

	return pickedLibrary;*/
    return 0;

}

GreedyAnt::GreedyAnt(int deadline, int numberOfLibraries, int type) :
Ant(deadline, numberOfLibraries, type)
{}