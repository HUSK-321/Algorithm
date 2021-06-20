#include <iostream>
#include <cstring>
using namespace std;

int t, n, res;
int student[100001];
bool visit[100001];
bool isOnCycle[100001];

void DFS(int studentNum){
    visit[studentNum] = true;

    int nextStudent = student[studentNum];

    if(!visit[nextStudent])
        DFS(nextStudent);
    else if(!isOnCycle[nextStudent]){
        for(int i = nextStudent; i != studentNum; i = student[i])
            res++;
        res++;
    }

    isOnCycle[studentNum] = true;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &student[i]);

        res = 0;
        memset(visit, false, sizeof(visit));
        memset(isOnCycle, false, sizeof(isOnCycle));
        for(int i = 1; i <= n; i++){
            if(!visit[i])
                DFS(i);
        }
        printf("%d\n", n - res);
    }
}