#include <iostream>
using namespace std;
int main(){
    long long x, y, z;
    cin >> x >> y;
    z = (y * 100) / x;

    if(z >= 99){
        cout << -1 << '\n';
        return 0;
    }

    int left = 0, right = 1000000000, mid;  // 몇번 더 해야 하는지 이분탐색으로 알아본다
    int result, temp;
    while(left <= right){
        mid = (left + right) / 2;

        temp = ((y+mid)*100)/(x+mid);
        if(z >= temp){
            result = mid + 1;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    cout << result << '\n';
    return 0;
}