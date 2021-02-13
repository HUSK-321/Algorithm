#include <iostream>
#include <algorithm>
using namespace std;
long long func(int a, int b){
    return (a-b)*(a-b);
}
int main(){
    int t;
    long long arr[6];
    int x[4], y[4];// x,y좌표, arr : 각 점의 차이 (이후 대각선은 뒤로)
    cin >> t;
    while(t--){
        for(int i = 0; i < 4; i++){
            cin >> x[i] >> y[i];
        }
        // 1 : 점 1,2 길이 / 2 : 2,3 길이 / 3 : 3,4 길이 / 4 : 4, 1 길이 / 5 : 1,3 길이 / 6 : 2,4 길이
        // 1-2,3,4   /  2-3,4  /  3 -4 : 총 6개 경우
        /*arr[1] = func(x[1], x[2]) + func(y[1], y[2]);
        arr[2] = func(x[2], x[3]) + func(y[1], y[2]);
        arr[3] = func(x[3], x[4]) + func(y[1], y[2]);
        arr[4] = func(x[4], x[1]) + func(y[1], y[2]);
        arr[5] = func(x[1], x[3]) + func(y[1], y[2]);
        arr[6] = func(x[2], x[4]) + func(y[1], y[2]);*/
        int count = 0;
        for(int i = 0; i < 4; i++){
            for(int j = i+1; j < 4; j++){
                arr[count] = func(x[i], x[j]) + func(y[i], y[j]);
                count++;
            }
        }
        sort(arr, arr+6);
        cout << ((arr[0] == arr[1]) && (arr[0] == arr[2]) && (arr[0] == arr[3]) && (arr[4] == arr[5])) << '\n';
    }
}