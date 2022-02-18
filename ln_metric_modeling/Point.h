#ifndef POINT_H
#define POINT_H

namespace lnMetricModeling {

    struct Point {

        //CONSTRUCTORS
        Point() : _x(0), _y(0), _z(NAN) { } //DEFAULT IS 2d
        Point(double x, double y) : _x(x), _y(y), _z(NAN) { } //Define 2d point
        Point(double x, double y, double z) : _x(x), _y(y), _z(z) { } //Define 3d point

        //MUTATORS 
        void x(const double x) { _x = x; } //set x
        void y(const double y) { _y = y; } //set y
        void z(const double z) { _z = z; }//set z
        const double x() { return _x; } //get x
        const double y() { return _y; } //get y
        const double z() { return _z; } //get y

        //OPERATORS
        bool operator ==(const Point P); //equals
        inline bool operator !=(const Point P) { return (!(*this == P)) ? true : false; } //not equals
        Point operator-(Point P); //subtraction

        //ADDITIONAL METHODS
        //Returns true if point is 3d, false otherwise 
        static bool is3d(Point P);
        //calculates the distance between two points 2d or 3d
        //DO NOT MIX 2d and 3d
        //returns a value representing their distance
        static double distanceCalc(Point A, Point B, double n); 

    private:
        double _x;
        double _y;
        double _z;
    };
}

#endif
