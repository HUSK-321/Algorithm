#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> posX;
vector<pair<int, int>> posY;
vector<pair<int, int>> posZ;
vector<pair<int, pair<int, int>>> edges; // distance, index, index
int parent[100001];

int findParent(int x){
    if(x == parent[x])
        return x;
    return parent[x] = findParent(parent[x]);
}

void merge(int x, int y){
    x = findParent(x);
    y = findParent(y);

    if(x == y)  return;

    parent[x] = y;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(unsigned i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;

        posX.push_back(make_pair(x, i));
        posY.push_back(make_pair(y, i));
        posZ.push_back(make_pair(z, i));
    }
    
    // init
    for(unsigned i = 0; i <= n; i++)
        parent[i] = i;
    sort(posX.begin(), posX.end());
    sort(posY.begin(), posY.end());
    sort(posZ.begin(), posZ.end());

    // make edges
    for(unsigned i = 0; i < n-1; i++){
        int distX = posX[i+1].first - posX[i].first;
        int distY = posY[i+1].first - posY[i].first;
        int distZ = posZ[i+1].first - posZ[i].first;

        edges.push_back(make_pair(distX, make_pair(posX[i].second, posX[i+1].second)));
        edges.push_back(make_pair(distY, make_pair(posY[i].second, posY[i+1].second)));
        edges.push_back(make_pair(distZ, make_pair(posZ[i].second, posZ[i+1].second)));
    }

    sort(edges.begin(), edges.end());

    // solve
    int unionCount = 0;
    int answer = 0;
    for(unsigned i = 0; i < edges.size(); i++){
        if(unionCount == n-1)   break;

        int dist = edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;

        if(findParent(x) != findParent(y)){
            merge(x, y);
            answer += dist;
            unionCount++;
        }
    }

    cout << answer << '\n';
}