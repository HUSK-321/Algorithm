#include <iostream>
using namespace std;

int list[1000000];

void merge(int arr[], int left, int middle, int right){
    int i, j, k, l;
    i = left;
    j = middle +1;
    k = left;
    // 배열 합병
    while(i <= middle && j <= right){
        if(arr[i] <= arr[j])
            list[k++] = arr[i++];
        else
            list[k++] = arr[j++];
    }
    // 남은 값 복사
    if(i > middle){
        for(l = j; l <= right; l++)
            list[k++] = arr[l];
    }
    else {
        for(l = i; l <= middle; l++)
            list[k++] = arr[l];
    }
    // 인자로 온 배열값 복사
    for(l = left; l <= right; l++)
        arr[l] = list[l];
}

void mergeSort(int arr[],int left,int right){
    int middle;
    if(left < right){
        middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main(void){
	int N;
	cin >> N;
	int arr[N];
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	mergeSort(arr, 0, N-1);
	
	for(int i = 0; i < N; i++)
		cout << arr[i] << '\n';
		
	return 0;
}