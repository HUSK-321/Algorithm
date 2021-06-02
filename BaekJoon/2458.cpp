#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res = 0;
int small, big;
int compare[501][501];
int student[501];

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            compare[i][j] = 999999999;
    
    while(m--){
        scanf("%d %d", &small, &big);
        compare[small][big] = 1;
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
            if(i == j)
                continue;
            
            if(compare[i][j] < 999999999){
                student[i]++;
                student[j]++;

                if(student[i] == n-1)
                    res++;
                if(student[j] == n-1)
                    res++;
            }
        }
    }

    printf("%d\n", res);
}