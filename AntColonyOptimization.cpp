#include "AntColonyOptimization.h"
#include <chrono>

ACO::ACO(int numberOfAnts, int deadline, double p, int numberOfLibraries, int numberOfIterations)
{
    m_numberOfIterations = numberOfIterations;
    m_numberOfAnts = numberOfAnts;
    m_deadline = deadline;
    m_p = p;
    m_best = 0;

    createAnts(numberOfLibraries);
}

void ACO::set_best(std::vector<Library> &libraries, const std::shared_ptr<Ant> &best)
{
    m_best = best->totalValue(libraries, m_deadline);
    m_bestAnt = best;
    m_bestPath = best->GetPath();
    m_bests[0] = {m_best, m_bestAnt};
}

void ACO::calculateBestValue(std::vector<Library> &libraries)
{
    for (auto &m_ant : m_ants)
    {
        int totalValue = m_ant->totalValue(libraries, m_deadline);
        if (totalValue > m_best)
        {
            m_best = totalValue;
            m_bestPath = m_ant->GetPath();
            m_bestAnt = m_ant;
        }
    }
}

void ACO::createAnts(int numberOfLibraries)
{
    for (int i = 0; i < m_numberOfAnts; i++)
    {
        m_ants.push_back(std::shared_ptr<Ant>(new PheromoneAnt(m_deadline, numberOfLibraries)));
    }
}

void ACO::calculatePheromones(std::vector<Library> &libraries, int iter, bool type)
{
    long long totalSum{};
    std::vector<std::pair<int, int>> totalValues;
    type ? totalValues.resize(m_ants.size()) : totalValues.resize(10);
    if (type)
    {
        for (int i = 0; i < (int)m_ants.size(); i++)
        {
            m_ants[i]->totalValue(libraries, m_deadline);
            totalValues[i] = {m_ants[i]->getTotalValue(), i};
            int totalValue = m_ants[i]->getTotalValue();
            totalSum += totalValue;
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            m_bests[i].second->totalValue(libraries, m_deadline);
            totalValues[i] = {m_bests[i].second->getTotalValue(), i};
            int totalValue = m_bests[i].second->getTotalValue();
            totalSum += totalValue;
        }
    }
//    std::cerr << "Average: " << totalSum / m_ants.size() << std::endl;
    std::sort(totalValues.begin(), totalValues.end());
    std::reverse(totalValues.begin(), totalValues.end());

    for (int i = 0; i < std::min(50, (int)totalValues.size()); i++)
    {
        m_ants[totalValues[i].second]->calculatePheromonesDeltas(libraries, m_best, m_deadline);
        if (totalValues[i].first > m_best)
        {
            m_best = totalValues[i].first;
            if (type)
            {
                m_bestPath = m_ants[i]->GetPath();
                m_bestAnt = m_ants[i];
            }
            else
            {
                m_bestPath = m_bests[i].second->GetPath();
                m_bestAnt = m_bests[i].second;
            }
        }
        if (type && totalValues[i].first > m_bests.back().first)
        {
            m_bests.back() = {totalValues[i].first, m_ants[i]};
            for (int j = (int)m_bests.size() - 1; m_bests[j].first > m_bests[j - 1].first && j > 0; j--)
            {
                std::swap(m_bests[j], m_bests[j - 1]);
            }
        }
    }
    int multiplier = (type ? 1 : 2);
    for (auto &[road, delta] : Ant::deltaPheromones)
    {
        Ant::pheromones[road].first = (std::pow(1.0 - m_p, iter - (double)Ant::pheromones[road].second - 1) * Ant::pheromones[road].first +
                                       delta * multiplier);
        Ant::pheromones[road].second = iter;
    }
    for (int book = 0; book < (int)Ant::bookDeltaPheromones.size(); book++)
    {
        Ant::bookPheromones[book].first = (std::pow(1.0 - m_p, iter - (double)Ant::bookPheromones[book].second - 1) *
                                               Ant::bookPheromones[book].first +
                                           Ant::bookDeltaPheromones[book] * multiplier);
        Ant::bookPheromones[book].second = iter;
    }
    //     std::cerr << "max pheromones: " << std::max_element(Ant::pheromones.begin(), Ant::pheromones.end(), [](const std::pair<std::pair<int, int>, std::pair<double, int>> &val1, const std::pair<std::pair<int, int>, std::pair<double, int>> &val2)
    //                                                         { return val1.second.first < val2.second.first; })
    //                                            ->second.first
    //               << std::endl;
    //     std::cerr << "max books pheromones: " << std::max_element(Ant::bookPheromones.begin(), Ant::bookPheromones.end(), [](const std::pair<double, int> &val1, const std::pair<double, int> &val2)
    //                                                              { return val1.first < val2.first; })
    //                                                 ->first
    //               << std::endl;
}

int ACO::iteration(std::vector<Library> &libraries, int iter)
{
    std::vector<bool> fullPath(m_ants.size(), false);
    int ends = 0;
    for (auto &ant : m_ants)
        ant->clear(m_deadline);

    while (ends < m_numberOfAnts)
    {
        for (int i = 0; i < m_ants.size(); i++)
        {
            if (!fullPath[i])
            {
                int next = m_ants[i]->nextLibrary(libraries, iter, m_p);
                if (next == -1)
                {
                    fullPath[i] = true;
                    ends++;
                }
            }
        }
    }
    if (!iter)
    {
        calculateBestValue(libraries);
    }
    calculatePheromones(libraries, iter, true);
    for (auto &lib : libraries)
        lib.calculatePheromonesPrefixSums();
    return m_best;
}

void ACO::mutate(std::vector<Library> &libraries, int iter, bool localSearch)
{
    for (auto &[value, ant] : m_bests)
    {
        ant->mutate(libraries, m_deadline, localSearch);
        value = ant->getTotalValue();
    }
    sort(m_bests.begin(), m_bests.end());
    reverse(m_bests.begin(), m_bests.end());
    calculatePheromones(libraries, iter, false);
}

void ACO::normalize()
{
    auto maximum = std::max_element(Ant::pheromones.begin(), Ant::pheromones.end(),
                                    [](const std::pair<std::pair<int, int>, std::pair<double, int>> &val1,
                                       const std::pair<std::pair<int, int>, std::pair<double, int>> &val2)
                                    {
                                        return val1.second.first < val2.second.first;
                                    })
                       ->second.first;
    for (auto &[road, pheromones] : Ant::pheromones)
        pheromones.first = pheromones.first / maximum * 10;
}
