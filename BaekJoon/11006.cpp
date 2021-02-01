#include <iostream>
using namespace std;
int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d %d\n", m - (n - m), n - m);
    }
}