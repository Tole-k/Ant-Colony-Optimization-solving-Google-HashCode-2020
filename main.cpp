#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include "Ant.h"
#include "AntColonyOptimization.h"
#include "Library.h"
#include "GreedyAnt.h"
#include <chrono>

void solve(double p)
{
    auto startClock = std::chrono::high_resolution_clock::now();
    int numOfBooks, numOfLibraries, days;
    std::cin >> numOfBooks >> numOfLibraries >> days;
    Ant::bookDeltaPheromones.resize(numOfBooks);
    Ant::bookPheromones.resize(numOfBooks);
    std::vector<Library> libraries(numOfLibraries);
    std::vector<int> values(numOfBooks);

    for (int i = 0; i < numOfBooks; i++)
    {
        std::cin >> values[i];
    }

    for (int i = 0; i < numOfLibraries; i++)
    {
        int n, t, m;
        std::cin >> n >> t >> m;

        libraries[i] = Library(n, t, m);

        for (int j = 0; j < n; j++)
        {
            int num;
            std::cin >> num;
            libraries[i].addBook(num, values[num]);
        }
        libraries[i].calculateTotalTime();
        libraries[i].calculatePrefixSums();
    }
    int numberOfIterations = 1000;

    PheromoneAnt::generator.seed(20);
    srand(42);

    auto greedyAnt = std::shared_ptr<Ant>(new GreedyAnt(days, numOfLibraries));

    while (greedyAnt->nextLibrary(libraries, 0, 0.05) != -1)
        ;
    ACO testInstance(1, days, p, numOfLibraries, numberOfIterations);
    testInstance.iteration(libraries, 0);
    auto startClockGreedy = std::chrono::high_resolution_clock::now();
    testInstance.iteration(libraries, 1);
    auto endClockGreedy = std::chrono::high_resolution_clock::now();

    int numberOfAnts = std::min(std::max(2, 10 * 1000000 / (int)std::chrono::duration_cast<std::chrono::microseconds>(endClockGreedy - startClockGreedy).count()), 1000);

    ACO instance(numberOfAnts, days, 0.05, numOfLibraries, numberOfIterations);
    instance.set_best(libraries, greedyAnt);

    for (int i = 0;; i++)
    {
        auto startClockIter = std::chrono::high_resolution_clock::now();
        // std::cerr << "--------- iter: " << i << " ------------" << std::endl;

        if (i % 5 == 0 && i != 0)
        {
            instance.mutate(libraries, i);
        }
        else if (i % 10 == 0 && i != 0)
        {
            instance.mutate(libraries, i, true);
        }

        instance.iteration(libraries, i);

        auto endClock = std::chrono::high_resolution_clock::now();

        // std::cerr << instance.getBest() << std::endl;

        if (std::chrono::duration_cast<std::chrono::seconds>(endClock - startClockIter).count() +
                std::chrono::duration_cast<std::chrono::seconds>(endClock - startClock).count() >
            200)
            break;
    }

    auto path = instance.GetBestPath();
    int deadline = days;
    std::cout << path.size() << std::endl;
    std::set<int> scanned;
    int total{};
    for (auto &idx : path)
    {

        int signedIn = libraries[idx].getNumberOfBooksScanned(deadline);
        deadline -= libraries[idx].GetSignUpTime();
        int scannedFromThisLib{};
        std::vector<int> toCout;
        auto books = libraries[idx].GetAllBooks();
        for (auto &[number, value] : books)
        {
            if (!scanned.count(number))
            {

                toCout.push_back(number);
                total += value;
                scanned.insert(number);
                if (++scannedFromThisLib >= signedIn)
                    break;
            }
        }

        if (!toCout.empty())
        {
            std::cout << idx << ' ' << toCout.size() << std::endl;
            for (auto &number : toCout)
                std::cout << number << ' ';
        }
        else
        {
            std::cout << idx << ' ' << 1 << std::endl;
            std::cout << books[0].number;
        }

        std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    int alfa = atoi(argv[1]), beta = atoi(argv[2]), gamma = atoi(argv[3]), p = (double)atof(argv[4]);
    PheromoneAnt::m_alfa = alfa;
    PheromoneAnt::m_beta = beta;
    PheromoneAnt::m_gamma = gamma;
    solve(p);
}
