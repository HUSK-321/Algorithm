#include <iostream>
using namespace std;
int main(){
    long long n;
    scanf("%d", &n);
    long long result = 1;
    for(long long i = n; i >= 1; i--){
        result *= i;
        while(result%10 == 0){
            result /= 10;
        }
        result %= 10000000000000;
    }
    result %= 100000;
    if (result >= 10000)
        printf("%lld\n", result);
    else if (result >= 1000)
        printf("0%lld\n", result);
    else if (result >= 100)
        printf("00%lld\n", result);
    else if (result >= 10)
        printf("000%lld\n", result);
    else
        printf("0000%lld\n", result);
}