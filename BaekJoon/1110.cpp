#include <iostream>
using namespace std;
int main(){
    int input, one, sum, count = 0;
    scanf("%d", &input);
    int next = input;
    do{
        one = next%10;
        sum = ((next/10) + one) % 10;
        next = one*10 + sum;
        count++;
    }while(next != input);
    printf("%d\n", count);
    return 0;
}
