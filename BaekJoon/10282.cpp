#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 999999999
using namespace std;

int t; //테스트케이스 수
int n, d, c; // 컴퓨터 수, 의존성 수(경로수), 해킹당한 컴퓨터
int a, b, s; // a,b 컴퓨터, s 시간
int cur, time, nextCur, nextTime;
int comCount, infectTime;
int com[10001];
priority_queue<pair<int, int> > djikQ;

int main(){
    scanf("%d", &t);
    while(t--){
        // 선언 및 초기화
        vector<vector<pair<int, int> > > depend;

        // 입력
        scanf("%d %d %d", &n, &d, &c);

        depend.resize(n+1);

        for(int i = 0; i < d; i++){
            scanf("%d %d %d", &a, &b, &s);
            depend[b].push_back(make_pair(a, s));
        }

        // 배열 초기화
        for(int i = 0; i <= n; i++){
            com[i] = MAX;
        }

        // 다익스트라로 탐색
        djikQ.push(make_pair(0, c));
        com[c] = 0;
        int time;

        while (!djikQ.empty()){
            cur = djikQ.top().second;
            time = -djikQ.top().first;
            djikQ.pop();

            if(time > com[cur])
                continue;

            for(int i = 0; i < depend[cur].size(); i++){
                nextCur = depend[cur][i].first;
                nextTime = depend[cur][i].second + time;

                if(com[nextCur] > nextTime){
                    com[nextCur] = nextTime;
                    djikQ.push(make_pair(-com[nextCur], nextCur));
                }
            }
        }

        // 결과
        comCount = 0,
        infectTime = 0;

        for(int i = 1; i <= n; i++){
            if(com[i] != MAX){
                comCount++;
                infectTime = max(com[i], infectTime);
            }
        }

        printf("%d %d\n", comCount, infectTime);
        
    }
}