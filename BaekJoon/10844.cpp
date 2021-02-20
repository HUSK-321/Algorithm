#include <iostream>
#define mod 1000000000
using namespace std;
int step[101][10];  // i계단의 다음으로 j 계단이 오게 된다
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 10; i++)
        step[1][i] = 1;
    
    // 0 다음에는 1, 9 다음에는 8만 올 수 있다
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0)
                step[i][j] = step[i-1][1];   // 0이 오는건 이전이 1이라는 소리
            else if(j == 9)
                step[i][j] = step[i-1][8];
            else
                step[i][j] = (step[i-1][j-1] + step[i-1][j+1]) % mod;
        }
    }

    int result = 0;
    for(int i = 1; i < 10; i++)
        result = (result + step[n][i]) % mod;
    cout << result << '\n';
}