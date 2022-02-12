#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

int n, m, s, t;
vector<pair<int, int>> edges[5001];
int cost_from_start[5001];

void Djik(){
    priority_queue<pair<int, int>> q;   // cost, vertex
    q.push({0, s});
    cost_from_start[s] = 0;

    while(!q.empty()){
        int cur = q.top().second;
        int cost = -q.top().first;
        q.pop();

        if(cost_from_start[cur] < cost)
            continue;
        
        if(cur == t){
            cout << cost << endl;
            return;
        }
        

        for(unsigned i = 0; i < edges[cur].size(); i++){
            int next_pos = edges[cur][i].first;
            int next_cost = cost + edges[cur][i].second;

            if(next_cost < cost_from_start[next_pos]){
                cost_from_start[next_pos] = next_cost;
                q.push({-next_cost, next_pos});
            }
        }
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input;
    cin >> n >> m;   // vertex, edge count;
    for(unsigned i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    cin >> s >> t;

    // solution
    for(int i = 0; i <= n; i++)
        cost_from_start[i] = INT32_MAX;

    Djik();

    return 0;
    
}