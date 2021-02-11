#include <iostream>
using namespace std;
int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, m, i, j;
    int sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        arr[i+1] = arr[i] + input;
    }
    while(m--){
        cin >> i >> j;
        if(i == 0)
            cout << arr[j] << '\n';
        else
            cout << arr[j] - arr[i-1] << '\n';
    }

}