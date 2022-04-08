#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

int n, m;
int result = INT32_MAX-1;
int city[51][51];
bool visit[14];
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken;

int ChickenDistance(int houseIndex, int chickenIndex){
    pair<int, int> housePos = houses[houseIndex];
    pair<int, int> chickenPos = chicken[chickenIndex];

    return (abs(housePos.first - chickenPos.first) + abs(housePos.second - chickenPos.second));
}

void SearchChicken(int chickenIndex, int selectCount){
    if(selectCount == m){
        int curResult = 0;

        for(int i = 0; i < houses.size(); i++){
            int curDist = INT32_MAX;
            for(int j = 0; j < chicken.size(); j++){
                if(visit[j]){
                    curDist = min(curDist, ChickenDistance(i, j));
                }
            }
            curResult += curDist;
        }

        result = min(result, curResult);
    }

    if(chickenIndex == chicken.size())
        return;
    
    visit[chickenIndex] = true;
    SearchChicken(chickenIndex + 1, selectCount + 1);
    visit[chickenIndex] = false;
    SearchChicken(chickenIndex + 1, selectCount);
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> city[i][j];

            if(city[i][j] == 1){
                houses.push_back({i, j});
            }
            if(city[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    SearchChicken(0, 0);
    cout << result << '\n';

}