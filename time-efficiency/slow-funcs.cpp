#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

struct Point {
    double x, y;
};

vector<Point> generate_points(int n) {
    vector<Point> v;
    for (int i = 0; i < n; i++) {
        double x = rand();
        double y = rand();
        v.push_back({x, y});
    }
    return v;
}

double dist(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double dist2(Point A, Point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

void slow_point_check() {
    double threshold;
    cin >> threshold;
    int cnt = 0;
    vector<Point> points = generate_points(30000);
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (dist(points[i], points[j]) < threshold) cnt++;
        }
    }
    cout << cnt;
}

void fast_point_check() {
    double threshold;
    cin >> threshold;
    int cnt = 0;
    vector<Point> points = generate_points(30000);
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (dist2(points[i], points[j]) < threshold * threshold) cnt++;
        }
    }
    cout << cnt;
}

int main() {
    // fast_point_check();
    // slow_point_check();
}
