#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k; // 도시 수, 도시간 간선 수, k번째 최단거리 수
int a, b, c; // a -> b 로 갈때 c만큼 비용
vector<pair<int, int>> vec[1001]; // 인덱스 -> first까지 가는데 second만큼 비용듬
priority_queue<int> city[1001];

int main(){
    // 입력
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        vec[a].push_back({make_pair(b, c)});
    }

    // 다익스트라 알고리즘을 통해 풀이
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, 1)); // 우선순위 큐라 비용이 먼저 들어간다
    city[1].push(0);

    while(!q.empty()) {
        int cur, cost;  // 현재지점, 비용
        cur = q.top().second;
        cost = q.top().first;
        q.pop();

        for(int i = 0; i < vec[cur].size(); i++){
            int nextCur, nextCost;
            nextCur = vec[cur][i].first;
            nextCost = vec[cur][i].second;

            if(city[nextCur].size() < k){
                city[nextCur].push(cost + nextCost);
                q.push(make_pair(cost + nextCost, nextCur));
            } else if(city[nextCur].top() > cost + nextCost) {
                city[nextCur].pop();
                city[nextCur].push(cost + nextCost);
                q.push(make_pair(cost + nextCost, nextCur));
            }
        }
    }


    // 출력
    for(int i = 1; i <= n; i++){
        if(city[i].size() < k)
            printf("-1\n");
        else
            printf("%d\n", city[i].top());

    }
}