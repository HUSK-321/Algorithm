#include <iostream>
using namespace std;
 
int main(){
	long long n;
	cin >> n;
	
	if (n % 7 == 0 || n % 7 == 2)
		cout << "CY" << '\n';
	else
		cout << "SK" << '\n';
}