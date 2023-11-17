
#include "PheromoneAnt.h"
PheromoneAnt::Ant(int deadline, int numberOfLibraries):Ant(deadline, numberOfLibraries)
{}
int PheromoneAnt::pickLibrary(std::vector<std::pair<double, int>> &probabilities) 
{
	double sum = probabilities.back().first;

	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	double num = distribution(generator) * sum;

	int idx{};
	for (int i = (int)probabilities.size(); i > 0; i /= 2)
	{
		while (idx + i < (int)probabilities.size() && probabilities[idx + i - 1].first <= num)
			idx += i;
	}
	//std::cerr << idx << " " << probabilities.size() << " " << probabilities[idx].second << std::endl;
	return probabilities[idx].second;
}
int PheromoneAnt::nextLibrary(std::vector<Library> &libraries, int iter, int p)
{
	std::vector<std::pair<double, int>> probabilities; // probability, index of library
	probabilities.push_back({0, -1});

	double previous{};
	for (int i = 0; i < libraries.size(); i++)
	{
		if (!m_signedIn[i])
		{
			double prob = calculateProbability(libraries[i], i, iter, p);
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

	return pickedLibrary;
}
double PheromoneAnt::calculateProbability(Library &lib, int idx, int iter, int p)
{

	double totalValue = lib.getApproxValue(m_deadline, m_type);
	if (totalValue == -1.0)
		return -1.0;

	double numOfPheromones, numOfBooksPheromones = lib.getBookPheromones(m_deadline);
	if (m_path.size() == 0)
		numOfPheromones = 1.0;
	else {
		numOfPheromones = pheromones.count({m_path.size(), idx}) ? pheromones[std::make_pair(m_path.size(), idx)].first * std::pow(1.0 - p, iter - (double)pheromones[std::make_pair(m_path.size(), idx)].second) : 1 * std::pow(1.0 - p, (double)iter);
	}
	// faster option:
	//  numOfPheromones = pheromones.count({iter / 100, idx}) ? pheromones[std::make_pair(iter / 100, idx)].first : 1;

	double probability = pow(totalValue, m_alfa) * pow(numOfPheromones, m_beta) * pow(numOfBooksPheromones, m_gamma);
	// double probability = pow(totalValue, m_alfa) * pow(numOfPheromones, m_beta);
m_signedIn(numberOfLibraries)
	return probability;
}