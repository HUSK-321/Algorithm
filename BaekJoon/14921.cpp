#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    vector<int> liquid(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &liquid[i]);

    // pointer
    int left  = 0;
    int right = n - 1;
    int result = 2100000000;

    // solution
    while(left < right){
        int liq1 = liquid[left];
        int liq2 = liquid[right];

        if(abs(liq1 + liq2) < abs(result))
            result = liq1 + liq2;
        
        if(liq1 + liq2 < 0)
            left++;
        else 
            right--;
    }

    printf("%d\n", result);
    
}