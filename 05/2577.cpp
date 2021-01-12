#include <iostream>
using namespace std;
int main(){
    int numbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int A, B, C;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    int n = A*B*C;
    int a;
    while(n > 0){
        a = n%10;
        numbers[a]++;
        n = n/10;
    }

    for(int i = 0; i < 10; i++)
        printf("%d\n", numbers[i]);
}