#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
    long long x, y;
};
int n, r;

vector<Point> points;

long long GetCCW(const Point& a, const Point& b, const Point& c){
    auto positive = a.x * b.y + b.x * c.y + c.x * a.y;
    auto negative = b.x * a.y + c.x * b.y + a.x * c.y;
    return positive - negative;
}

bool CompareByYPos(const Point& a, const Point& b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

bool CompareByCCW(const Point& a, const Point& b){
    auto ccw = GetCCW(points[0], a, b);
    return ccw ? ccw > 0 : CompareByYPos(a, b);
}

long long GetDistance(const Point& a, const Point& b){
    return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}


int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    points.resize(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    // sort
    vector<Point> hull;

    sort(points.begin(), points.end(), CompareByYPos);
    hull.push_back(points[0]);
    sort(points.begin() + 1, points.end(), CompareByCCW);
    hull.push_back(points[1]);

    // convex hull algorithm
    for(int i = 2; i < n; i++){
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

    // calculate area
    int totalCount = hull.size();
    long long answer = 0;
    for(int pivot = 0; pivot < totalCount - 1; pivot++){
        for(int curPoint = pivot + 1; curPoint < totalCount; curPoint++){
            answer = max(answer, GetDistance(hull[pivot], hull[curPoint]));
        }
    }
    cout << answer << '\n';
}