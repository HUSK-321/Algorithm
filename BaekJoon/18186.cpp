#include <iostream>
#include <algorithm>
using namespace std;

long long factorys[1000003];
long long n, b, c;
long long answer = 0;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> b >> c;
    for(int i = 1; i <= n; i++)
        cin >> factorys[i];

    // solve
    // select b is better choice
    if(b < c){
        for(int i = 1; i <= n; i++)
            answer+= factorys[i];
        cout << answer*b << '\n';
        return 0;
    }

    for(int i = 1; i <= n; i++){
        // 3개 불가능
        if(factorys[i+1] > factorys[i+2]){
            long long count = min(factorys[i], factorys[i+1] - factorys[i+2]);
            answer += (b+c)*count;

            factorys[i] -= count;
            factorys[i+1] -= count;

            long long count2 = min(factorys[i], min(factorys[i+1], factorys[i+2]));
            answer += (b+2*c)*count2;

            factorys[i] -= count2;
            factorys[i+1] -= count2;
            factorys[i+2] -= count2;
        } 
        else{ 
            // 3개 가능
            long long count = min(factorys[i], min(factorys[i+1], factorys[i+2]));
            answer += (b+2*c)*count;

            factorys[i] -= count;
            factorys[i+1] -= count;
            factorys[i+2] -= count;

            long long count2 = min(factorys[i], factorys[i+1]);
            answer += (b+c)*count2;

            factorys[i] -= count2;
            factorys[i+1] -= count2;
        }
        answer += b*factorys[i];
        factorys[i] = 0;
    }

    cout << answer << '\n';
}

/*
b, b+c, b+2c

b < c 라면?
*/