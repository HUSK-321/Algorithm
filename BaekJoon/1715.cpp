#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, ans;

int main(){
    scanf("%d", &n);

    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        pq.push(-input);
    }
    
    /*
        10, 20, 40이 들어왔을 때 정답은 100이다
        10 20 을 합친 뒤 30 40을 해서 100이 된다고 한다
        여기서 보면 가장 작은 수를 먼저 계산을 한다는 특징이 있다
        만일 4개 이상이라면 계산 결과를 다시 큐에 넣어 계산을 하면 된다
    */

    int count = 0;
    while(!pq.empty()){
        if(count == n - 1)
            break;
        
        int cardA = -pq.top();
        pq.pop();
        int cardB = -pq.top();
        pq.pop();

        int newCard = cardA + cardB;
        pq.push(-newCard);
        ans += newCard;
        count++;
    }
    
    printf("%d\n", ans);

}