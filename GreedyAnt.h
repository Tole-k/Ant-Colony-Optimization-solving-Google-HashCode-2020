#ifndef CPP_GREEDYANT_H
#define CPP_GREEDYANT_H
#include "ant.h"

class GreedyAnt : public Ant
{
public:
    int nextLibrary(std::vector<Library> &libraries, int iter, int p) override;
    GreedyAnt(int deadline, int numberOfLibraries);
};

#endif // CPP_GREEDYANT_H
