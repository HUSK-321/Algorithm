#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, x;    // 학생 수, 도로 수, 목적지
int from, to, t;
int ans;
int cur, time, nextCur, nextTime;
int arr[1010], temp[1010];
vector<pair<int, int>> vec[1010];   // [출발지] = 도착지, 시간


void Djik(int start){
    priority_queue<pair<int, int>> q;   //  시간, 출발

    arr[start] = 0;
    q.push(make_pair(0, start));

    while(!q.empty()){
        cur = q.top().second;
        time = -q.top().first;
        q.pop();

        for(int i = 0; i < vec[cur].size(); i++){
            nextCur = vec[cur][i].first;
            nextTime = vec[cur][i].second;

            if(arr[nextCur] > time + nextTime) {
                arr[nextCur] = time + nextTime;
                q.push(make_pair(-arr[nextCur], nextCur));
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &x);

    while(m--){
        scanf("%d %d %d", &from, &to, &t);
        vec[from].push_back(make_pair(to, t));
    }

    for(int i = 1; i <= n; i++){
        memset(arr, 0x7f, sizeof(arr));
        Djik(i);
        temp[i] = arr[x];
    }

    memset(arr, 0x7f, sizeof(arr));
    Djik(x);

    for(int i = 1; i <= n; i++){
        temp[i] += arr[i];
    }

    sort(temp + 1, temp + n + 1);

    printf("%d\n", temp[n]);
}