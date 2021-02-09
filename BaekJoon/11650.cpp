#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b){
    if(b.first > a.first)
        return true;
    else if(b.first == a.first){
        if(b.second > a.second)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main(){
    int n;
    cin >> n;

    vector< pair<int, int> > arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), compare);
    for(int i = 0; i < n; i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
}