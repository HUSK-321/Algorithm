#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

struct Point{
    long long x, y;
    bool operator < (const Point& b){
        return (y == b.y) ? (x < b.x) : (y < b.y);
    }
};

vector<Point> points;
stack<Point> hull;
int n, l;
const double PI = 3.1415926535;
long long CCW(const Point& a, const Point& b, const Point& c){
    return a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
}

long long Distance(const Point& a, const Point& b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool CompareByCCW(const Point& a, const Point& b){
    long long ccw = CCW(points[0], a, b);

    if(ccw == 0){
        return Distance(points[0], a) < Distance(points[0], b);
    }
    return ccw > 0;
}


int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> l;
    points.resize(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), CompareByCCW);

    hull.push(points[0]);
    hull.push(points[1]);

    for(int i = 2; i < n; i++){
        while(hull.size() >= 2){
            Point first = hull.top();
            hull.pop();
            Point second = hull.top();

            long long ccw = CCW(points[i], first, second);
            if(ccw < 0){
                hull.push(first);
                break;
            }
        }
        hull.push(points[i]);
    }

    double answer = 0;
    int hullSize = hull.size();
    Point lastPoint(hull.top());
    for(int i = 1; i < hullSize; i++){
        Point point = hull.top();
        hull.pop();
        answer += Distance(point, hull.top());
    }
    answer += Distance(lastPoint, hull.top());
    answer += PI * 2 * l;

    cout.precision(12);
    cout << answer << '\n';
}