#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int t, a, b, cur, nextNum;
queue<char> q;
bool visit[100001];

string bfs(){
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visit[a] = true;

    while(!q.empty()){
        int cur = q.front().first;
        string s = q.front().second;
        q.pop();

        if(cur == b)
            return s;
        
        // D : 2n mod 10000
        nextNum = (2 * cur) % 10000;
        if(!visit[nextNum]){
            visit[nextNum] = true;
            q.push(make_pair(nextNum, s + "D"));
        }
        // S : n -1 (n=0이라면 9999)
        nextNum = (cur-1) < 0 ? 9999 : cur-1;
        if(!visit[nextNum]){
            visit[nextNum] = true;
            q.push(make_pair(nextNum, s + "S"));
        }
        // L : 각 자리수 왼쪽으로   1234  2341
        nextNum = (cur % 1000) * 10 + (cur / 1000);
        if(!visit[nextNum]){
            visit[nextNum] = true;
            q.push(make_pair(nextNum, s + "L"));
        }
        // R : 각 자리수 오른쪽으로   1234  4123
        nextNum = (cur / 10) + ((cur%10) * 1000);
        if(!visit[nextNum]){
            visit[nextNum] = true;
            q.push(make_pair(nextNum, s + "R"));
        }
    }
}

int main(){
    scanf("%d", &t);

    while(t--){
        memset(visit, false, sizeof(visit));
        scanf("%d %d", &a, &b);
        cout << bfs() << '\n';
    }
}