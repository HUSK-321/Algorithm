#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, start, finish;
int inputTo, inputFrom, inputCost;
vector<pair<int, int> > bus[1001];
int toIndexCityCost[1001];

void Djik(){
    priority_queue<pair<int, int> > djikQ;
    djikQ.push(make_pair(0, start));
    toIndexCityCost[start] = 0;

    while(!djikQ.empty()) {
        int cur = djikQ.top().second;
        int curCost = -djikQ.top().first;
        djikQ.pop();

        for(int i = 0; i < bus[cur].size(); i++){
            int nextCur = bus[cur][i].first;
            int nextCost = bus[cur][i].second;

            if(toIndexCityCost[nextCur] > nextCost + curCost){
                toIndexCityCost[nextCur] = nextCost + curCost;
                djikQ.push(make_pair(-toIndexCityCost[nextCur], nextCur));
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d %d", &inputFrom, &inputTo, &inputCost);
        bus[inputFrom].push_back(make_pair(inputTo, inputCost));
    }
    scanf("%d %d", &start, &finish);

    for(int i = 0; i <= n; i++) toIndexCityCost[i] = 999999999;
    
    Djik();

    printf("%d\n", toIndexCityCost[finish]);
}