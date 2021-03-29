#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001];
int k, n;
long long mid, h = 0, l = 1, res = 0;

bool Check(long long input){
    // 랜선을 정해진 수만큼 만들 수 있냐
    int count = 0;
    for(int i = 0; i < k; i++)
        count += arr[i] / input;

    if(count >= n)
        return true;
    
    return false;
}

int main(){
    scanf("%d %d", &k, &n);

    for(int i = 0; i < k; i++){
        scanf("%lld", &arr[i]);
        h = max(h, arr[i]);
    }
    
    while(l <= h){
        mid = (l + h) / 2;
        if(Check(mid)) {
            res = max(res, mid);
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    printf("%lld\n", res);
}