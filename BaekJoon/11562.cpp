#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int k;
int route[251][251];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            route[i][j] = 999999999;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v, b;    cin >> u >> v >> b;
        route[u][v] = 0;
        route[v][u] = 1;
        if(b == 1)
           route[v][u] = 0;

    }

    // floyid
    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                if(from == to) route[from][to] = 0;

                route[from][to] = min(route[from][to], route[from][via] + route[via][to]);
            }
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++){
        int s, e;
        cin >> s >> e;

        cout << route[s][e] << '\n';
    }
}