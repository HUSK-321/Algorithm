#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m1, m2, m3, m4;
    int h1, h2, h3, h4;
    scanf("%d %d %d %d", &m1, &m2, &m3, &m4);
    scanf("%d %d %d %d", &h1, &h2, &h3, &h4);
    int result = max((m1 + m2 + m3 + m4), (h1 + h2 + h3 + h4));
    printf("%d\n", result);
}