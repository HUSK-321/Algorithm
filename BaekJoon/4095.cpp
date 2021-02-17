#include <iostream>
using namespace std;
int arr[1001][1001];
int main(){
    while(true){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> arr[i][j];
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
        cout << result << '\n';
    }
    return 0;
}