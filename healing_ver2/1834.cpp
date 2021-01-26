#include <iostream>
using namespace std;
int main(){
    long long n;
    long long result = 0;
    scanf("%lld", &n);
    for(int i = 1; i < n; i++){
        result += (i*n) + i;
    }
    printf("%lld\n", result);
}