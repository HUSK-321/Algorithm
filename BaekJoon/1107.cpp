#include <iostream>
#include <cmath>
using namespace std;
bool broken[10];

int Possible(int n){
    // count는 만약 채널을 갈 수 있다면 가능한 채널로 가는데 눌러야 하는 버튼의 수를 저장해줌
    int count = 0;
    if(n == 0) {
        if(!broken[0]) 
            return 1;
        else
            return 0;
    }
    while(n){
        if(broken[n % 10])
            return 0;
        n /= 10;
        count++;
    }
    return count;
}

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < M; i++){
        int j;
        scanf("%d", &j);
        broken[j] = true;
    }

    int a = abs(100-N);
    for(int i = 0; i <= 1000000; i++){
        int count = Possible(i);
        if(count > 0){
            int b = abs(N-i);
            if(a > b + count)
                a = b + count;
        }
    }

    printf("%d", a);
    return 0;
}
