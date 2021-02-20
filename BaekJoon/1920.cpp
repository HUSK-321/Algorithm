#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);

    cin >> m;

    while(m--){
        int input;
        cin >> input;
        cout << binary_search(arr, arr+n, input) << '\n';
    }
}