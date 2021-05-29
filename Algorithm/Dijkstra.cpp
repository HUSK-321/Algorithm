#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// arr은 문제의 시작 지점이 인덱스로 가는데까지 비용을 저장
int arr[100];
// 입력에서 인덱스가 출발지가 되고 <도착지, 비용> 순으로 받아오게 됩니다.
vector<pair<int, int>> v[100];
void Djikstra(int start){
    // 큐에는 시간, 출발지 순으로 데이터가 들어가게 됩니다.
    // 때문에 우선순위 큐는 시간에 따라서 우선순위를 만들어 줍니다.
    priority_queue<pair<int, int>> q;

    arr[start] = 0;
    q.push(make_pair(0, start));

    while(!q.empty()){
        int cur = q.top().second;
        int time = q.top().first;
        q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            int nextCur = v[cur][i].first;
            int nextTime = v[cur][i].second;

            if(arr[nextCur] > time + nextTime){
                arr[nextTime] = time + nextTime;
                q.push(make_pair(-arr[nextCur], nextCur));
            }
        }
    }
}