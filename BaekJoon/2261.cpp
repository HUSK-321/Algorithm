#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
    int x;
    int y;

    bool operator < (const Point &b) const{
        if(x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};

int Distance(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool CompareY(Point a, Point b){
    return a.y < b.y;
}




int SearchAll(vector<Point> &v,int s, int e){
    int minDist = -1;

    for(int i = s; i <= e - 1; i++){
        for(int j = i + 1; j <= e; j++){
            int dist = Distance(v[i], v[j]);

            if(minDist == -1 || minDist > dist)
                minDist = dist;
        }
    }

    return minDist;
}



int SearchPoint(vector<Point> &v, int start, int end){
    int count = end - start + 1;

    if(count <= 3)
        return SearchAll(v, start, end);
    
    int mid = (start + end) / 2;
    int left = SearchPoint(v, start, mid);
    int right = SearchPoint(v, mid + 1, end);

    int answer;
    if(left > right)
        answer = right;
    else
        answer = left;

    // 중앙 근처 값을 계산할 예정
    vector<Point> final;

    for(int i = start; i <= end; i++){
        int xDistance = v[i].x - v[mid].x;

        if(xDistance * xDistance < answer)
            final.push_back(v[i]);
    }
    
    // y 기준 정렬
    int maxIndex = final.size();
    sort(final.begin(), final.end(), CompareY);

    for(int i = 0; i < maxIndex - 1; i++){
        for(int j = i + 1; j < maxIndex; j++){
        
            int y = final[j].y - final[i].y;

            if(y*y < answer){
                int dist = Distance(final[j], final[i]);
                if(dist < answer)
                    answer = dist;
            }
            else 
                break;
        }
    }
    return answer;
}


int main(){
    int n;
    char temp; // 쉼표 제거용
    cin >> n;
    vector<Point> points(n);

    for(int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    
    sort(points.begin(), points.end());


    int answer = SearchPoint(points, 0, n-1);

    cout << answer << '\n';
}