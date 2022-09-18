#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    long long x;
    long long y;

    void operator = (const Point& a){
        x = a.x;
        y = a.y;
    }
};
vector<Point> points;
int numOfTestCase;

long long GetCCW(const Point& a, const Point& b, const Point& c){
    auto positive = a.x*b.y + b.x*c.y + c.x*a.y;
    auto negative = b.x*a.y + c.x*b.y + a.x*c.y;
    return positive - negative;
}

long long GetDistance(const Point& a, const Point& b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
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

int main(){
    // init 
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    cin >> numOfTestCase;

    while (numOfTestCase--){
        points.clear();
        int numOfCity;  
        
        cin >> numOfCity;
        points.resize(numOfCity);

        for(int i = 0; i < numOfCity; i++){
            cin >> points[i].x >> points[i].y;
        }

        // sort
        vector<Point> hull;
        stable_sort(points.begin(), points.end(), CompareByYPos);
        hull.push_back(points[0]);
        stable_sort(points.begin() + 1, points.end(), CompareByCCW);
        hull.push_back(points[1]);

        // make convex hull
        for(int i = 2; i < numOfCity; i++){
            while (hull.size() >= 2){
                auto first = hull.back();
                hull.pop_back();
                auto second = hull.back();

                auto ccw = GetCCW(second, first, points[i]);
                if(ccw > 0){
                    hull.push_back(first);
                    break;
                }
            }
            hull.push_back(points[i]);
        }

        // rotate calipers
        Point farPointFirst, farPointSecond;
        long long maxDistance = -1;
        int opposite = 1;
        int hullSize = hull.size();

        for(int pivot = 0; pivot < hullSize; pivot++){
            int pivotNext = (pivot + 1) % hullSize;
            while(true){
                int oppositeNext = (opposite + 1) % hullSize;

                Point nextPoint;
                nextPoint.x = hull[pivotNext].x + hull[oppositeNext].x - hull[opposite].x;
                nextPoint.y = hull[pivotNext].y + hull[oppositeNext].y - hull[opposite].y;
                auto ccw = GetCCW(hull[pivot], hull[pivotNext], nextPoint);

                if(ccw <= 0)
                    break;
                opposite = oppositeNext;
            }

            auto distance = GetDistance(hull[pivot], hull[opposite]);
            if(maxDistance < distance){
                maxDistance = distance;
                farPointFirst = hull[pivot];
                farPointSecond = hull[opposite];
            }
        }

        // output
        cout << farPointFirst.x << " " << farPointFirst.y << " " <<
                farPointSecond.x << " " << farPointSecond.y << '\n';
    }
}