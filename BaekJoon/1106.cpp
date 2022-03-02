#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int maxCost = 100001;
int c, n;
int cost[maxCost];
vector<pair<int, int>> hotel;
int main(){
    // init 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        int curCost, curPeople;
        cin >> curCost >> curPeople;
        hotel.push_back(make_pair(curCost, curPeople));
    }

    // solve
    for(int i = 0; i < hotel.size(); i++){
        for(int j = 1; j <= maxCost; j++){
            if(j - hotel[i].first >= 0){
                cost[j] = max(cost[j], cost[j-hotel[i].first] + hotel[i].second);
            }
        }
    }

    for(int i = 1; i <= maxCost; i++){
        if(cost[i] >= c){
            cout << i << '\n';
            return 0;
        }
    }
}