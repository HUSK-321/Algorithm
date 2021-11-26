#include <iostream>
using namespace std;

int n;
int edge[100][100];

void FindPathAll(){
    for(int via = 0; via < n; via++){
        for(int from = 0; from < n; from++){
            if(edge[from][via] == 99999)
                continue;

            for(int to = 0; to < n; to++){
                if(edge[via][to] == 99999)
                    continue;
                
                if(edge[from][to] > edge[from][via] + edge[via][to])
                    edge[from][to] = edge[from][via] + edge[via][to];
            }
        }
    }
}


int main(){
    cin >> n;

    // input
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> edge[i][j];

    // Floyd
    FindPathAll();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << edge[i][j] << " ";
        }
        cout << '\n';
    }
}