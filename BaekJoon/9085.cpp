#include <iostream>
using namespace std;
int main(){
    int t, n, a;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        int sum = 0;
        while (n--){
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
    }
}