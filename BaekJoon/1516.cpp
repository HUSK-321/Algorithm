#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int build_cost[501], previous_count[501];
vector<int> route[501];
int tower_time[501];

void TopologySort(){
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(previous_count[i] == 0){
            q.push(i);
            tower_time[i] = build_cost[i];
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < route[cur].size(); i++){
            int nextCur = route[cur][i];
            previous_count[nextCur]--;

            tower_time[nextCur] = max(tower_time[nextCur], tower_time[cur] + build_cost[nextCur]);

            if(previous_count[nextCur] == 0){
                q.push(nextCur);
            }
        }
    }  
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> build_cost[i];
        while (true){
            int input;
            cin >> input;
            if(input == -1) 
                break;

            route[input].push_back(i);
            previous_count[i]++;
        }
    }

    // solution
    TopologySort();

    // print
    for(int i = 1; i <= n; i++){
        cout << tower_time[i] << '\n';
    }
}