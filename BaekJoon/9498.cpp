#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if(90 <= n){
        printf("A\n");
    } else if(80 <= n){
        printf("B\n");
    } else if(70 <= n){
        printf("C\n");
    } else if(60 <= n){
        printf("D\n");
    } else{
        printf("F\n");
    }
}
