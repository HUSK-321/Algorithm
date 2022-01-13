#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// slow wolf <(*2) normal fox <(*2) fast wolf

int n, m;
int foxCost[4001];
int wolfCost[2][4001];
vector<pair<int, int>> edges[4001];

void FoxRunning(){
    priority_queue<pair<int, int>> q;   //  cost, current pos
    q.push(make_pair(0, 1));
    foxCost[1] = 0;

    while(!q.empty()){
        int cur = q.top().second;
        int cost = -q.top().first;
        q.pop();

        if(foxCost[cur] < cost)
            continue;

        for(unsigned i = 0; i < edges[cur].size(); i++){
            int next_pos = edges[cur][i].first;
            int next_cost = cost + edges[cur][i].second;

            if(next_cost < foxCost[next_pos]){
                foxCost[next_pos] = next_cost;
                q.push(make_pair(-next_cost, next_pos));
            }
        }
    }
}

void WolfRunning(){
    priority_queue<pair<int, pair<int, int>>> q;    // cost, current pos, cur state
    // start with running state (=0)
    q.push(make_pair(0, make_pair(1, 0)));
    // wolfCost[0][1] = 0;

    while(!q.empty()){
        int cur = q.top().second.first;
        int cost = -q.top().first;
        int cur_state = q.top().second.second;
        q.pop();

        int prev_state = (cur_state == 1) ? 0 : 1;
        if(wolfCost[prev_state][cur] < cost)
            continue;

        for(unsigned i = 0; i < edges[cur].size(); i++){
            int next_pos = edges[cur][i].first;
            if(cur_state == 0){
                // state = running
                int next_cost = cost + edges[cur][i].second / 2;

                if(next_cost < wolfCost[0][next_pos]){
                    wolfCost[0][next_pos] = next_cost;
                    q.push(make_pair(-next_cost, make_pair(next_pos, 1)));
                }
            }
            else{
                // state = walking
                int next_cost = cost + edges[cur][i].second * 2;

                if(next_cost < wolfCost[1][next_pos]){
                    wolfCost[1][next_pos] = next_cost;
                    q.push(make_pair(-next_cost, make_pair(next_pos, 0)));
                }
            }
        }
    } 
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(unsigned i = 0; i < 4001; i++){
        foxCost[i] = INT_MAX;
        wolfCost[0][i] = INT_MAX;
        wolfCost[1][i] = INT_MAX;
    }

    // input
    cin >> n >> m;
    for(unsigned i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        edges[from].push_back(make_pair(to, cost*2));
        edges[to].push_back(make_pair(from, cost*2));
    }

    // Djikstra
    FoxRunning();
    WolfRunning();
    
    int wolf_win_count = 0;
    for(unsigned i = 2; i <= n; i++){
        if(foxCost[i] < min(wolfCost[0][i], wolfCost[1][i]))
            wolf_win_count++;
    }

    cout << wolf_win_count << endl;
    return 0;
}   