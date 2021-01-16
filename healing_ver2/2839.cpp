#include<iostream>
using namespace std;
int main() {
	int N, five, left, result;
	cin >> N;
	five = N / 5; 
	while (five >= 0) {
		left = 0;
		result = 0;
		if (five > 0){
			left = N - 5 * five; 
			result = five;
		}else  // 5키로 봉지가 없는 경우
			left = N;
        
		result += left / 3; 
		left = left % 3;
		
		if (left == 0){
			cout << result;
			break;
		}
        five--; 
	}
	if (left != 0)
		cout << -1;
}