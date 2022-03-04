#include <vector>
using namespace std;

bool fight[110][110];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    // make input
    for(int i = 0; i < results.size(); i++)
        fight[results[i][0]][results[i][1]] = true;

    // floyid
    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            if(!fight[from][via])   continue;
            for(int to = 1; to <= n; to++){
                if(fight[via][to])
                    fight[from][to] = true;
            }
        }
    }

    // for(int from = 1; from <= n; from++){
    //     for(int via = 1; via <= n; via++){
    //         if(fight[from][via] == false)   continue;

    //         for(int to = 1; to <= n; to++){
    //             if(fight[from][via] && fight[via][to])
    //                 fight[from][to] = true;
    //         }
    //     }
    // }

    // search
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;

            if(fight[i][j] || fight[j][i])
                count++;
        }
        if(count == n-1)
            answer++;
    }

    return answer;
}