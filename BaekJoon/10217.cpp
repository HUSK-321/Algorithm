#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int airport[101][10001];
const int MAX = INT32_MAX;
int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // set test case
    int t;
    cin >> t;
    while (t--){
        // input
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, pair<int, int>>> edges[n+1]; // from -> to, cost, distance
        for(int i = 0; i < k; i++){
            int from, to, c, d;
            cin >> from >> to >> c >> d;
            edges[from].push_back(make_pair(to, make_pair(c, d)));
        }

        // init array
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                airport[i][j] = MAX;
            }
        }

        // Djikstra
        priority_queue<pair<int, pair<int, int>>> q; // distance, node, cost
        q.push(make_pair(0, make_pair(1, 0)));
        airport[1][0] = 0;

        while (!q.empty()){
            int curPos = q.top().second.first;
            int curDistnace = -q.top().first;
            int curCost = q.top().second.second;
            q.pop();

            if(airport[curPos][curCost] < curDistnace)
                continue;

            for(int i = 0; i < edges[curPos].size(); i++){
                int nextPos = edges[curPos][i].first;
                int nextDistance = edges[curPos][i].second.second + curDistnace;
                int nextCost = edges[curPos][i].second.first + curCost;

                if(nextCost > m)    continue;
                if(airport[nextPos][nextCost] <= nextDistance)  continue;

                airport[nextPos][nextCost] = nextDistance;
                
                for(int j = nextCost + 1; j <= m; j++){
                    if(airport[nextPos][j] <= nextDistance)
                        break;
                    airport[nextPos][j] = nextDistance;
                }

                q.push(make_pair(-nextDistance, make_pair(nextPos, nextCost)));
            }
        }
        
        // find output
        int answer = MAX;
        for(int i = 0; i <= m; i++){
            answer = min(airport[n][i], answer);
        }

        if(answer != MAX)
            cout << answer << '\n';
        else
            cout << "Poor KCM" << '\n';
    }
}