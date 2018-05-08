#ifndef DFS_hpp
#define DFS_hpp

class DFS : public PathingAlgorithm {

public:
    DFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
    
    void next();
};

DFS::DFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : PathingAlgorithm(adjList, vecList, s, g)
{ }

void DFS::next()
{

}

#endif // DFS_hpp
