#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NODE = 11;
const int MAX = 999999999;

int costs[NODE][NODE];
bool visit[NODE];
int planetNumber, StartPlanet;
int answer = MAX;

void Launch(int curPos, int visitCount, int curCost){
    if(curCost > answer)    return;

    if(visitCount == planetNumber-1){
        answer = min(answer, curCost);
        return;
    }

    for(int i = 0; i < planetNumber; i++){
        if(!visit[i]){
            visit[i] = true;
            Launch(i, visitCount + 1, curCost + costs[curPos][i]);
            visit[i] = false;
        }
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(visit, false, sizeof(visit));
    
    // input;
    cin >> planetNumber >> StartPlanet;
    for(int i = 0; i < planetNumber; i++){
        for(int j = 0; j < planetNumber; j++){
            cin >> costs[i][j];
        }
    }

    // floyid
    for(int via = 0; via < planetNumber; via++){
        for(int from = 0; from < planetNumber; from++){
            for(int to = 0; to < planetNumber; to++){
                if(costs[from][to] > costs[from][via] + costs[via][to])
                    costs[from][to] = costs[from][via] + costs[via][to];
            }
        }
    }

    // Search
    visit[StartPlanet] = true;
    Launch(StartPlanet, 0, 0);

    cout << answer << '\n';
}