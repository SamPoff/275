#include "Point.h"

/** Point default constructor. */
Point::Point() {
    xCoors = 0;
    yCoors = 0;
}//end Point

/** Point constructor.
@param xVal - x value.
@param yVal - y value. */
Point::Point(int xVal, int yVal) {
    xCoors = xVal;
    yCoors = yVal;
}//end Point

/** Returns 'x' value.
@return xCoors - x value. */
int Point::getX() {
    return xCoors;
}//end getX

/** Returns 'y' value.
@return yCoors - y value. */
int Point::getY() {
    return yCoors;
}//end getY
