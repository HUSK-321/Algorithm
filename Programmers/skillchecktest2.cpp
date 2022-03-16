#include <string>
#include <vector>
#include <algorithm>
#include <map>
// 실패율 문제
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<double, int>> level;
    map<int, double> m;
    for(int i = 0; i < stages.size(); i++){
        m[stages[i]]++;
    }

    int lose = 0;
    for(int i = 1; i <= N; i++){
        if(m[i] == 0){
            level.push_back({0, i});
            continue;
        }

        level.push_back({m[i]/stages.size()-lose, i});
        lose += m[i];
    }

    sort(level.begin(), level.end(), cmp);

    for(int i = 0; i < level.size(); i++){
        answer.push_back(level[i].second);
    }
    return answer;
}