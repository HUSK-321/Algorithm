#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct Point{
    long long x;
    long long y;

    bool operator < (const Point &b) const{
        if(x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};

long long Distance(Point a, Point b){
    long long ans = (long long)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return ans;
}

bool CompareY(Point a, Point b){
    return a.y < b.y;
}

int Partition(vector<Point> &arr, int left, int right) {
   int pivotIndex = left;
   int storeIndex = pivotIndex;

    for (int i = left + 1; i <= right; i++) {
        if (arr[i] < arr[pivotIndex]) {
            storeIndex++;
            swap(arr[i], arr[storeIndex]);
        }
    }
   swap(arr[pivotIndex], arr[storeIndex]);
   pivotIndex = storeIndex;

   return pivotIndex;
}

void QuickSort(vector<Point> &arr, int left, int right) {
   if (left < right) {
      int pivot = Partition(arr, left, right);
      QuickSort(arr, left, pivot - 1);
      QuickSort(arr, pivot + 1, right);
   }
}



long long SearchAll(vector<Point> &v,int s, int e){
    long long minDist = -1;

    for(int i = s; i <= e - 1; i++){
        for(int j = i + 1; j <= e; j++){
            long long dist = Distance(v[i], v[j]);

            if(minDist == -1 || minDist > dist)
                minDist = dist;
        }
    }

    return minDist;
}


long long SearchPoint(vector<Point> &v, int start, int end){
    if(end - start + 1 <= 3)
        return SearchAll(v, start, end);
    
    long long mid = (start + end) / 2;
    long long left = SearchPoint(v, start, mid);
    long long right = SearchPoint(v, mid + 1, end);

    long long answer;
    if(left > right)
        answer = right;
    else
        answer = left;

    // 중앙 근처 값을 계산할 예정
    vector<Point> final;

    for(int i = start; i <= end; i++){
        long long xDistance = v[i].x - v[mid].x;

        if(xDistance * xDistance < answer)
            final.push_back(v[i]);
    }
    
    // y 기준 정렬
    int maxIndex = final.size();
    if(maxIndex == 0)
        return answer;
    QuickSort(final, 0, maxIndex - 1);

    for(int i = 0; i < maxIndex; i++){
        for(int j = i + 1; j < maxIndex; j++){
        
            long long y = final[j].y - final[i].y;

            if(y*y < answer){
                long long dist = Distance(final[j], final[i]);
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
    
    QuickSort(points, 0, n-1);

    long long answer = SearchPoint(points, 0, n-1);
    cout << fixed;
    cout.precision(6);
    cout << sqrt(answer);
}