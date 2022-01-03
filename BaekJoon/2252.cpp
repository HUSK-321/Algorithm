#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int from, to;
int inCome[32001];
vector<int> node[32001];

void TopologySort(){
    queue<int> q;

    // init queue
    for(int i = 1; i <= n; i++){
        if(inCome[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for(int i = 0; i < node[cur].size(); i++){
            int nextCur = node[cur][i];
            inCome[nextCur]--;

            if(inCome[nextCur] == 0)
                q.push(nextCur);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(inCome, 0, sizeof(inCome));
    // input
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> from >> to;
        inCome[to] = inCome[to] + 1;
        node[from].push_back(to);
    }

    // solve
    TopologySort();
    cout << '\n';

    return 0;
}