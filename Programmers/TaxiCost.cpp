#include <string>
#include <vector>
#include <algorithm>

const int MAX = 999999999;
long long costs[201][201];
using namespace std;

void MakePath(int n){
    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                if(costs[from][to] > costs[from][via] + costs[via][to]){
                    costs[from][to] = costs[from][via] + costs[via][to];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;

    // init cost array
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == j)  continue;
            costs[i][j] = MAX;
        }  
    }
        

    // make edges array
    for(int i = 0; i < fares.size(); i++){
        int posA = fares[i][0];
        int posB = fares[i][1];
        int cost = fares[i][2];

        costs[posA][posB] = cost;
        costs[posB][posA] = cost;
    }

    // find all route
    MakePath(n);

    // find min cost
    for(int i = 1; i <= n; i++){
        long long curCost = costs[s][i] + costs[i][a] + costs[i][b];
        if(curCost < answer)
            answer = curCost;
    }

    return answer;
}