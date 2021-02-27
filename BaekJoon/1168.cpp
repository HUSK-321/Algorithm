#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    // 위키피셜 : f(1,k) = 1
    // f(n,k) = (f(n-1, k) + k - 1) mod n  + 1
    // n = n+1 이라면
    // f(n=1, k) = (f(n,k) + k - 1) mod (n+1) + 1
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    // 위키식대로 점화식은 안되지만 첫 사람 수를 p로 두고 mod 연산으 해주면 원형에서와 같은 연산 가능
    // kill이 지금 죽여야 하는 사람의 인덱스라고 하면 k를 더한 뒤 mod 연산
    // 찾아보니 erase를 사용하면 굉장히 빠르다고 한다!
    int kill = -1;
    int p = n;
    printf("<");
    for(int i = 1; i <= n; i++){
        kill = (kill+k) % p;
        printf("%d", v[kill]);
        v.erase(v.begin() + kill); // erase : 빠르다!
        // 사람 수 줄어든것 반영
        kill--;
        p--;

        if(i==n)    // 마지막
            printf(">");
        else        // 남아있음
            printf(", ");
    }
    
    
}