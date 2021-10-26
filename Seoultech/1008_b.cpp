#include <iostream>
using namespace std;
int time[1000000000];
int main(){
    int n, s, e;
    cin >> n;
    int answer = 0;

    for(int i = 0; i < n; i++){
        cin >> s >> e;

        for(int j = s; j < e; j++)
            time[j]++;
    }

    for(int i = 0; i < 1000000000; i++)
        if(answer < time[i]) answer = time[i];
    
    cout << answer;
}