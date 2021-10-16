#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>

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

double Distance(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool CompareY(Point a, Point b){
    return a.y < b.y;
}


void QuickSortX(vector<Point> &v, int s, int e){
    if(s >= e)
        return;
    
    int right = e;
    int left = s;
    int mid = s + e / 2;
    Point pivot = v[mid];

    while (left < right){
        while (v[left] < pivot)
            left++;
        while (pivot < v[right])
            right--;
        
        if(left <= right){
            if(left < right){
                //Swap
                Point temp;
                temp = v[left];
                v[left] = v[right];
                v[right] = temp;
            }
            left++;
            right--;
        }
    }
    QuickSortX(v, s, right);
    QuickSortX(v, left, e);
}

// void QuickSortY(vector<Point> &v, int s, int e){
//     if(s >= e)
//         return;
    
//     int right = e;
//     int left = s;
//     int mid = s + e / 2;
//     Point pivot = v[mid];

//     while (left < right){
//         while (v[left].y < pivot.y)
//             left++;
//         while (pivot.y < v[right].y)
//             right--;
        
//         if(left <= right){
//             if(left < right){
//                 //Swap
//                 Point temp;
//                 temp = v[left];
//                 v[left] = v[right];
//                 v[right] = temp;
//             }
//             left++;
//             right--;
//         }
//     }
//     QuickSortY(v, s, right);
//     QuickSortY(v, left, e);
// }




double SearchAll(vector<Point> &v,int s, int e){
    double minDist = -1;

    for(int i = s; i <= e - 1; i++){
        for(int j = i + 1; j <= e; j++){
            double dist = Distance(v[i], v[j]);

            if(minDist == -1 || minDist > dist)
                minDist = dist;
        }
    }

    return minDist;
}


double SearchPoint(vector<Point> &v, int start, int end){
    if(end - start + 1 <= 3)
        return SearchAll(v, start, end);
    
    int mid = (start + end) / 2;
    double left = SearchPoint(v, start, mid);
    double right = SearchPoint(v, mid + 1, end);

    double answer;
    if(left > right)
        answer = right;
    else
        answer = left;

    // 중앙 근처 값을 계산할 예정
    vector<Point> final;

    for(int i = start; i <= end; i++){
        double xDistance = v[i].x - v[mid].x;

        if(xDistance * xDistance < answer)
            final.push_back(v[i]);
    }
    
    // y 기준 정렬
    int maxIndex = final.size();
    QuickSortX(final, 0, maxIndex - 1);

    for(int i = 0; i < maxIndex - 1; i++){
        for(int j = i + 1; j < maxIndex; j++){
        
            double y = final[j].y - final[i].y;

            if(y*y < answer){
                double dist = Distance(final[j], final[i]);
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
        cin >> points[i].x >> temp >> points[i].y;
    
    QuickSortX(points, 0, n-1);

    double answer = SearchPoint(points, 0, n-1);

    printf("%0.6lf\n", sqrt(answer));
}

7
971239, 121876
463918, 254404
547547, 744402
859997, 729153
115418, 603248
261717, 147646
408682, 217164