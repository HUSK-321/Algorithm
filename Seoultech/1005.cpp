#include <iostream>
using namespace std;
//힙정렬
int n, heap[10000001];

void MakeHeap(int i) {
// 부모 > 자식 의 구조로 만드는 과정
// i가 부모이고 cur(현재 가리키는 인덱스)은 i의 왼 자식
// 왼쪽 오른쪽을 비교한 뒤 더 큰걸 선택
// 부모와 제일 큰 자식을 비교
// 만약 부모가 교체되고 cur <= n/2 현재 가리키는 인덱스가 말단이 아니면 재귀
// 재귀를 하는 이유는 바뀐 노드랑 형제간 비교를 하기 위해
	int cur = 2 * i;

	if(cur < n && heap[cur] < heap[cur+1]) cur++;

	if(heap[i] < heap[cur]) {
		swap(heap[i],heap[cur]);
		if(cur <= n/2) MakeHeap(cur);
	}
}

void HeapSort(int i) {
// cur가 말단을 가리키는게 아니라면 while문 시작
// 루트~자식이 있는 노드까지 계속 반복
// 한번 과정을 거치면 i(말단)은 제일 큰 값이 되고 그 다음으로 큰게 루트가 된다
// 그러니 다음 과정에서 루트를 i-1(for문에서 조정함)과 바꾸면 제일 큰수가 뒤로 가게 되는 구조
	swap(heap[1],heap[i]);

	int root = 1;
	int cur = 2;

	while(cur/2<i) {
		cur = 2*root;
		if(cur < i-1 && heap[cur] < heap[cur+1])
            cur++;
		if(cur < i && heap[root] < heap[cur])
			swap(heap[root],heap[cur]);

		root = cur;
	}
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&heap[i]);
	
	for(int i = n/2; i > 0; i--) // 최초 heap 생성
		MakeHeap(i);
	for(int i = n; i > 0; i--) // heap 정렬
		HeapSort(i);

	for(int j = 1; j <= n; j++) // 출력
		printf("%d\n",heap[j]);
}