#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cost[55];
vector<pair<int, int>> edge[55];

void Djikstra(){
    cost[1] = 0;
    priority_queue<pair<int, int>> q; // cost, node
    q.push(make_pair(0, 1));

    while (!q.empty()){
        int curPos = q.top().second;
        int curCost = -q.top().first;
        q.pop();

        if(cost[curPos] < curCost)    continue;

        for(int i = 0; i < edge[curPos].size(); i++){
            int nextPos = edge[curPos][i].first;
            int nextCost = edge[curPos][i].second;

            if(cost[nextPos] > nextCost + curCost){
                cost[nextPos] = nextCost + curCost;
                q.push(make_pair(-cost[nextPos], nextPos));
            }
        }        
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;
    // init
    for(int i = 1; i <= N; i++)    cost[i] = 999999999;

    // make input
    for(int i = 0; i < road.size(); i++){
        int from = road[i][0];
        int to = road[i][1];
        int time = road[i][2];

        edge[from].push_back(make_pair(to, time));
        edge[to].push_back(make_pair(from, time));
    }

    // calculate
    Djikstra();
    
    // solution
    for(int i = 2; i <= N; i++){
        if(cost[i] <= K)
            answer++;
    }
    return answer;
}