#ifndef PathingAlgorithm_hpp
#define PathingAlgorithm_hpp

#include <vector>
#include "Node.hpp"

class PathingAlgorithm {
protected:
    std::vector< std::vector<int> > adjList;
    std::vector<Node> nodeList;
    int startID;
    int endID;
    bool running;
    bool pathFound;
public:
    PathingAlgorithm(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g)
        : adjList(adjList)
        , nodeList(nodeList)
        , startID(s)
        , endID(g)
        , running(true)
    { }
    virtual ~PathingAlgorithm(){}
    virtual void next() = 0;
    virtual bool isRunning() { return running; }
    virtual void extractPath() = 0;
    std::vector<Node> getList() { return nodeList; }
};

#endif // PathingAlgorithm_hpp
