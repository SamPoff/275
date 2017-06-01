#include "Square.h"

/** Default Square Constructor */
Square::Square() {

    x      = 0;
    y      = 0;
    width  = 0;
    height = 0;

}//end default constructor

/** Square Constructor with Parameters. */
Square::Square(int xa, int ya, int widtha, int heighta) {

    x      = xa;
    y      = ya;
    width  = widtha;
    height = heighta;

}//end overloaded constructor

/** Overloaded output operator to print squares.
@param out - output stream.
@param mySquare - the square to be printed. */
std::ostream & operator<< (std::ostream & out, const Square & mySquare) {

    out << mySquare.x      << ", "
        << mySquare.y      << ", "
        << mySquare.width  << ", "
        << mySquare.height << std::endl;

    return out;

}//end overload <<



