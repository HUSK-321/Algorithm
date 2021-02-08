#include <iostream>
using namespace std;
long long arr[201][201];
int n, k;
int main(){
    scanf("%d %d", &n, &k);

    for(int i = 0; i <= n; i++){
        arr[1][i] = 1;  // 1개로 i를 만드는 경우의 수
    }
    // a개로 num을 만드는 경우의 수 구하기
    for(int a = 2; a <= k; a++){
        for(int num = 0; num <= n; num++){
            for(int c = 0; c <= num; c++){
                arr[a][num] += arr[a-1][c];
            }
            arr[a][num] %= 1000000000;
        }
    }

    printf("%d\n", arr[k][n]);
}