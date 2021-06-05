#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 501
using namespace std;

int n, m, start, finish;
int inputFrom, inputTo, inputCost;
int city[MAX];
bool isFast[MAX][MAX];
bool visit[MAX];

void Djik(vector<pair<int, int> > road[]){
    for(int i = 0; i <= n; i++)
        city[i] = 999999999;

    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, start));
    city[start] = 0;

    while (!q.empty()){
        int cur = q.top().second;
        int curCost = -q.top().first;
        q.pop();

        if(city[cur] < curCost)
            continue;

        for(int i = 0; i < road[cur].size(); i++){
            int nextCur = road[cur][i].first;
            int nextCost = road[cur][i].second;

            // 빠른길 건너뛰기
            if(isFast[cur][nextCur] == true)
                continue;

            if(city[nextCur] > curCost + nextCost){
                city[nextCur] = curCost + nextCost;
                q.push(make_pair(-city[nextCur], nextCur));
            }
        }
    } 
}

void FastRoadSearch(vector<pair<int, int> > inverserRoad[]){
    queue<int> q;
    q.push(finish);

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        if(visit[cur] == true)
            continue;
        if(cur == start)
            continue;
        
        visit[cur] = true;
        for(int i = 0; i < inverserRoad[cur].size(); i++){
            int prev = inverserRoad[cur][i].first;

            if(city[prev] + inverserRoad[cur][i].second == city[cur]){
                isFast[prev][cur] = true;
                q.push(prev);
            }
        }
    } 
}

int main(){
    while(true){
        // 초기화 해야 할 것들
        // city(거리값저장 배열), isFast
        memset(isFast, false, sizeof(isFast));
        memset(visit, false, sizeof(visit));
        // 입력
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        cin >> start >> finish;

        // 경로 저장
        vector<pair<int, int> > road[MAX];
        vector<pair<int, int> > inverseRoad[MAX];
        
        
        while(m--){
            cin >> inputFrom >> inputTo >> inputCost;
            road[inputFrom].push_back(make_pair(inputTo, inputCost));
            inverseRoad[inputTo].push_back(make_pair(inputFrom, inputCost));
        }
        // 탐색
        Djik(road);
        FastRoadSearch(inverseRoad);
        Djik(road);

        if(city[finish] == 999999999)
            cout << "-1\n";
        else
            cout << city[finish] << '\n';
    }
    
}