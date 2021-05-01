#include <string>
#include <vector>
#include <cstring>
#define mod 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // m : 가로, n : 세로, puddles : 물이 담긴 곳
    long long arr[m+1][n+1];
    memset(arr, 0, sizeof(arr));
    // 초기화는 (0,0), (0,1), (1,0) 은 1로 초기화
    arr[1][1] = arr[1][2] = arr[2][1] = 1;
    
    for (int i = 0; i < puddles.size(); i++)
		arr[puddles[i][0]][puddles[i][1]] = -1;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == -1)
                arr[i][j] = 0;
            else if (arr[i][j] == 0)
                arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % mod;
        }
    }
    answer = arr[m][n] % mod;
    return answer;
}