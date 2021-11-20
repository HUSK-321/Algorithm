#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b;
int enterance[1001];
int howmany[1001];
vector<int> edge[1001];

void Topology(){
    int cur_sem = 1;
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        if(enterance[i] == 0){
            q.push(make_pair(i, 1));
        }
    }

    while (!q.empty()){
        int cur = q.front().first;
        int cur_season = q.front().second;
        q.pop();

        howmany[cur] = cur_season;

        for(int i = 0; i < edge[cur].size(); i++){
            int nextCur = edge[cur][i];
            enterance[nextCur]--;

            if(enterance[nextCur] == 0){
                q.push(make_pair(nextCur, cur_season+1));
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
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++)
        howmany[i] = 1;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        enterance[b]++;
        edge[a].push_back(b);
    }

    // topology sory
    Topology();

    // print
    for(int i = 1; i <= n; i++){
        cout << howmany[i] << " ";
    }
    cout << '\n';
    return 0;
}