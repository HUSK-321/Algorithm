#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxDistance = 0;
    vector<int> distance(n+1);
    vector<bool> visit(n+1);
    for(unsigned i = 0; i <= n; i++)
        distance[i] = 999999999;

    vector<vector<int>> road(n+1);
    for(unsigned i = 0; i < edge.size(); i++){
        int from = edge[i][0];
        int to = edge[i][1];

        road[from].push_back(to);
        road[to].push_back(from);
    }

    // bfs
    queue<pair<int, int>> q;  // node, cost
    q.push(make_pair(1, 0));
    while (!q.empty()){
        int curPos = q.front().first;
        int curCost = q.front().second;
        q.pop();

        for(unsigned i = 0; i < road[curPos].size(); i++){
            int nextPos = road[curPos][i];
            int nextCost = curCost+1;

            if(visit[nextPos])
                continue;

            if(distance[nextPos] >= nextCost){
                visit[nextPos] = true;
                distance[nextPos] = nextCost;
                q.push(make_pair(nextPos, nextCost));
            }
        }
    }
    
    for(unsigned i = 2; i <= n; i++)
        maxDistance = max(maxDistance, distance[i]);
    
    for(unsigned i = 2; i <= n; i++)
        if(distance[i] == maxDistance)
            answer++;

    return answer;
}