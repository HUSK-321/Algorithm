#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;
int pos1, pos2;
int a, b, c;
vector<pair<int, int>> edges[801];
const int MAX = 999999999;
int costToIndex[801];

void InitArray(){
    for(int i = 1; i <= n; i++) costToIndex[i] = MAX;
}

void FindPath(int start){
    InitArray();
    priority_queue<pair<int, int>> q;
    q.push({0, start});
    costToIndex[start] = 0;

    while(!q.empty()){
        int curCost = -q.top().first;
        int curPos = q.top().second;
        q.pop();

        for(int i = 0; i < edges[curPos].size(); i++){
            int nextPos = edges[curPos][i].first;
            int nextCost = edges[curPos][i].second + curCost;

            if(costToIndex[nextPos] > nextCost){
                costToIndex[nextPos] = nextCost;
                q.push({-nextCost, nextPos});
            }
        }
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    cin >> pos1 >> pos2;

    // solve
    int answer1 = 0, answer2 = 0;
    bool firstRoute = true, secondRoute = true;

    // should search two route
    // first route : s -> 1 -> 2 -> e
    // second route : s -> 2 -> 1 -> e
    FindPath(1);    
    answer1 = costToIndex[pos1]; // s -> 1
    answer2 = costToIndex[pos2]; // s -> 2
    if(answer1 == MAX)  firstRoute = false;
    if(answer2 == MAX)  secondRoute = false;

    // cost pos1 <-> pos2
    FindPath(pos1);
    if(costToIndex[pos2] == MAX){
        cout << "-1\n";
        return 0;
    }
    if(firstRoute)  answer1 += costToIndex[pos2]; // 1 -> 2
    if(secondRoute) answer2 += costToIndex[pos2]; // 2 -> 1

    FindPath(n);
    if(firstRoute)  answer1 += costToIndex[pos2]; // 2 -> n
    if(secondRoute) answer2 += costToIndex[pos1]; // 1 -> n

    // print cost
    if(!firstRoute && !secondRoute){
        cout << "-1\n";
        return 0;
    }
    int finalCost = min(answer1, answer2);
    if(finalCost > MAX){
        cout << "-1\n";
        return 0;
    }
    cout << finalCost << '\n';
    return 0;
}