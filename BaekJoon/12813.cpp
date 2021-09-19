#include <iostream>
#include <string>
using namespace std;

char a[100000], b[100000];
int main(){
    string A, B;
    cin >> A >> B;

    int len = A.length();

    for(int i = 0; i < len; i++){
        a[i] = A[i] - '0';
        b[i] = B[i] - '0';
    }

    for(int i = 0; i < len; i++)
        printf("%d", a[i] & b[i]);
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("%d", a[i] | b[i]);
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("%d", a[i] ^ b[i]);
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("%d", !a[i]);
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("%d", !b[i]);
    printf("\n");
}