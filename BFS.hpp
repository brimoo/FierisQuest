#ifndef BFS_hpp
#define BFS_hpp

class BFS : public PathingAlgorithm {

public:
    BFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
    
    void next();
};

BFS::BFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : PathingAlgorithm(adjList, vecList, s, g)
{ }

void BFS::next()
{

}

#endif // BFS_hpp
