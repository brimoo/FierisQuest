#include "Board.hpp"
#include "SquareTypes.hpp"
#include <stdexcept>
#include <iostream>
Board::Board(unsigned size)
    : size(size)
{
    if (size < 1)
        throw std::invalid_argument("Invalid board size");

    board = std::vector< std::vector<Square*> >(size, std::vector<Square*>(size));

    float gap_size = 0.01;
    float square_size = 2.0/size - gap_size;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            float x = i*square_size + i*gap_size - 1 + square_size/2;
            float y = j*square_size + j*gap_size - 1 + square_size/2;
            y = -y;

            board[i][j] = new Square(x, y, square_size);
        }
    }
}

Board::~Board()
{
    for (auto row : board)
        for (auto square : row)
            delete square;
}

void Board::draw()
{
    for (auto row :board)
        for (auto square : row)
            square->draw();
}

void Board::click(float x, float y)
{
    for (auto row : board)
        for (auto square : row)
            if (square->contains(x, y))
                square->click();
}

void Board::drag(float x, float y)
{
    for (auto row : board)
        for (auto square : row)
            if (square->contains(x, y))
                square->setType(new WallSquare);
}

void Board::reset()
{
    for (auto row : board)
        for (auto square : row)
            square->setType(new NormalSquare);
}
