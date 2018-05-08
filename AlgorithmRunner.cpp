#include "AlgorithmRunner.hpp"
#include "Node.hpp"
#include "AStar.hpp"
#include "Dijkstra.hpp"
#include "DFS.hpp"
#include "BFS.hpp"
#include <stdexcept>

AlgorithmRunner::AlgorithmRunner(Board* board)
    : board(board)
    , algorithm(nullptr)
{ }

AlgorithmRunner::~AlgorithmRunner()
{
    delete algorithm;
    delete board;
}

void AlgorithmRunner::updateBoard()
{
    std::vector<Node> vertices = algorithm->getList();

    for (auto node : vertices) {
        SquareType* type;
        
        if (node.traversed)
            type = new TraversedSquare;
        else if (node.expanding)
            type = new ExpandingSquare;
        else
            type = new NormalSquare;

        board->setSquareType(node.i, node.j, type);
    }
}

int AlgorithmRunner::indexToID(int i, int j)
{
    return i*board->size() + j;
}

std::vector<int> AlgorithmRunner::getNeighbors(int i, int j)
{
    std::vector<int> neighbors;

    // Apologies for this nightmare edge case checking

    // Left Side
    if (i != 0) {
        // Top left
        if (j != 0)
            neighbors.push_back( indexToID(i-1, j-1) );

        // Bottom left
        if (j != board->size() )
            neighbors.push_back( indexToID(i-1, j+1) );

        // Left
        neighbors.push_back( indexToID(i-1, j) );
    }

    // Above
    if (j != 0)
        neighbors.push_back( indexToID(i, j-1) );

    // Below
    if (j != board->size() )
        neighbors.push_back( indexToID(i, j+1) );

    // Right Side
    if (i != board->size() ) {
        // Top right
        if (j != 0)
            neighbors.push_back( indexToID(i+1, j-1) );

        // Bottom right
        if (j != board->size() )
            neighbors.push_back( indexToID(i+1, j+1) );

        // Right
        neighbors.push_back( indexToID(i+1, j) );
    }

    return neighbors;
}

void AlgorithmRunner::setAlgorithm(std::string algorithm)
{
    std::vector<Node> nodes;
    std::vector< std::vector<int> > adjList;
    int start_ID = -1;
    int goal_ID = -1;
    
    for (int i = 0; i < board->size(); i++) {
        for (int j = 0; j < board->size(); j++) {
            
            Square* square = board->getSquare(i, j);
            if (dynamic_cast<WallSquare*>(square->getType()))
                continue;
            
            else if (dynamic_cast<StartSquare*>(square->getType()))
                start_ID = indexToID(i, j);
            
            else if (dynamic_cast<EndSquare*>(square->getType()))
                goal_ID = indexToID(i, j);
            
            nodes.push_back( Node(indexToID(i, j), i, j) );
            adjList.push_back(getNeighbors(i, j));
        }
    }
    
    if (algorithm == std::string("A*"))
        this->algorithm = new AStar(adjList, nodes, start_ID, goal_ID);
    
    else if (algorithm == std::string("Dijkstra"))
        this->algorithm = new Dijkstra(adjList, nodes, start_ID, goal_ID);

    else if (algorithm ==  std::string("DFS"))
        this->algorithm = new DFS(adjList, nodes, start_ID, goal_ID);

    else if (algorithm ==  std::string("BFS"))
        this->algorithm = new DFS(adjList, nodes, start_ID, goal_ID);

    else
        throw std::invalid_argument("Undefined Algorithm");    
}

bool AlgorithmRunner::isRunning()
{
    if (algorithm)
        return algorithm->isRunning();
    return false;
}

void AlgorithmRunner::next()
{
    if (algorithm) {
        algorithm->next();
        updateBoard();
    }
}

bool AlgorithmRunner::algorithm_chosen()
{
    return algorithm;
}

void AlgorithmRunner::reset()
{
    algorithm = nullptr;
}
