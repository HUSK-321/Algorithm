#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long left, right, mid, allTime;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    left = 1;
    right = (long long) times[times.size() - 1] * n;
    
    while(left <= right){
        mid = (left + right) / 2;
        
        allTime = 0;
        
        for(int i = 0; i < times.size(); i++)
            allTime += mid / times[i];
        
        // 시간 부족
        if(allTime < n)
            left = mid + 1;
        else { // 시간 충분
            answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}