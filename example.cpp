#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A{
public:
    A(const int& a){
        cout << "normal constructor\n";
    }

    A(const int&& a){
        cout << "move constructor\n";
    }
};

int main(){
    int x = 1;
    int y{ move(x) };

    cout << x << " , " << y << '\n';
}