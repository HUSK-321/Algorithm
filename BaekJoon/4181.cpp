#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
    long long x, y;

    Point(long long x, long long y){
        this->x = x;
        this->y = y;
    }
};
int n, r;

vector<Point> points;

long long GetCCW(const Point& a, const Point& b, const Point& c){
    auto positive = a.x * b.y + b.x * c.y + c.x * a.y;
    auto negative = b.x * a.y + c.x * b.y + a.x * c.y;
    return positive - negative;
}

bool CompareByPos(const Point& a, const Point& b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool CompareByCCW(const Point& a, const Point& b){
    auto ccw = GetCCW(points[0], a, b);
    return ccw ? ccw > 0 : CompareByPos(a, b);
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; char sign;
        cin >> x >> y >> sign;
        if(sign == 'N') continue;

        points.push_back({x, y});
    }

    // sort
    vector<Point> hull;
    sort(points.begin(), points.end(), CompareByPos);
    hull.push_back(points[0]);
    sort(points.begin() + 1, points.end(), CompareByCCW);
    hull.push_back(points[1]);

    // convex hull algorithm
    for(int i = 2; i < points.size(); i++){
        while (hull.size() >= 2){
            Point first = hull.back();
            hull.pop_back();
            Point second = hull.back();

            double ccw = GetCCW(second, first, points[i]);
            if(ccw > 0){
                hull.push_back(first);
                break;
            }
        }
        hull.push_back(points[i]);
    }

    // output
    cout << hull.size() << '\n';
    for(int i = 0; i < hull.size(); i++){
        cout << hull[i].x << " " << hull[i].y << '\n';
    }
}