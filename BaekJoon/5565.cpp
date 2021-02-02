#include <iostream>
using namespace std;
int main(){
    int total = 0;
    int nine = 9;
    scanf("%d", &total);
    while(nine--){
        int book;
        scanf("%d", &book);
        total -= book;
    }
    printf("%d\n", total);
}