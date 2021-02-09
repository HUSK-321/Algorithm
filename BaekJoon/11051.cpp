#include <iostream>
using namespace std;
int arr[1001][1001];
int n, k;
int main(){
    cin >> n >> k;
    // i는 층 j는 칸
    // n,k = n-1,k-1 + n-1,k   (씽크빅)
    for(int i = 1; i <= 1000; i++){
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(int j = 1; j < i; j++){
            arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) % 10007;
        }
    }
    cout << arr[n][k] << "\n";
}