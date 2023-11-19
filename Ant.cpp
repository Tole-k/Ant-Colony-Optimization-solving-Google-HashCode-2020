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

Ant::Ant(int deadline, int numberOfLibraries)
    : m_signedIn(numberOfLibraries), m_deadline(deadline)
{
    m_totalValue = 0;
}

int Ant::mutate(std::vector<Library> &libraries, int deadline, bool localSearch)
{
    int bestValue = totalValue(libraries, deadline);
    int iterations = 0;
    for (int i = 0; (i < (localSearch ? m_path.size() - 1 : 1000)) && iterations < 50; i++)
    {
        int deadline_copy = deadline;

        int idx1, idx2;
        if (localSearch)
        {
            idx1 = i;
            idx2 = i + 1;
            std::swap(m_path[idx1], m_path[idx2]);
        }
        else
        {
            idx1 = rand() % m_path.size();
            idx2 = rand() % m_path.size();
            std::swap(m_path[idx1], m_path[idx2]);
        }

        int total = totalValue(libraries, deadline);

        if (total > bestValue)
        {
            bestValue = total;
            ++iterations;
            i = 0;
        }
        else
        {
            std::swap(m_path[idx1], m_path[idx2]);
        }
        deadline = deadline_copy;
    }
    totalValue(libraries, deadline);
    return bestValue;
}

int Ant::totalValue(std::vector<Library> &libraries, int deadline)
{
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
    m_totalValue = total;
    return m_totalValue;
}

void Ant::calculatePheromonesDeltas(std::vector<Library> &libraries, int bestValue)
{
    int totalValue = getTotalValue();
    for (int i = 0; i < m_path.size() - 1; i++)
    {
        deltaPheromones[std::make_pair(i, m_path[i + 1].first)] += (1 / (1 + (double)(bestValue - totalValue) /
                                                                                 totalValue));
        bookDeltaPheromones[m_path[i].first] += (1 / (1 + (double)(bestValue - totalValue) / totalValue)) / 1000;
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
    for (int i = 0; i < m_path.size(); i++)
        toReturn[i] = m_path[i].first;
    return toReturn;
}

std::map<std::pair<int, int>, std::pair<double, int>> Ant::pheromones;
std::map<std::pair<int, int>, double> Ant::deltaPheromones;

std::vector<std::pair<double, int>> Ant::bookPheromones;
std::vector<double> Ant::bookDeltaPheromones;
