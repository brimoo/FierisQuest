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
    void click(float x, float y);
    void drag(float x, float y);
    void reset();
};

#endif // Board_hpp
