#include "ant.h"
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

double Ant::calculateProbability(Library &lib, int idx, int iter, int p)
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

	return probability;
}

int Ant::pickLibrary(std::vector<std::pair<double, int>> &probabilities)
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

int Ant::pickBest(std::vector<std::pair<double, int>> &probabilities)
{
	sort(probabilities.begin(), probabilities.end());
	return probabilities.back().second;
}

Ant::Ant(int deadline, int numberOfLibraries, int type)
	: m_signedIn(numberOfLibraries)
{
	m_deadline = deadline;
	m_type = type;
	m_totalValue = 0;
}

int Ant::nextLibrary(std::vector<Library> &libraries, int iter, int p)
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
					if(++scannedFromThisLib >= signedIn)
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
	//std::cerr << "totalValue " << deadline << " " << m_path[0].first << " " << m_path[0].second << std::endl;
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
				if(++scannedFromThisLib >= signedIn)
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
	for (int i = 0; i < m_path.size() - 1; i++)
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
	for(auto & it : bookDeltaPheromones)
		it = 0;
}

std::vector<int> Ant::GetPath()
{
	std::vector<int> toReturn(m_path.size());
	for (int i = 0; i < m_path.size(); i++)
		toReturn[i] = m_path[i].first;
	return toReturn;
}

int Ant::m_alfa = 5.0;
int Ant::m_beta = 1.0;
int Ant::m_gamma = 1.0;
std::map<std::pair<int, int>, std::pair<double, int>> Ant::pheromones;
std::map<std::pair<int, int>, double> Ant::deltaPheromones;
std::default_random_engine Ant::generator;

std::vector<std::pair<double, int>> Ant::bookPheromones;
std::vector<double> Ant::bookDeltaPheromones;
