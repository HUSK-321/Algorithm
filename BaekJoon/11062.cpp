#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 근우 먼저, 명우 다음. 근우의 답을 적어라
// 가장 왼쪽과 오른쪽만을 가져갈 수 있다.
int t, n, i;
int arr[1001], dp[1001][1001];

int DP(int l, int r, int turn){
    if(l > r)
        return 0;

    if(dp[l][r])
        return dp[l][r];

    if(turn % 2)
        return dp[l][r] = max(arr[l] + DP(l + 1, r, turn + 1), arr[r] + DP(l, r - 1, turn + 1));
    else
        return dp[l][r] = min(DP(l + 1, r, turn + 1), DP(l, r - 1, turn + 1));
}

int main(){
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        memset(dp, 0, sizeof(dp));
        DP(0, n-1, 1);
        printf("%d\n", dp[0][n-1]);
    }
    
}