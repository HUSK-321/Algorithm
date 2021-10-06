#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[16];
int main(){
    int t = 16;

    while(t--){
        int x, y;
        cin >> x >> y;
        arr[16-t] = make_pair(x, y);
    }

    sort(arr, arr+16);

    for(int i = 0; i < 16; i++){
        cout << "(" <<arr[i].first << ", " << arr[i].second << "), ";
    }
}