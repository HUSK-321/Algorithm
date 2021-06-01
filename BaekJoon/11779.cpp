#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, start, finish;
int inputFrom, inputTo, inputCost;
vector<pair<int, int> > road[1001];
int city[1001];
int route[1001];
int main(){
    // 입력
    cin >> n >> m;
    for(int i = 1; i <= n; i++) city[i] = 999999999;
    while (m--){
        cin >> inputFrom >> inputTo >> inputCost;
        road[inputFrom].push_back(make_pair(inputTo, inputCost));
    }

    cin >> start >> finish;

    priority_queue<pair<int, int> > djikQ; // 비용, 지점 순
    djikQ.push(make_pair(0, start));
    city[start] = 0;

    while(!djikQ.empty()) {
        int cur = djikQ.top().second;
        int curCost = -djikQ.top().first;
        djikQ.pop();

        for(int i = 0; i < road[cur].size(); i++){
            int nextCur = road[cur][i].first;
            int nextCost = road[cur][i].second;

            if(city[nextCur] > curCost + nextCost){
                route[nextCur] = cur;
                city[nextCur] = curCost + nextCost;
                djikQ.push(make_pair(-city[nextCur], nextCur));
            }
        }
    }

    // 경로를 담을 벡터 선언
    vector<int> forPrint;
    int temp = finish;
    while(temp) {
        forPrint.push_back(temp);
        temp = route[temp];
    }
    int size = forPrint.size();
    // 출력 : 최소 비용, 경로에 있는 도시 수, 경로의 도시 순
    printf("%d\n", city[finish]);
    printf("%d\n", size);
    for(int i = size - 1; i >= 0; i--)
        printf("%d ", forPrint[i]);

}