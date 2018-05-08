#ifndef Board_hpp
#define Board_hpp

#include <vector>
#include "Square.hpp"

class SquareTypes;

class Board {
    std::vector< std::vector<Square*> > board;
    bool start_picked;
    bool goal_picked;
public:
    Board(int size);
    ~Board();
    void draw();
    void click(float x, float y);
    void drag(float x, float y);
    void reset();
    void setSquareType(int i, int j, SquareType* type);
    Square* getSquare(int i, int j);
    int size();
    bool goalsChosen();
};

#endif // Board_hpp
