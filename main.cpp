#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <random>
#include <unordered_set>
#include "ant.h"
#include "AntColonyOptimization.h"
#include "library.h"
#include "book.h"
#include <chrono>

void solve()
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
    int numberOfAnts;
    if (numOfLibraries > 10000)
        numberOfAnts = 120000 / numOfLibraries;
    else if (numOfLibraries == 10000)
        // std::cout << "GetBooks: [ numberOfBooksToReturn: " << numberOfBooksToReturn << " ]" << std::endl;
        numberOfAnts = 50;
    else
        numberOfAnts = 200;
    // numberOfAnts = 1000;

    // Just random number for now
    int numberOfIterations = 1000;

    Ant::generator.seed(20);
    srand(42);
    ACO instance(numberOfAnts, days, 0.05, numOfLibraries, numberOfIterations);

    for (int i = 0;; i++)
    {
        std::cerr << "--------- iter: " << i << " ------------" << std::endl;
		// if (i % 100 == 0 && i != 0) {
		// 	Ant::m_alfa -= 1;
		// 	Ant::m_beta += 1;
		// 	Ant::m_gamma += 1;
		// }
		if (i % 10 == 0 && i != 0) {
			instance.mutate(libraries, i);
		}
        // if (i % 10 == 0 && i != 0)
        //     instance.normalize();

        instance.iteration(libraries, i);

        auto endClock = std::chrono::high_resolution_clock::now();
        // nice for debugging
        std::cerr << instance.getBest() << std::endl;

        if (std::chrono::duration_cast<std::chrono::seconds>(endClock - startClock).count() > 240)
            break;
    }
	std::cerr << "after" << std::endl;
//    auto bestAnt = instance.getBestAnt();
//    int bestPath = instance.getBest();
//    int best = bestAnt.mutate(libraries, days);
//    // std::cout << bestPath << ' ' << best << std::endl;

    auto path = instance.GetBestPath();
	int deadline = days;
    std::cout << path.size() << std::endl;
	std::set<int> scanned;
	int total{};
    for (auto &idx : path)
    {
        // auto books = libraries[idx].GetAllBooks();
		int signedIn = libraries[idx].getNumberOfBooksScanned(deadline);
		deadline -= libraries[idx].GetSignUpTime();
		int scannedFromThisLib{};
		std::vector<int> toCout;
		auto books = libraries[idx].GetAllBooks();
        for (auto &[number, value] : books) {
			if (!scanned.count(number)) {
				//std::cout << value << ' ';
                toCout.push_back(number);
				total += value;
				scanned.insert(number);
				if (++scannedFromThisLib >= signedIn)
					break;
			}
		}

		if (!toCout.empty()) {
			std::cout << idx << ' ' << toCout.size() << std::endl;
			for (auto &number : toCout)
				std::cout << number << ' ';
		}
		else {
			std::cout << idx << ' ' << 1 << std::endl;
			std::cout << books[0].number;
		}

        std::cout << std::endl;
    }
	std::cerr << "final score: " << total << std::endl;

}

int main()
{
    solve();
}
