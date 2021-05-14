#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int ans = 9;

void DP(int n, int num, int count, int cur){
    if(count > 8)
        return;
    
    if(cur == num){
        ans = min(ans, count);
        return;
    }
    // 더하기, 붙이기, 나누기
    int temp = 0;
    for(int i = 0; i + count < 9; i++){
        temp = temp * 10 + n;   // n, nn, nnn ...
        DP(n, num, count + 1 + i, cur + temp);
        DP(n, num, count + 1 + i, cur * temp);
        DP(n, num, count + 1 + i, cur / temp);
        DP(n, num, count + 1 + i, cur - temp);
    }
}

int solution(int N, int number) {
    DP(N, number, 0, 0);
    
    if(ans > 8) 
        ans = -1;
    
    return ans;
}