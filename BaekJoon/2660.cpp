#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, score, num, minnium;
int vote[51][51];
int result[51];

int main(){

    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            vote[i][j] = 999999999;
        }
    }

    while(true){
        int from, to;
        scanf("%d %d", &from, &to);

        if(from == -1 || to == -1)
            break;

        vote[from][to] = 1;
        vote[to][from] = 1;
    }
    
    for(int via = 1; via <= n; via++){
        for(int to = 1; to <= n; to++){
            for(int from = 1; from <= n; from++){
                vote[from][to] = min(vote[from][to], vote[from][via] + vote[via][to]);
            }
        }
    }

    minnium = 10000;

    for(int i = 1; i <= n; i++){
        result[i] = 0;
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            result[i] = max(result[i], vote[i][j]);
        }
        minnium = min(result[i], minnium);
        score = minnium;
    }

    num = 0;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(result[i] == score){
            v.push_back(i);
            num++;
        }
    }

    printf("%d %d\n", score, num);
    for(int i = 0; i < num; i++)
        printf("%d ", v[i]);

}   