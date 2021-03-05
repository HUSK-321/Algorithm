#include <iostream>
#include <queue>
using namespace std;
int n, input;
priority_queue<int> q;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n*n; i++){
        scanf("%d", &input);

        q.push(-input);
        if(q.size() > n)
            q.pop();
    }

    printf("%d", -q.top());
}