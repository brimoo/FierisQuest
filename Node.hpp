#ifndef Node_hpp
#define Node_hpp

struct Node{
    int ID;
    int i, j;

    bool traversed = false;
    bool expanding = false;

    Node(int ID, int i, int j)
        : ID(ID)
        , i(i)
        , j(j)
    { }
};

#endif
