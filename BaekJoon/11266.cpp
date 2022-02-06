#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<int> edge[10001];
bool is_node_articulation_point[10001];
int visit_order[10001];
int order = 0;

int SearchGraph(int cur, bool isRoot){
    visit_order[cur] = ++order;
    int res = visit_order[cur];

    int child_count = 0;
    for(unsigned i = 0; i < edge[cur].size(); i++){
        int next = edge[cur][i];

        // already visit
        // -> 방문점들 중 가장 빠른 방문 순서를 찾는 것.
        if(visit_order[next]){
            res = min(res, visit_order[next]);
            continue;
        }

        child_count++;
        int prev = SearchGraph(next, false);

        if(!isRoot && prev >= visit_order[cur])
            is_node_articulation_point[cur] = true;
        
        res = min(res, prev);
    }

    // root node의 자식이 2 이상이면 바로 나눌 수 있음
    if(isRoot && (child_count >= 2))
        is_node_articulation_point[cur] = true;

    return res;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> v >> e;
    for(unsigned i = 0; i < e; i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    for(unsigned i = 1; i <= v; i++)
        SearchGraph(i, true);

    vector<int> point;
    for(unsigned i = 1; i <= v; i++){
        if(is_node_articulation_point[i])
            point.push_back(i);
    }

    cout << point.size() << endl;
    for(unsigned i = 0; i < point.size(); i++){
        cout << point[i] << " ";
    }

    return 0;
}