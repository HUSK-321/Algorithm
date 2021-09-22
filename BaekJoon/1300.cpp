#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    int left = 1, right = k, res = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        int count = 0;
        for(int i = 1; i <= n; i++)
            count += min(mid/i, n);
        
        if(count < k){
            left = mid + 1;
        }
        else {
            right = mid - 1;
            res = mid;
        }
    }

    cout << res << '\n';
}