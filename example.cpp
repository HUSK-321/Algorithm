#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int inputFrom, inputTo, inputCost;
vector<pair<int, int> > road[1001];
int city[1001];
int route[1001];
bool isEnemy[1001][1001];

void Djik(){
    priority_queue<pair<int, int> > djikQ; // 비용, 지점 순
    djikQ.push(make_pair(0, 1));
    city[1] = 0;

    while(!djikQ.empty()) {
        int cur = djikQ.top().second;
        int curCost = -djikQ.top().first;
        djikQ.pop();

        for(int i = 0; i < road[cur].size(); i++){
            int nextCur = road[cur][i].first;
            int nextCost = road[cur][i].second;

            if(city[nextCur] > curCost + nextCost){
                if(isEnemy[cur][nextCur])
                    continue;
                
                route[nextCur] = cur;
                city[nextCur] = curCost + nextCost;
                djikQ.push(make_pair(-city[nextCur], nextCur));
            }
        }
    }
}

int main(){
    // 입력
    cin >> n >> m;
    for(int i = 1; i <= n; i++) city[i] = 999999999;
    

    while (m--){
        cin >> inputFrom >> inputTo >> inputCost;
        road[inputFrom].push_back(make_pair(inputTo, inputCost));
    }

    Djik();

    // 경로를 담을 벡터 선언
    vector<int> forPrint;
    int temp = n;
    while(temp) {
        forPrint.push_back(temp);
        isEnemy[route[temp]][temp];
        temp = route[temp];
    }

    // 출력 : 최소 비용, 경로에 있는 도시 수, 경로의 도시 순
    for(int i = forPrint.size() - 1; i > 0; i--){
        isEnemy[forPrint[i]][forPrint[i-1]] = true;
    }

    for(int i = 1; i <= n; i++) city[i] = 999999999;
    Djik();

    cout << city[n] << "\n";
}