#include <iostream>
#include <vector>
using namespace std;

int n, k, s, from, to;
int pre, aft;
int history[401][401];
vector<pair<int, int>> sol;

void History(){
    for(int v = 1; v <= n; v++){
        for(int f = 1; f <= n; f++){
            for(int t = 1; t <= n; t++){
                if(!history[f][t]){
                    if(history[f][v] == 1 && history[v][t] == 1)
                        history[f][t] = 1;
                    else if(history[f][v] == -1 && history[v][t] == -1)
                        history[f][t] = -1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &k);
    while(k--){
        scanf("%d %d", &pre, &aft);
        history[pre][aft] = -1;
        history[aft][pre] = 1;
    }

    scanf("%d", &s);
    while(s--){
        scanf("%d %d", &from, &to);
        sol.push_back(make_pair(from, to));
    }

    History();

    for(int i = 0; i < sol.size(); i++)
        printf("%d\n", history[sol[i].first][sol[i].second]);
}