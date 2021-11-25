#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, w, vi, wi;
int cost[10001];

int main(){
    // input
    cin >> n >> w;

    for(int i = 0; i < n; i++){
        cin >>  vi >> wi;
        for(int i = w; i >= wi; i--){
            cost[i] = max(cost[i], cost[i-wi] + vi);
        }
    }

    cout << cost[w] << '\n';
    // vector<pair<int, int>> things(n);
    // for(int i = 0; i < n; i++){
    //     cin >> things[i].first >> things[i].second;
    // }

}