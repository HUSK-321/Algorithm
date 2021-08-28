#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n;
int parent[101];
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> edge;

int FindParent(int x){
    if(x == parent[x])
        return x;
    else 
        return parent[x] = FindParent(parent[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);
    
    parent[y] = x;
}

double Distance(double x1, double y1, double x2, double y2){
    double tempx = (x1 - x2) * (x1 - x2);
    double tempy = (y1 - y2) * (y1 - y2);
    
    return sqrt(tempx + tempy);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2);

    cin >> n;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        star.push_back(make_pair(x, y));
    }

    for(int i = 0; i < star.size(); i++){
        double x1 = star[i].first;
        double y1 = star[i].second;

        for(int j = i + 1; j < star.size(); j++){
            double x2 = star[j].first;
            double y2 = star[j].second;

            double dist = Distance(x1, y1, x2, y2);
            edge.push_back(make_pair(dist, make_pair(i, j)));
        }
    }

    for(int i = 0; i < n; i++)
        parent[i] = i;

    sort(edge.begin(), edge.end());

    double answer;
    for(int i = 0; i < edge.size(); i++){
        double dist = edge[i].first;
        int start = edge[i].second.first;
        int end = edge[i].second.second;

        if(FindParent(start) != FindParent(end)){
            Merge(start, end);
            answer += dist;
        }
    }
    cout << answer << '\n';
}