/*
you get the point main lab cpp
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

class Point 
{
public:
Point(double setx, double sety): x_coord(setx), y_coord(sety){};

double getx(){
    return x_coord;
}
double gety(){
    return y_coord;
}

double operator-(const Point &pointA){
return sqrt((pow(this->x_coord - pointA.x_coord, 2) + pow(this->y_coord - pointA.y_coord, 2)));
}

bool operator==(const Point &pointA){
if(this->x_coord == pointA.x_coord && this->y_coord == pointA.y_coord){
    return true;
}
else return false;
}

bool operator!=(const Point &pointA){
if(this->x_coord != pointA.x_coord && this->y_coord != pointA.y_coord){
    return true;
}
else return false;
}

Point operator/(const Point &pointA){
return Point ((this->x_coord + pointA.x_coord)/2, (this->y_coord + pointA.y_coord)/2);
}


private:

double x_coord = 0;
double y_coord = 0;

};

int main() {
    /////////////// --- Test area --- /////////////

    Point p1(1, 1);
    Point p2(2, 2); 

    double c1 = p1 - p2;
    bool c2 = p1 == p2;
    bool c3 = p1 != p2;
    Point c4 = p1/p2;

    cout << "\nOverload test for - operator Output should be " << sqrt(2) << ", output: " << c1;
    cout << "\nOverload test for == operator Output should be " << false << ", output: " << c2;
    cout << "\nOverload test for != operator Output should be " << true << ", output: " << c3;
    cout << "\nOverload test for / operator Output should be " << "(1.5, 1.5), output: (" << c4.getx() << ", " << c4.gety() << ")";
    cout << "\n     If values match, all tests pass.";

    ///////////////////////////////////////////////

    return 0;
}