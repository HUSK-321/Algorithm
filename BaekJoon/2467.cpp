#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, resL, resR;


int main(){
    scanf("%d", &n);
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    int left = 0;
    int right = n-1;
    int res = 2000000000;

    while(left < right){
        int x = v[left];
        int y = v[right];

        if(abs(x + y) < res){
            res = abs(x + y);
            resL = x;
            resR = y;
        }

        if(x + y < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", resL, resR);
}