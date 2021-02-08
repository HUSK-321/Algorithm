#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int main(){

    int n, m;
    cin >> n >> m;
    char input;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> input;
            arr[i][j] = input - '0';
        }
    }
    int result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // 주변부 탐색
            if(arr[i][j]){
                arr[i][j] = min(min(arr[i-1][j-1], arr[i][j-1]), arr[i-1][j]);
                arr[i][j]++;
                result = max(result, arr[i][j]);
            }
        }
    }
    printf("%d\n", result*result);
}