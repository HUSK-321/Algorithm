#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int parent[1001];
int cost[1001][1001];
vector<pair<int, pair<int, int>>> edge;

int FindParent(int x){
    if(x == parent[x])
        return x;
    
    return parent[x] = FindParent(parent[x]);
}

bool SameParent(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return true;
    return false;
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return;
    parent[x] = y;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // input
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> cost[i][j];
        }
    }    
    
    // init
    for(int i = 1; i <= n; i++) 
        parent[i] = i;

    // edge
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            edge.push_back(make_pair(cost[i][j], make_pair(i, j)));
        }
    }

    // Make MST
    long long ans = 0;
    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        if(!SameParent(edge[i].second.first, edge[i].second.second)){
            ans += edge[i].first;
            Merge(edge[i].second.first, edge[i].second.second);
        }
    }

    cout << ans << '\n';
}