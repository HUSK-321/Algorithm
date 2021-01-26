#include <iostream>
#include <algorithm>
using namespace std;
// 1, 3, 4
// SK : 1,3,4,5, 
// CY : 2,
int main(){
    int n;
    cin >> n;
    int arr[1001];
    arr[1] = 1;
    arr[2] = 0;
    arr[3] = 1;
    arr[4] = 1;

    for(int i = 5; i <= n; i++){
        if(min({ arr[i-1], arr[i-3], arr[i-4]}) == 1)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    if(arr[n] == 1)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
}