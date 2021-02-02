#include <iostream>
using namespace std;
int arr[15];
int n;
int result = 0;
bool IsPossible(int index){
    // 행, 열, 대각선이 같은지 확인
    // 열은 배열의 인덱스, 행은 값, 대각선은 기울기가 1
    for(int i = 0; i < index; i++){
        if(arr[i] == arr[index] || index-i == abs(arr[index] - arr[i])){
            return false;
        }
    }
    return true;
}
void Queen(int num){
    if(num == n)    // 완료?
        result++;
    else{
        for(int i = 0; i < n; i++){
            arr[num] = i;  // num열에 i행 위치
            if(IsPossible(num)){
                Queen(num+1);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    Queen(0);
    printf("%d\n", result);
}