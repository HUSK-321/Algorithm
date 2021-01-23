#include <iostream>
using namespace std;
/*
int gcd(int n, int m){
    if(m == 0)
        return n;
    else
        return gcd(m, n%m);     
}*/
int gcd(int n, int m){
    int temp;
    while(m){
        temp = n%m;
        n = m;
        m = temp;
    }
    return n;
}
int main(){
    int t, a, b;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &a, &b);
        int c = gcd(a, b);
        printf("%d\n", a*b/c);
    }
}