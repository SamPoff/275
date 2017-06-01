#ifndef SQUARE_H
#define SQUARE_H
#include <ostream>

class Square {

    private:

        int x;
        int y;
        int width;
        int height;

    public:

        /** Default Square Constructor */
        Square();
        /** Square Constructor with Parameters. */
        Square(int x, int y, int width, int height);
        /** Overloaded output operator to print squares.
        @param out - output stream.
        @param mySquare - the square to be printed. */
        friend std::ostream & operator<< (std::ostream & out, const Square & mySquare);

};

#endif // SQUARE_H
