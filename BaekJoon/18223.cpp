#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
using namespace std;

int v, e, minjun;
int costs[5001];
vector<pair<int, int>> edges[5001];

int Djikstra(int start, int finish){
    for(int i = 0; i <= v; i++){
        costs[i] = INT32_MAX;
    }

    // Djikstra
    priority_queue<pair<int, int>> q; // cost, node
    q.push({0, start});
    costs[start] = 0;

    while (!q.empty()){
        int curCost = -q.top().first;
        int curPos = q.top().second;
        q.pop();

        if(costs[curPos] < curCost)
            continue;

        for(int i = 0; i < edges[curPos].size(); i++){
            int nextCost = curCost + edges[curPos][i].second;
            int nextPos = edges[curPos][i].first;

            if(costs[nextPos] > nextCost){
                costs[nextPos] = nextCost;
                q.push({-nextCost, nextPos});
            }
        }
    }

    return costs[finish];
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> v >> e >> minjun;
    for(int i = 0; i <= v; i++){
        costs[i] = INT32_MAX;
    }
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    int minDist = Djikstra(1, v);
    int startToMinjun = Djikstra(1, minjun);
    int minjunToFin = Djikstra(minjun, v);
    
    if(minDist == (startToMinjun + minjunToFin)) 
        cout << "SAVE HIM\n";
    else
        cout << "GOOD BYE\n";
}