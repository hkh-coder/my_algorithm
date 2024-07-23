#include <vector>
#include <iostream>
#include <cmath>

const double PI = 3.1415926;
const double MIN_DIS = 0.00000001;
struct Point {
    double x;
    double y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};
// 叉乘
double calculate_chacheng(Point a, Point b, Point c) {
    double ab_x = a.x - b.x;
    double ab_y = a.y - b.y;
    double ac_x = a.x - c.x;
    double ac_y = a.y - c.y;
    return ((ab_x * ac_y) - (ab_y * ac_x));
}

double calculate_distance(const Point &a, const Point &b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    return std::sqrt(x * x + y * y);
}

double calculate_angle(const Point &a, const Point &b) {
    double dis = calculate_distance(a, b);
    double cos = (b.y - a.y) / dis;
    // 弧度 = 角度 * PI / 180
    double angle = acos(cos) * 180 / PI;
    if (fabs(a.x - b.x) < MIN_DIS  && b.y > a.y) {
        return 0;
    } else if (fabs(a.x - b.x) < MIN_DIS && a.y > b.y) {
        return 180;
    } else if (fabs(a.y - b.y) < MIN_DIS && a.x > b.x) {
        return 270;
    } else if (fabs(a.y - b.y) < MIN_DIS && a.x > b.x) {
        return 90;
    } else if (a.x > b.x) {
        angle = 360 - angle;
    }
    return angle;
}

bool is_point_in_line_left(Point a, Point b, Point c) {
    // 叉乘大于0，则点在左侧，否则在同一条延长线上(等于0)或右侧(小于0)
    return calculate_chacheng(a, b, c) > 0;
}

bool is_point_in_line_right(Point a, Point b, Point c) {
    return calculate_chacheng(a, b, c) < 0;
}

bool is_line_interect(Point a, Point b, Point c, Point d) {
    // 线段 ab 和 cd 相交
    double abc = calculate_chacheng(a, b, c);
    double abd = calculate_chacheng(a, b, d);
    double acd = calculate_chacheng(c, d, a);
    double adb = calculate_chacheng(c, d, b);
    if ((abc == 0 && abd == 0 ) || (acd == 0 && adb == 0)) {
        return true; // 共线
    }
    bool is_left = is_point_in_line_left(a, b, c);
    bool is_right_or_on = is_point_in_line_left(a, b, d);
    bool is_left_1 = is_point_in_line_left(c, d, a);
    bool is_right_or_on_1 = is_point_in_line_left(c, d, b);
    return ((!is_left == is_right_or_on) && (!is_left_1 == is_right_or_on_1));
}

bool calculate_line_interect(const Point &a, const Point &b, 
                             const Point &c, const Point &d, Point &interect) {
    if (!is_line_interect(a, b, c, d)) {
        return false;
    }

    // 使用克莱姆法则计算 Ax + By + C = 0
    //                 Dx + Ey + F = 0

    double A = a.y - b.y; // y1-y2
    double B = b.x - a.x; // x2-x1
    double C = a.y * (a.x - b.x) + a.x * (b.y - a.y);

    double D = c.y - d.y; // 1
    double E = d.x - c.x; // 1
    double F = c.y * (c.x - d.x) + c.x * (d.y - c.y);
    // 计算交点坐标
    double tmp = E * A - D * B;
    if (tmp == 0) {
        return false; // 平行或共线
    }
    double x = (F * B - E * C) / tmp;
    double y = (D * C - A * F) / tmp;
    interect.x = x;
    interect.y = y;
    return true;
}

Point calculate_foot_point(const Point &a, const Point &b, const Point &pt) {
    // 利用向量的点乘原理计算
    double ab = calculate_distance(a, b);
    double ap = calculate_distance(a, pt);
    double tmp = (b.x - a.x) * (pt.x - a.x) + (b.y - a.y) * (pt.y - a.y);
    double ratio = tmp / (ab * ab);
    std::cout << "ratio: " << ratio << std::endl;
    std::cout << "ab: " << ab << std::endl;
    std::cout << "ap: " << ap << std::endl;
    std::cout << "tmp: " << tmp << std::endl;
    if (ratio < 0 ) {
        return a;
    }
    if (ratio > 1) {
        return b;
    }
    
    Point foot_point;
    foot_point.x = a.x + ratio * (b.x - a.x);
    foot_point.y = a.y + ratio * (b.y - a.y);
    return foot_point;
}

bool calculate_sideline(const std::vector<Point> &points, 
                        std::vector<Point> &left_sideline, 
                        std::vector<Point> &right_sideline,
                        double width) {
    if (points.size() < 2 || width <= 0) {
        left_sideline.resize(0);
        right_sideline.resize(0);
        return false;
    }

    for (int i = 1; i < points.size(); ++i) {
        Point a = points[i - 1];
        Point b = points[i];
        double ab = calculate_distance(a, b);
        if (ab < 0.001){
            continue;
        }
        // 单位向量
        double x = (b.x - a.x) / ab;
        double y = (b.y - a.y) / ab;
        // 需要判断象限
        double l_x1(0.0), r_x1(0.0);
        double l_y1(0.0), r_y1(0.0);
        if (x >= 0 && y >= 0) {
            // 象限1 
            l_x1 = -x;
            l_y1 = y;
            r_x1 = x;
            r_y1 = -y;
        } else if (x < 0 && y >= 0) {
            // 象限2
            l_x1 = x;
            l_y1 = -y;
            r_x1 = -x;
            r_y1 = y;
        } else if (x < 0 && y < 0) {
            // 象限3
            l_x1 = -x;
            l_y1 = y;
            r_x1 = x;
            r_y1 = -y;
        } else if (x >= 0 && y < 0) {
            // 象限4
            l_x1 = x;
            l_y1 = -y;
            r_x1 = -x;
            r_y1 = y;
        }

        Point left_a((a.x + width + l_x1), (a.y + width + l_y1));
        Point right_a((a.x - width + r_x1), (a.y - width + r_y1));
        Point left_b((b.x + width + l_x1), (b.y + width + l_y1));
        Point right_b((b.x - width + r_x1), (b.y - width + r_y1));
        if (i == 1) {
            left_sideline.push_back(left_a);
            right_sideline.push_back(right_a);
        }
        left_sideline.push_back(left_b);
        right_sideline.push_back(right_b);
    }
    return true;
}

int main() {
    Point a(1.0, 0.0);
    Point b(2.0, 0.0);
    Point c(3.0, 0.0);
    // Point d(3.0, 3.0);
    // std::cout << " left: " << is_point_in_line_left(a, b, c) << std::endl;
    // std::cout << " right: " << is_point_in_line_right(a, b, c) << std::endl;
    // std::cout << " line_interect: " << is_line_interect(a, b, c, d) << std::endl;
    // Point interect;
    // if (calculate_line_interect(a, b, c, d, interect)) {
    //     std::cout << " interect: (" << interect.x << ", " << interect.y << ")" << std::endl;
    // }

    // Point pt = calculate_foot_point(a, b, c);
    // std::cout << " foot_point: (" << pt.x << ", " << pt.y << ")" << std::endl;
    std::vector<Point> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    std::vector<Point> left_sideline;
    std::vector<Point> right_sideline;
    calculate_sideline(points, left_sideline, right_sideline, 1.0);
    for (int i = 0; i < left_sideline.size(); ++i) {
        std::cout << " left_sideline: (" << left_sideline[i].x << ", " << left_sideline[i].y << ")" << std::endl;
    }
    for (int i = 0; i < right_sideline.size(); ++i) {
        std::cout << " right_sideline: (" << right_sideline[i].x << ", " << right_sideline[i].y << ")" << std::endl;
    }
    // double angle = 60.0;
    // std::cout << " cos: " << std::cos(angle * M_PI / 180) << std::endl;
    return 0;
}