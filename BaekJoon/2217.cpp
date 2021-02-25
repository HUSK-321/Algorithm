#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, arr[100001];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    // w / k
    int result = 0;
    for(int i = 0; i < n; i++){
        if(result < (n-i)*arr[i])
            result = (n-i)*arr[i];
    }
    cout << result << '\n';
}