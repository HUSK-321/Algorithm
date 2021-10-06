#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a, b, c;
int parent[1001];
vector<pair<int, pair<int, int> > > edge;

int FindParent(int x){
    if(x == parent[x])
        return x;
    else 
        return parent[x] = FindParent(parent[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y) return;

    parent[x] = y;
}
bool IsSameParent(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return true;
    else
        return false;
}


int main(){
    int ans = 0;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(edge.begin(), edge.end());
    
    for(int i = 0; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < m; i++){
        if(!IsSameParent(edge[i].second.first, edge[i].second.second)){
            Merge(edge[i].second.first, edge[i].second.second);
            ans = ans + edge[i].first;
        }
    }

    cout << ans << '\n';
}