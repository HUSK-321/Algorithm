#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v, trees_diameter = 0, far_point;
bool visit_this_node[100001];
vector<pair<int, int>> edge[100001];

void SearchDiameter(int node, int diameter){
    if(visit_this_node[node])
        return;

    visit_this_node[node] = true;

    if(trees_diameter < diameter){
        trees_diameter = diameter;
        far_point = node;
    }

    for(int i = 0; i < edge[node].size(); i++){
        SearchDiameter(edge[node][i].first, diameter + edge[node][i].second);
        // int next_node = edge[node][i].first;
        // int new_diameter = edge[node][i].second;
        // SearchDiameter(next_node, diameter + new_diameter);
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> v;

    for(int i = 0; i < v; i++){
        int from_node;
        cin >> from_node;
        int to_node, cost;
        cin >> to_node;
        while (to_node != -1){
            cin >> cost;

            edge[from_node].push_back(make_pair(to_node, cost));
            edge[to_node].push_back(make_pair(from_node, cost));

            cin >> to_node;
        }
    }

    // Search diameter
    SearchDiameter(1, 0);

    memset(visit_this_node, false, sizeof(visit_this_node));

    SearchDiameter(far_point, 0);

    // print
    cout << trees_diameter << '\n';
}