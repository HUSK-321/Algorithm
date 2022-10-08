#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a, b, c;
bool visit[201][201][201];
queue<pair<pair<int, int>, int>> q;
vector<int> cCapacityLog;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> a >> b >> c;

    q.push({{0, 0}, c});
    while (!q.empty()){
        int curA = q.front().first.first;
        int curB = q.front().first.second;
        int curC = q.front().second;
        q.pop();

        if(visit[curA][curB][curC]) continue;
        visit[curA][curB][curC] = true;

        if(curA == 0)
            cCapacityLog.push_back(curC);
        
        // a -> b
        if(curA + curB > b)
            q.push({{curA + curB - b, b}, curC});
        else
            q.push({{0, curA + curB}, curC});
        // a -> c
        if(curA + curC > c)
            q.push({{curA + curC - c, curB}, c});
        else
            q.push({{0, curB}, curA + curC});
        
        // b -> a
        if(curB + curA > a)
            q.push({{a, curB + curA - a}, curC});
        else   
            q.push({{curB + curA, 0}, curC});
        // b -> c
        if(curB + curC > c)
            q.push({{curA, curB + curC - c}, c});
        else
            q.push({{curA, 0}, curB + curC});

        // c -> a
        if(curC + curA > a)
            q.push({{a, curB}, curC + curA - a});
        else   
            q.push({{curC + curA, curB}, 0});
        // c -> b
        if(curC + curB > b)
            q.push({{curA, b}, curC + curB - b});
        else   
            q.push({{curA, curC + curB}, 0});   
    }

    sort(cCapacityLog.begin(), cCapacityLog.end());
    for(int i = 0; i < cCapacityLog.size(); i++){
        cout << cCapacityLog[i] << " ";
    }
    
}