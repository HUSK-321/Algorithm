#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int n;
    cin >> n;

    int answer = 0;
    int count = 0;
    int prev = -1;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(prev < input){
            answer = max(answer, count);
            prev = input;
            count = 0;
        }
        else {
            count ++;
        }
    }
    answer = max(answer, count);
    // output
    cout << answer << '\n';
}