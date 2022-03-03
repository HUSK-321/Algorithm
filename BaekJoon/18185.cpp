#include <iostream>
#include <algorithm>
using namespace std;

int factorys[10003];
int n;
int answer = 0;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> factorys[i];

    // solve
    for(int i = 1; i <= n; i++){
        // 3개 불가능
        if(factorys[i+1] > factorys[i+2]){
            int count = min(factorys[i], factorys[i+1] - factorys[i+2]);
            answer += 5*count;

            factorys[i] -= count;
            factorys[i+1] -= count;

            int count2 = min(factorys[i], min(factorys[i+1], factorys[i+2]));
            answer += 7*count2;

            factorys[i] -= count2;
            factorys[i+1] -= count2;
            factorys[i+2] -= count2;
        } 
        else{ 
            // 3개 가능
            int count = min(factorys[i], min(factorys[i+1], factorys[i+2]));
            answer += 7*count;

            factorys[i] -= count;
            factorys[i+1] -= count;
            factorys[i+2] -= count;

            int count2 = min(factorys[i], factorys[i+1]);
            answer += 5*count2;

            factorys[i] -= count2;
            factorys[i+1] -= count2;
        }
        answer += 3*factorys[i];
        factorys[i] = 0;
    }

    cout << answer << '\n';
}