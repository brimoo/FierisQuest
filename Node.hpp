#ifndef Node_hpp
#define Node_hpp

struct Node{
    static total_nodes;
    int ID;
    int i, j;

    bool traversed = false;
    bool expanding = false;
    bool inQueue   = false;

    Node(int i, int j);  
};

Node::total_nodes = 0;

Node::Node(int i, int j)
{
    this->i = i;
    this->j = j;
        
    ID = total_nodes;

    total_nodes++;
}

#endif
