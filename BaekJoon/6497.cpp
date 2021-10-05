#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
vector<pair<int, pair<int, int>>> edges;
int houses[200001];

int FindGroup(int x){
    if(x == houses[x])
        return x;
    return houses[x] = FindGroup(houses[x]);
}

void Merge(int x, int y){
    x = FindGroup(x);
    y = FindGroup(y);

    if(x == y)  return;

    houses[x] = y;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true){
        // init
        edges.clear();
        int cost = 0;
        // input
        cin >> m >> n;

        if(m == 0 && n == 0)
            return 0;

        for(int i = 0; i < m; i++)
            houses[i] = i;
        int x, y, z;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> z;
            edges.push_back({z, {x, y}});
            cost += z;
        }

        // solve
        sort(edges.begin(), edges.end());

        for(int i = 0; i < n; i++){
            if(FindGroup(edges[i].second.first) == FindGroup(edges[i].second.second))
                continue;
            
            Merge(FindGroup(edges[i].second.first), FindGroup(edges[i].second.second));
            cost -= edges[i].first;
        }

        cout << cost << '\n';
    }

}