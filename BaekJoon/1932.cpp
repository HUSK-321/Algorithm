#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];    //i층 j칸
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
        }
    }
    int result = 0;
    for(int i = 1; i <= n; i++){
        result = max(result, arr[n][i]);
    }
    cout << result << "\n";
}