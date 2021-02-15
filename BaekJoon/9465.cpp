#include <iostream>
#include <algorithm>
using namespace std;
int arr[2][100001];     // 스티커 점수
int result[2][100001];  // 스티커 점수합
int main(){
    int t, n;
    cin >> t;

    while (t--){
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
                cin >> arr[i][j];
            }
        }

        result[0][1] = arr[0][1];
        result[1][1] = arr[1][1];

        for(int i = 2; i <= n; i++){
            // 시작점 2개
            result[0][i] = max(result[1][i-1], result[1][i-2]) + arr[0][i];
            result[1][i] = max(result[0][i-1], result[0][i-2]) + arr[1][i];
        }

        cout << max(result[0][n], result[1][n]) << "\n";
    }
    
}
