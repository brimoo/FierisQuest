#ifndef AlgorithmRunner_hpp
#define AlgorithmRunner_hpp

#include "PathingAlgorithm.hpp"
#include "Board.hpp"
#include <vector>
#include <string>

class AlgorithmRunner {
    Board* board;
    PathingAlgorithm* algorithm;

    void updateBoard();
    int indexToID(int i, int j);
    std::vector<int> getNeighbors(int i, int j);
public:
    AlgorithmRunner(Board* board);
    ~AlgorithmRunner();

    void setAlgorithm(std::string algorithm);
    bool isRunning();
    void next();
    bool algorithm_chosen();
    void reset();
};

#endif // AlgorithmRunner_hpp
