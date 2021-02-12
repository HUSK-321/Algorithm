#include <iostream>
#include<algorithm>
using namespace std;
// 0 : R, 1 : G, 2 : B 값을 받아온다
int arr[1001][3];
int rgb[3];
int main(){
    int n;
    cin >> n;
    arr[0][0] = 0; arr[0][1] = 0; arr[0][2] = 0;
    for(int i = 1; i <= n; i++){
        cin >> rgb[0] >> rgb[1] >> rgb[2];
        arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + rgb[0];
        arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + rgb[1];
        arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + rgb[2];
    }
    int result = min(min(arr[n][0], arr[n][1]), arr[n][2]);
    cout << result << '\n';
}