#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int parent, child, cost;
bool visit[10001];
int result = 0;
int farpoint;
vector<pair<int, int>> edge[10001];

void DFS(int node, int diameter){
    if(visit[node])
        return;
    
    visit[node] = true;

    if(result < diameter){
        result = diameter;
        farpoint = node;
    }

    for(int i = 0; i < edge[node].size(); i++){
        DFS(edge[node][i].first, diameter + edge[node][i].second);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> parent >> child >> cost;
        edge[parent].push_back(make_pair(child, cost));
        edge[child].push_back(make_pair(parent, cost));
    }

    // solve
    DFS(1, 0);

    memset(visit, false, sizeof(visit));

    DFS(farpoint, 0);

    // output
    cout << result << '\n';
}