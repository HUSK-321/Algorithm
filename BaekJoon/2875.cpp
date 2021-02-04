#include <iostream>
using namespace std;
int main(){
    int n, m, k; // n여 m남 k인턴(2,1)
    scanf("%d %d %d", &n, &m, &k);
    int people = n + m - k;
    int team = 1;
    while(true){
        int girl = 2 * team;
        int boy = team;
        if(girl > n || boy > m || girl + boy > people)
            break;
        team++;
    }
    printf("%d\n", team - 1);
}