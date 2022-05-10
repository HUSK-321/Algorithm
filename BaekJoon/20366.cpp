#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> snows;
vector<pair<int, pair<int, int>>> snowmans;

bool Same(const pair<int, int>& a, const pair<int, int>& b){
    if((a.first != b.first) && (a.first != b.second) && (a.second != b.first) && (a.second != b.second))
        return false;
    return true;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    snows.resize(n);
    for(int i = 0; i < n; i++){
        cin >> snows[i];
    }

    // make all snowmans
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            snowmans.push_back({snows[i] + snows[j], {i, j}});
        }
    }

    // solution
    int answer = static_cast<int>(10e9);
    sort(snowmans.begin(), snowmans.end());
    for(int i = 0; i < snowmans.size()-1; i++){
        for(int j = i+1; j < snowmans.size(); j++){
            if(Same(snowmans[i].second, snowmans[j].second))    continue;

            answer = min(answer, snowmans[j].first - snowmans[i].first);
            break;
        }
    }

    cout << answer << '\n';
}