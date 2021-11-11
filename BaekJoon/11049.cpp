#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, r, c, res = 0;
pair<int, int> matrix[501];
int dp[501][501];   // left ~ right : 최소 연산 횟수

int MultiplyMatrix(int left, int right){
    if(left == right)
        return 0;
    
    int minimum = 999999999;

    if(dp[left][right] != -1)
        return dp[left][right];

    for(int i = left; i < right; i++){
        minimum = min(minimum, MultiplyMatrix(left, i) + MultiplyMatrix(i+1, right)
                    + (matrix[left].first * matrix[i].second * matrix[right].second));
    }
    dp[left][right] = minimum;
    return minimum;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> matrix[i].first >> matrix[i].second;
    }

    // init
    memset(dp, -1, sizeof(dp));

    // solve
    cout << MultiplyMatrix(0, n-1) << '\n';
}