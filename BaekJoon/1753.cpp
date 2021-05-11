#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int v, e, k;    // 정점 수, 간선 수, 시작 지점
int cur, weight;
int nextP, nextW;
int arr[20001]; // 시작지점이 인덱스로 가는데까지 비용 저장
vector<pair<int, int>> vec[20001]; // 현재 지점, 비용 순

int main(){
    // 입력
    scanf("%d %d", &v, &e);
    scanf("%d", &k);

    for(int i = 0; i < e; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        vec[x].push_back(make_pair(y, z));
    }
    // 배열 초기화
    for(int i = 1; i <= v; i++)
        arr[i] = INF;


    priority_queue<pair<int, int>> q;   // 비용, 지점 순으로 우선순위
    q.push(make_pair(0, k));
    arr[k] = 0;

    while(!q.empty()){
        weight = -q.top().first;
        cur = q.top().second;
        q.pop();

        for(int i = 0; i < vec[cur].size(); i++){
            nextP = vec[cur][i].first;
            nextW = vec[cur][i].second;

            if(arr[nextP] > weight + nextW){
                arr[nextP] = weight + nextW;
                q.push(make_pair(-arr[nextP], nextP));
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(arr[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", arr[i]);
    }

}