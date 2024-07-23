#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// class SingleTest() {
//     private:
//         SingleTest() {

//         }
//         ~SingleTest() {

//         }
//         SingleTest(const SingleTest&);
//         SingleTest& operator=(const SingleTest&);
//     public:
//         static SingleTest &get_instance() {
//             static SingleTest single;
//             return single;
//         }
// };

struct Point {
    double x;
    double y;
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    Point() {

    }
};

double distance(const Point a, const Point b) {
    return  std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// ab = (b.x - a.x, b.y - a.y)
// apt = (pt.x - a.x, pt.y - a.y)
// 0,1 0,3  1,4
// 

Point Point_font_line(const Point &a, const Point &b, const Point &pt) {
    double ab = distance(a, b);
    double apt = distance(a, pt);
    double ratio = (b.x - a.x) * (pt.x - a.x) + (b.y - a.y) * (pt.y - a.y);
    double tmp = ratio / (ab * ab);
    if (tmp < 0) {
        return a;
    }
    if (tmp > 1) {
        return b;
    }
    Point p;
    p.x = a.x + tmp * (b.x - a.x);
    p.y = a.y + tmp * (b.y - a.y);
    return p;
}

int main() {
    Point pt(5.0, 1.0), a(1.0, 0.0), b(4.0, 0.0), ft;
    ft = Point_font_line(a, b, pt);
    std::cout << ft.x << " " << ft.y << std::endl;
    return 0;
}