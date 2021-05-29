#include <iostream>
using namespace std;

int n; // 노드 수
int road[100][100];

void FloydWarshall(){
    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            if(!road[from][via])
                continue;
            for(int to = 1; to <= n; to++){
                if(!road[to][via])
                    continue;
                
                if(road[from][to] > road[from][via] + road[via][to])
                    road[from][to] = road[from][via] + road[via][to];
            }
        }
    }
}