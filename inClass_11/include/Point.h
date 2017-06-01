#ifndef POINT_H
#define POINT_H


class Point {

    private:

        int xCoors;
        int yCoors;

    public:

        /** Point default constructor. */
        Point();
        /** Point constructor.
        @param xVal - x value.
        @param yVal - y value. */
        Point(int xCoors, int yCoors);

        /** Returns 'x' value.
        @return xCoors - x value. */
        getX();
        /** Returns 'y' value.
        @return yCoors - y value. */
        getY();

};

#endif // POINT_H
