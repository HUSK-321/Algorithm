#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
int cows[50001];
vector<pair<int, int>> edges[50001];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i <= n ; i++)
        cows[i] = INT32_MAX;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    // Djikstra
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    cows[1] = 0;

    while (!q.empty()){
        int curCost = -q.top().first;
        int curPos = q.top().second;
        q.pop();

        for(int i = 0; i < edges[curPos].size(); i++){
            int nextCost = curCost + edges[curPos][i].second;
            int nextPos = edges[curPos][i].first;

            if(cows[nextPos] > nextCost){
                cows[nextPos] = nextCost;
                q.push({-nextCost, nextPos});
            }
        }
    }
    
    cout << cows[n] << '\n';

}