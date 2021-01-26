#include <iostream>
using namespace std;
int main(){
    int N, X;
    scanf("%d %d", &N, &X);
    
    int a;
    while(N--){
        scanf("%d", &a);
        if(a < X) printf("%d ", a);
    }
}