#include <iostream>
using namespace std;
int main(){
    int N, count = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        int now;
        cin >> now;
        count += (now-1);
    }
    cout << count << '\n';

}