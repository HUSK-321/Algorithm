#include <iostream>
#include <algorithm>
using namespace std;
// 1cm = 10000000 um
// 구멍의 너비, 레고 조각수, 레고 조각의 길이
int x, n, l;
int lego[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    while(cin >> x >> n){
        // input
        for(int i = 0; i < n; i++)
            cin >> lego[i];

        sort(lego, lego + n);

        x *= 10000000;
        
        int left = 0;
        int right = n - 1;
        int temp;

        while(left < right){
            temp = lego[left] + lego[right];

            if(temp > x)
                right--;
            else if(temp < x)
                left++;
            else
                break;
        }
        if(n < 2)
            cout << "danger\n";
        else if(temp == x)
            cout << "yes" << " " << lego[left] << " " << lego[right] << '\n';
        else
            cout << "danger\n";    
    }
}