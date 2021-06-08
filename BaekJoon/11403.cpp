#include <iostream>
using namespace std;
int n;
int graph[101][101];

void Floyd(){
    for(int via = 0; via < n; via++){
        for(int from = 0; from < n; from++){
            if(!graph[from][via])
                continue;
            for(int to = 0; to < n; to++){
                if(!graph[via][to])
                    continue;
                
                if(graph[from][via] == 1 && graph[via][to] == 1)
                    graph[from][to] = 1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    Floyd();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}