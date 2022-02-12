#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, m, r;   // 지역, 수색범위, 길의 수
int item_in_area[101];
int cost_from_start[101];
vector<pair<int, int>> edges[101];

void Yeeun_Search(int start_pos){
    // init array
    for(int i = 1; i <= n; i++)
        cost_from_start[i] = INT32_MAX;
    

    queue<int> q;
    q.push(start_pos);
    cost_from_start[start_pos] = 0;

    // search
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < edges[cur].size(); i++){
            int next_pos = edges[cur][i].first;
            int next_cost = edges[cur][i].second;

            if(cost_from_start[next_pos] > cost_from_start[cur] + next_cost){
                cost_from_start[next_pos] = cost_from_start[cur] + next_cost;
                q.push(next_pos);
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
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++)
        cin >> item_in_area[i];
    
    for(int i = 0; i < r; i++){
        int a, b, l;
        cin >> a >> b >> l;

        edges[a].push_back({b, l});
        edges[b].push_back({a, l});
    }


    // solution
    int max_items = 0;

    for(int i = 1; i <= n; i++){
        Yeeun_Search(i);

        int items = 0;
        for(int j = 1; j <= n; j++){
            if(cost_from_start[j] <= m)
                items += item_in_area[j];
        }
        max_items = max(max_items, items);
    }


    // print
    cout << max_items << endl;

    return 0;
}