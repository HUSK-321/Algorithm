#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


struct Point{
    long long x, y;
    long long p, q;
    Point()
        : x(0), y(0), p(1), q(0){}
};

bool CompareInFirst(const Point& a, const Point& b){
    if(a.y != b.y)
        return a.y < b.y;
    
    return a.x < b.x;
}

bool CompareInSecond(const Point& a, const Point& b){
    if(1LL * a.q * b.p != 1LL * a.p * b.q)
        return 1LL * a.q * b.p < 1LL * a.p * b.q;
    
    if(a.y != b.y)
        return a.y < b.y;
    
    return a.x < b.x;
}

long long CCW(const Point& a, const Point& b, const Point& c){
    return 1LL * (a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y);
}

int n;
Point points[100010];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points+n, CompareInFirst);

    for(int i = 1; i < n; i++){
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }

    sort(points + 1, points + n, CompareInSecond);

    stack<int> s;
    s.push(0);
    s.push(1);
    
    int next(2);

    while (next < n){
        while(s.size() >= 2){
            int second = s.top();
            s.pop();
            int first = s.top();

            if(CCW(points[first], points[second], points[next]) > 0){
                s.push(second);
                break;
            }
        }

        s.push(next++);
    }

    cout << s.size() << '\n';
    
}