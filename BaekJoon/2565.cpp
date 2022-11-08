#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> edge[501];
int arr[501];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> edge[i].first >> edge[i].second;
    }

    sort(edge, edge + n);

    int accentLine = 0;
    for(int i = 0; i < n; i++){
        arr[i] = 1;
        for(int j = 0; j < i; j++){
            if(edge[i].second > edge[j].second){
                arr[i] = max(arr[i], arr[j] + 1);
            }
        }
        accentLine = max(accentLine, arr[i]);
    }

    cout << n - accentLine << '\n';
}