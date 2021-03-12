#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int arr[11];
int result = 0;
int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int i = n-1;
    while(i >= 0 && k){
        result += k/arr[i];
        k %= arr[i];
        --i;
    }

    cout << result << '\n';
}