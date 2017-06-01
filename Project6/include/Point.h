#ifndef POINT_H
#define POINT_H

class Point {

    private:

        int x;
        int y;

    public:

        /** Default Point constructor */
        Point();
        /** Parameter Point constructor
        @param Xa - X value passed in by program.
        @param Ya - Y value passed in by program. */
        Point(int Xa, int Ya);
        /** Returns a Point's X value.
        @return x - the point's x value. */
        getX() {return x;}
        /** Returns a Point's Y value.
        @return y - the point's y value. */
        getY() {return y;}

};

#endif // POINT_H
