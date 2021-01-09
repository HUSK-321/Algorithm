#include <iostream>
int main(){
    long long T;
    scanf("%lld", &T);
    while(T--) {
        long long start, end, distance, level, count = 1;      // start < end

        scanf("%lld%lld", &start, &end);
        distance = end - start;
        // count는 최대 워프 거리
        while(count * count <= distance){
            count++;
        }
        count--;
        // 1 2 1 = 4 - 3 / 1 2 3 2 1 = 9 - 5 / 1234321 = 16 - 7 / 123454321 = 25 - 8
        // 최대 워프 거리가 i 면 횟수는? 
        long long etc = distance - (count * count);
        level = (2 * count) -1;

        if(etc == 0){               // 더 가야할게 없다, 완벽한 제곱근
            
        } else if(1 <= etc <= count) {    // i ~ 1
            count += 1;
        } else if(count+1 < etc < 2*count){                         // 2i ~ i+1
            count +=2;
        }
        printf("%lld\n", count);
    }
}