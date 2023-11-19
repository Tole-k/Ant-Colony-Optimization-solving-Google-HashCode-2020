#ifndef CPP_GREEDYANT_H
#define CPP_GREEDYANT_H
#include "Ant.h"

class GreedyAnt : public Ant
{
public:
    int nextLibrary(std::vector<Library> &libraries, int iter, double p) override;
    GreedyAnt(int deadline, int numberOfLibraries);
};

#endif // CPP_GREEDYANT_H
