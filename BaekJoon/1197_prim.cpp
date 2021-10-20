#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e;
int a, b, c;
bool visit[10001];
vector<pair<int, int>> node[10001];

int main(){
    cin >> v >> e;
    long long answer = 0;

    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }

    priority_queue<pair<int, int>> q;

    q.push(make_pair(0, 1));

    while(!q.empty()){
        int curPos = q.top().second;
        int curCost = -q.top().first;
        q.pop();

        if(visit[curPos])
            continue;
        
        visit[curPos] = true;
        answer += curCost;

        for(int i = 0; i < node[curPos].size(); i++){
            int nextNode = node[curPos][i].first;
            int nextCost = node[curPos][i].second;

            q.push(make_pair(-nextCost, nextNode));
        }
    }

    cout << answer << '\n';
    
}