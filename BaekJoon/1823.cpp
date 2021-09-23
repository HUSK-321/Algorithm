#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
int rice[2001];
int dp[2001][2001];


int DP(int left, int right, int count){
    if(left > right)
        return 0;
    
    if(dp[left][right])
        return dp[left][right];

    return dp[left][right] = max(DP(left+1, right, count+1) + rice[left] * count, DP(left, right-1, count+1) + rice[right] * count);
}

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
        scanf("%d", &rice[i]);
    
    cout << DP(1, n, 1) << '\n';

}   