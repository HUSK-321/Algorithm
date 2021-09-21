#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
int parent[100001];
vector<pair<int, pair<int, int> > > edge;


int FindParent(int x){
    if(x == parent[x])
        return x;
    else 
        return parent[x] = FindParent(parent[x]);
}

bool IsSameParent(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return true;
    else 
        return false;
}

void Union(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return;
    parent[y] = x;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        edge.push_back(make_pair(cost, make_pair(start, end)));
    }

    sort(edge.begin(), edge.end());
    for(int i = 0; i <= n; i++)
        parent[i] = i;
    
    for(int i = 0; i < edge.size(); i++){
        if(!IsSameParent(edge[i].second.first, edge[i].second.second)){
            Union(edge[i].second.first, edge[i].second.second);
            n--;
            if(n > 1)
                ans += edge[i].first;
        }
    }

    cout << ans << '\n';

}