#ifndef DFS_hpp
#define DFS_hpp

class DFS : public PathingAlgorithm {

public:
    DFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
    std::vector<int> extractPath();
    void next();
};

DFS::DFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : PathingAlgorithm(adjList, vecList, s, g)
{ }

void DFS::next()
{

}

std::vector<int> DFS::extractPath()
{
    std::vector<int> path;
    return path;
}

#endif // DFS_hpp
