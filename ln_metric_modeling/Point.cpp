/**
* Author: Tyler Dorey
* Date: 2/15/2022
* This is a console app meant to provide dynamic ln discrete metric calculations.
* The intent of this is to eventually be able to calculate distance between multiple sets of points and display distance and a graphic in
* either 2d or 3d.
**/

#include <iostream>
#include <cmath>
#include <math.h>
#include "Point.h"

namespace lnMetricModeling {

    //OPERATORS
    bool Point::operator ==(const Point P) { 
        if (is2d(*this)) { //2d
            return (_x == P._x && _y == P._y) ? true : false;
        }
        else { //3d
            return (_x == P._x && _y == P._y && _z == P._z) ? true : false;
        }
    } 

    Point Point::operator-(Point P) { //subtract
        if (is2d(P)) { //2d
            return Point(_x - P._x, _y - P._y);
        }
        else { //3d
            return Point(_x - P._x, _y - P._y, _z - P._z);
        }
    }      
    //inline Point operator+(Point P) { return Point(_x + P._x, _y + P._y); }
    //inline Point operator*(Point P) { return Point(_x * P._x, _y * P._y); } //Not sure if necessary yet TODO: Redef for 3d & 2d
    //inline Point operator/(Point P) { return Point(_x / P._x, _y / P._y); }     

    //ADDITONAL METHODS

    bool Point::is2d(Point P) {
        return (isnan(P.z()));
    }

    /**
    * Calculates the distance between two points A and B using the nth metric
    **/
    double Point::distanceCalc(Point A, Point B, double n) {
        if (A == B) {
            return 0; //same point
        }
        else if(is2d(A) && B.is2d(B)) { //2d
            return pow(( pow(abs((A - B).x()),n) + pow(abs((A - B).y()), n)), (1.0 / n));  //compute nth metric
        }
        else { //3d
            return pow((pow(abs((A - B).x()), n) + pow(abs((A - B).y()), n) + pow(abs((A - B).z()), n)), (1.0 / n));  //compute nth metric
        }
    }

    std::ostream& operator<<(std::ostream& output, Point& P)
    {
        if (P.is2d(P)) { //2d
            output << "(" << P.x() << "," << P.y() << ")";
        }
        else { //3d
            output << "(" << P.x() << "," << P.y() << "," << P.z() << ")";
        }
        return output;
    }
   
    std::istream& operator>>(std::istream& input, Point& P)
    {
        double x, y, z;
        std::string ans = "";
        bool invalid = true;
        while (invalid) {
            std::cout << "Is the point 3d? (Y/N)";
            input >> ans;
            if ((ans.compare("y") == 0) || (ans.compare("Y") == 0) || (ans.compare("yes") == 0) || (ans.compare("Yes") == 0)) { //3d
                invalid = false;
                std::cout << "Enter the first(x) coordinate: ";
                input >> x;
                std::cout << "\nEnter the second(y) coordinate: ";
                input >> y;
                std::cout << "\nEnter the third(z) coordinate: ";
                input >> z;
                P.x(x);
                P.y(y);
                P.z(z);
            }
            else if ((ans.compare("n") == 0) || (ans.compare("N") == 0) || (ans.compare("no") == 0) || (ans.compare("No") == 0)) { //2d
                invalid = false;
                std::cout << "Enter the first(x) coordinate: ";
                input >> x;
                std::cout << "\nEnter the second(y) coordinate: ";
                input >> y;
                P.x(x);
                P.y(y);
            }
            else {
                std::cout << "Error: Invalid answer please retry.\n";
            }
        }
        return input;
    }

}


/*
using namespace lnMetricModeling;
//TESTING
int main()
{
    Point a1(0, 0);
    Point a2(212, 210);
    Point c1(2, 1, 2);
    Point c2(2, 2, 1);
    std::cout << "Using the Taxicab metric(n=1): " << Point::distanceCalc(a1, a2, 1) <<  std::endl;
    std::cout << "Using the Euclidean metric(n=2): " << Point::distanceCalc(a1, a2, 2) << std::endl;
    std::cout << "Using the l3 metric(n=3): " << Point::distanceCalc(a1, a2, 3) << std::endl;
    std::cout << "Using the l50 metric(n=50): " << Point::distanceCalc(a1, a2, 50)  << std::endl;
    std::cout << "Using the l100 metric (n=100)" << Point::distanceCalc(a1, a2, 100) << std::endl;
    std::cout << "Testing the 3d calculation: " << Point::distanceCalc(c1, c2, 2);
}
*/
