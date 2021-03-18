#include <iostream>
#include <algorithm>
using namespace std;

int n, res = 0;
// 시작은 둘다 맨 오른쪽
int x, y, l, r;
int main(){
    scanf("%d", &n);
    n -= 1;

    scanf("%d %d", &l, &r);

    while(n--){
        scanf("%d %d", &x, &y);
        if (x > r) {    // 겹치지 않는 새 선분
            res += r - l;
            l = x;
            r = y;
        } else if (r < y){  // 연장
            r = y;
        }
    }
    res += r - l;
    printf("%d\n", res);
}