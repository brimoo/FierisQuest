#ifndef Node_hpp
#define Node_hpp

struct Node{
    int ID;
    int i, j;

    bool traversed = false;
    bool expanding = false;

    int cost;

    Node(int ID, int i, int j, int cost)
        : i(i)
        , j(j)
	, cost(cost)
    { }

    void expand() {
        traversed = false;
        expanding = true;
    }

    void traverse() {
        traversed = true;
        expanding = false;
    }
};



#endif
