#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, s, f;
vector<pair<int, int>> road[10001];
bool visit[10001];

bool Bfs(int input){
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == f)
            return true;

        for(int i = 0; i < road[cur].size(); i++){
            if(!visit[road[cur][i].first] && input <= road[cur][i].second){
                visit[road[cur][i].first] = true;
                q.push(road[cur][i].first);
            }
        }
    }
    return false;
}


int main(){
    scanf("%d %d", &n, &m);

    int MAX = 0;
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        road[a].push_back(make_pair(b,c));
        road[b].push_back(make_pair(a,c));
        MAX = max(MAX, c);
    }

    scanf("%d %d", &s, &f);

    // 이진 탐색 시작
    int left = 0, right = MAX;
    while (left <= right){
        memset(visit, false, sizeof(visit));
        int mid = (left + right) / 2;
        if(Bfs(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("%d\n", right);
}