#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // 집하장의 수, 경로 수
int from, to, cost;
int edge[201][201];
int map[201][201];


void Floyd(){
    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                if(edge[from][to] > edge[from][via] + edge[via][to]){
                    edge[from][to] = edge[from][via] + edge[via][to];
                    map[from][to] = map[from][via];
                }
            }
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> cost;

        edge[from][to] = cost;
        edge[to][from] = cost;

        map[from][to] = to;
        map[to][from] = from;
    }

    for(int i = 1; i <= n; i++){
        edge[i][i] = 0;
        map[i][i] = i;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i==j) 
                continue;
            if(!edge[i][j]) 
                edge[i][j] = 999999999;
        }
    }


    Floyd();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                cout << "- ";
            else
                cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}