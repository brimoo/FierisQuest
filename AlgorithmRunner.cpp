#include "AlgorithmRunner.hpp"
#include "Node.hpp"
#include "AStar.hpp"
#include "Dijkstra.hpp"
#include "DFS.hpp"
#include "BFS.hpp"
#include <stdexcept>
#include <iostream>
#include <climits>
#include <algorithm>

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

        // Set the node's corresponding square to the correct type
        // Based on node state
        if (!isRunning() && node.inPath)
            type = new PathSquare;
        else if (node.expanding)
            type = new ExpandingSquare;
        else if (node.traversed)
            type = new TraversedSquare;
	    else if (node.cost == INT_MAX)
	        type = new WallSquare;
	    else
	        type = new NormalSquare;

        // Prevent overwrighting Start and End square, then set the square type
        if (!dynamic_cast<StartSquare*>(board->getSquare(node.i, node.j)->getType()) &&
            !dynamic_cast<EndSquare*>(board->getSquare(node.i, node.j)->getType()) )
            board->setSquareType(node.i, node.j, type);
    }
}

int AlgorithmRunner::indexToID(int i, int j)
{
    return i + j*board->size();
}

std::vector<int> AlgorithmRunner::getNeighbors(int i, int j)
{
    std::vector<int> neighbors;

    // Apologies for this nightmare edge case checking

    // Left Side
    if (i != 0) {
        // Top left
        if (j != 0)
            neighbors.push_back( indexToID(j-1, i-1) );

        // Bottom left
        if (j != board->size()-1)
            neighbors.push_back( indexToID(j+1, i-1) );

        // Left
        neighbors.push_back( indexToID(j, i-1) );
    }

    // Above
    if (j != 0)
        neighbors.push_back( indexToID(j-1, i) );

    // Below
    if (j != board->size()-1)
        neighbors.push_back( indexToID(j+1, i) );

    // Right Side
    if (i != board->size()-1 ) {
        // Top right
        if (j != 0)
            neighbors.push_back( indexToID(j-1, i+1) );

        // Bottom right
        if (j != board->size()-1)
            neighbors.push_back( indexToID(j+1, i+1) );

        // Right
        neighbors.push_back( indexToID(j, i+1) );
    }

    return neighbors;
}

void AlgorithmRunner::setAlgorithm(std::string algorithm)
{
    std::vector<Node> nodes;
    std::vector< std::vector<int> > adjList;
    int start_ID = -1;
    int goal_ID = -1;

    // Generate list of nodes from board data, and fill adjacency list
    for (int i = 0; i < board->size(); i++) {
        for (int j = 0; j < board->size(); j++) {
	    Square* square = board->getSquare(i, j);
            
            if (dynamic_cast<StartSquare*>(square->getType()))
                start_ID = indexToID(i, j);
            
            else if (dynamic_cast<EndSquare*>(square->getType()))
                goal_ID = indexToID(i, j);
            
	    if (dynamic_cast<WallSquare*>(square->getType()))
	        nodes.push_back( Node(indexToID(i, j), i, j, INT_MAX) );
	    else
		nodes.push_back( Node(indexToID(i, j), i, j, 1) );
	    
            adjList.push_back(getNeighbors(i, j));
        }
    }

    // Fix for mirrored node values
    std::sort(nodes.begin(), nodes.end(), [](Node lhs, Node rhs){ 
            if (lhs.j == rhs.j)
                return lhs.i < rhs.i;
            else
                return lhs.j < rhs.j;
    } );

    // Call algorithm selected by App
    if (algorithm == std::string("A*"))
        this->algorithm = new AStar(adjList, nodes, start_ID, goal_ID);
    
    else if (algorithm == std::string("Dijkstra"))
        this->algorithm = new Dijkstra(adjList, nodes, start_ID, goal_ID);

    else if (algorithm ==  std::string("DFS"))
        this->algorithm = new DFS(adjList, nodes, start_ID, goal_ID);

    else if (algorithm ==  std::string("BFS"))
        this->algorithm = new BFS(adjList, nodes, start_ID, goal_ID);

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
    // Next iteration of algorithm
    if (algorithm && board->goalsChosen()) {
        if (isRunning()) {
            algorithm->next();
            updateBoard();
        }
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
