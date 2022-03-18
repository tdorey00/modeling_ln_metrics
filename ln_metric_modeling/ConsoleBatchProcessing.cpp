#include <iostream>
#include "Point.h"
#include <cmath>
#include <math.h>
#include <iomanip>

namespace lnMetricModeling {
	//Computes all nth metrics starting with n = 1 up to and including the given endPoint on given points A and B and prints to the console window
	void consoleBatchCompute(Point A, Point B, int endPoint) {
		if ((Point::is2d(A) && Point::is2d(B)) || !(Point::is2d(A) && Point::is2d(B))) { //both 2d or both 3d
			for (int n = 1; n <= endPoint; n++) { //print all distance calculations up to and including endpoint
				std::cout << "The n = " << n << " metric on points, " << A << " and " << B << " is: " << Point::distanceCalc(A, B, n) << std::endl;
			}
		}
		else {
			std::cout << "Error: Given points have mismatched dimensions.";
		}
		
	}

	/*
	* returns the value of the largest distance between corresponding coordinates given two points
	* Ex: if given(1, 200, 60) and (2, 10, 40) function will return 190 as it is the largest difference
	*/
	double mostSignificantDistance(Point A, Point B) {
		double max = abs(A.x() - B.x());
		if(abs(A.y() - B.y()) > max) {
			max = abs(A.y() - B.y());
		}
		else if (abs(A.z() - B.z()) > max) {
			max = abs(A.z() - B.z());
		}
		return max;
	}


}



//TESTING
using namespace lnMetricModeling;
int main() {
	std::cout << std::setprecision(15);
	Point A(29, 300);
	Point B(3, 2);
	consoleBatchCompute(A, B, 25);
	std::cout << mostSignificantDistance(A, B);
}