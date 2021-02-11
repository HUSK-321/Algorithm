#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int w = 1;      //왼쪽 물건 변수
    for(int i = 0; i < n; i++){
        if(arr[i] > w){
            break;
        }
        w += arr[i];
    }
    cout << w << "\n";
}