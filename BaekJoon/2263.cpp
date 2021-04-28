#include <iostream>
#define max 100001

using namespace std;
int n;
int temp[max], inOrder[max], postOrder[max];

void PreOrder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd)
        return;
    // Pre는 Root Letf Right 순
    printf("%d ", postOrder[postEnd]);
    // in에서 root가 어디인지 찾기
    int r = temp[postOrder[postEnd]];
    // 먼저 왼쪽
    // r-inStart는 트리에서 왼쪽 자식들을 의미
    PreOrder(inStart, r-1, postStart, postStart+r-inStart-1);
    // 그 다음 오른쪽
    PreOrder(r+1, inEnd, postStart+r-inStart, postEnd-1);
}

int main(){
    scanf("%d", &n);
    // in-order
    for (int i = 0; i < n; i++)
        scanf("%d", &inOrder[i]);
    // post-order
    for (int i = 0; i < n; i++)
        scanf("%d", &postOrder[i]);
    // inOrder의 값이 어느 인덱스인지 저장
    for (int i = 0; i < n; i++)
        temp[inOrder[i]] = i;

    PreOrder(0, n-1, 0, n-1);
}