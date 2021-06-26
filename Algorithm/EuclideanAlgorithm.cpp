#include <iostream>
using namespace std;
int gcd(int n, int m){
    int temp;
    while(m){
        temp = n%m;
        n = m;
        m = temp;
    }
    return n;
}