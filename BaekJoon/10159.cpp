#include <iostream>
using namespace std;

int n, m;
int heavy, light;
int thing[101][101];
int main(){
    scanf("%d", &n);
    scanf("%d", &m);

    while(m--){
        scanf("%d %d", &heavy, &light);
        thing[heavy][light] = 1;
        thing[light][heavy] = -1;
    }

    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            if(!thing[from][via])
                continue;

            for(int to = 1; to <= n; to++){
                if(!thing[via][to])
                    continue;
                
                if(thing[from][via] == thing[via][to])
                    thing[from][to] = thing[from][via];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int count = n - 1;
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            if(thing[i][j] != 0)
                count--;
        }
        printf("%d\n", count);
    }

}