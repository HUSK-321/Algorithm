#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 501;
vector<int32_t> edge[MAX];
int capacity[MAX][MAX], flow[MAX][MAX];

int GetMaxFlow(int start, int end){
    int sum{ 0 };
    while(true){
        int parent[MAX] = {};
        queue<int> q;
        q.push(start);
        parent[start] = start;

        while (!q.empty() && !parent[end]){
            int curPos = q.front();
            q.pop();
            for(auto next : edge[curPos]){
                if(capacity[curPos][next] - flow[curPos][next] > 0 && !parent[next]){
                    q.push(next);
                    parent[next] = curPos;
                    if(next == end) break;
                }
            }
        }
        if(!parent[end])    break;

        int amount = INT32_MAX;
        for(int i = end; i != start; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);
        for(int i = end; i != start; i = parent[i]){
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }
        sum += amount;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, source, target;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].push_back(to);
        edge[to].push_back(from);
        capacity[from][to] = capacity[to][from] = cost;
    }
    cin >> source >> target;

    cout << GetMaxFlow(source, target) << '\n';
}