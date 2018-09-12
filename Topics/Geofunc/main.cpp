#include <iostream>
#include <cmath>
using namespace std;
const float _eps = 1e-6;
bool RealEq(float a, float b){
    if (fabs(a-b) <= _eps) return true;
    return false;
}
bool RealGt(float a, float b){
    if (!RealEq(a, b) && a>b) return true;
    return false;
}
bool RealLt(float a, float b){
    if (!RealEq(a,b) && a<b) return true;
    return false;
}
class Point { // same as a vector
public:
    float x;
    float y;
    Point(float xx, float yy){
        this -> x = xx;
        this -> y = yy;
    }
    float norm(){
        return sqrt(x*x + y*y);
    }
    Point operator + (Point other){
        return Point(x + other.x, y + other.y);
    }
    Point operator - (Point other){
        return Point(x - other.x, y - other.y);
    }
    float dist(Point other){
        Point temp = other - *(this);
        return temp.norm();
    }
    bool equal(Point other){
        return RealEq(x, other.x) && RealEq(y, other.y);
    }
    float angle(){ // in rad
        if (RealEq(x, 0)){
            if (RealEq(y, 0)) return 0;
            if (RealGt(y, 0)) return M_PI/2;
            else return 3*M_PI/2;
        }
        if (RealEq(y, 0)){
            if (RealGt(x, 0)) return 0;
            else return M_PI;
        }
        float alp = atan(fabs(y)/x);
        if (RealLt(alp, 0)) alp = alp + M_PI;
        if (RealLt(y, 0)) alp = 2*M_PI - alp;
        return alp;
    }
    // vector operators
    float dot(Point other){ // dot product of 2 vectors
        return x*other.x + y*other.y;
    }
    float cross(Point other){ // magnitude of cross product
        return x*other.y - y*other.x;
    }
    float sina(Point other){
        return cross(other)/(norm() * other.norm());
    }
    float cosa(Point other){
        return dot(other)/(norm() * other.norm());
    }
    float angle2(){ // better choice
        if (RealEq(x, 0) && RealEq(y, 0)) return 0;
        Point i = Point(1,0);
        float c = acos(cosa(i)); // since dot is commutative
        if (RealLt(y, 0)) c = 2*M_PI - c;
        return c;
    }
    float angle(Point other){
        float c = acos(cosa(other));
        if (RealLt(cross(other), 0)) c = 2*M_PI - c;
        return c;
    }
    float angleWithOx(){ // even better
        if (RealEq(x, 0) && RealEq(y, 0)) return 0;
        Point i = Point(1,0);
        return i.angle(*this);
    }
};

class Line {
public:
    float A,B,C;
    Line(float a, float b, float c){
        A = a;
        B = b;
        C = c;
    }
    Line(Point a, Point b){
        A = a.y - b.y;
        B = b.x - a.x;
        C = -(A*a.x + B*a.y);
    }
    float dist2Point(Point a){
        return (A*a.x + B*a.y + C)/sqrt(A*A + B*B);
    }
};
int main()
{
    Point p1 = Point(1, 1);
    Point p2 = Point(1, -1);
    Point p3 = p1+p2;
    cout << p1.angle(p2) << endl;
    cout << p1.angle2() << endl;
    cout << p1.angleWithOx() << endl;
    return 0;
}
