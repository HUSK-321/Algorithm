#include <iostream>
#include <queue>
using namespace std;

int t;

int main(){
    scanf("%d", &t);
    while (t--){
        long long ans = 0, input;
        int k;
        priority_queue<long long> pq;
        
        scanf("%d", &k);

        for(int i = 0; i < k; i++){
            scanf("%lld", &input);
            pq.push(-input);
        }

        int count = 0;
        while(!pq.empty()){
            if(count == k - 1)
                break;
            
            long long cardA = -pq.top();
            pq.pop();
            long long cardB = -pq.top();
            pq.pop();

            long long newCard = cardA + cardB;
            pq.push(-newCard);
            ans += newCard;
            count++;
        }

        printf("%lld\n", ans);
    }
    
}