#include <iostream>
using namespace std;
int main(){
    int n, count=1, maze=1;
    cin >> n;
    // 1, 7, 19, 37, 61
    // 증가폭 6, 12, 18
    // N이 1이면 0, 7 안이면 1, 19 안이면 
    if(n==maze){
        cout << count << '\n';
        return 0;
    }
    while(n > maze){
        maze += 6*count;
        count++;
    }
    cout << count << '\n';
}