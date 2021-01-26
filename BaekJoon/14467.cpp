#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;

    int cow[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int count = 0;
    while(N--){
        int num, move;
        cin >> num >> move;
        if(cow[num] == -1){ // 처음 보는 소다
            cow[num] = move;
        } else if(cow[num] != move && cow[num] != -1){ // 심상치 않은 놈이다
            cow[num] = move;
            count++;
        }
        // 만약 한번 나왔던 놈인데 이전과 같은 move라면
        // 대입도 안하고 ++도 안하니 할 일이 없다
    }
    cout << count << '\n';
    return 0;
}
