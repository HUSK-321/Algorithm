#include <iostream>
#include <algorithm>
#define MAX 999999999
using namespace std;

int n, m, winner, loser, res = 0;
int compare[101][101];
int cow[101];

int main(){
    scanf("%d %d", &n ,& m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            compare[i][j] = MAX;
    
    while(m--){
        scanf("%d %d", &winner, &loser);
        compare[winner][loser] = 1;
    }

    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                compare[from][to] = min(compare[from][to], compare[from][via] + compare[via][to]);
            }
        }
    }
    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(compare[i][j] < MAX){
                cow[i]++;
                cow[j]++;

                if(cow[i] == n-1)
                    res++;
                if(cow[j] == n-1)
                    res++;
            }
                
        }
    }

    printf("%d\n", res);
}