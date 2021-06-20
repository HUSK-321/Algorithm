#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int res = 1000010;
    int house[1005][3];
    int arr[1005][3];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &house[i][j]);
        }
    }

    for(int j = 0; j < 3; j++){
        // 다른 색은 고를 수 없게 초기화
        arr[0][0] = 1000010;
        arr[0][1] = 1000010;
        arr[0][2] = 1000010;
        // 이번에 볼 색상
        arr[0][j] = house[0][j];

        for(int i = 1; i < n; i++){
            arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + house[i][0];
            arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + house[i][1];
            arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + house[i][2];
        }

        for(int i = 0; i < 3; i++){
            if(i == j)
                continue;
            res = min(res, arr[n-1][i]);
        }
    }

    printf("%d\n", res);

}