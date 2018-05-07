#ifndef Board_hpp
#define Board_hpp

#include <vector>
#include "Square.hpp"

class Board {
    std::vector< std::vector<Square*> > board;
    unsigned size;
public:
    Board(unsigned);
    ~Board();
    void draw();
};

#endif // Board_hpp
