#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

ll n, b;

// 요건 행렬의 곱
matrix operator*(const matrix &a, const matrix &b){
    matrix result(n, vector<ll>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

// 요건 행렬의 x제곱
matrix multi(matrix a, ll x){
    matrix result(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        result[i][i] = 1;
    // 단위행렬의 곱으로 하면 된다! 와우!
    while(x > 0){
        if(x%2 == 1){
            result = result * a;
        }
        x /= 2;
        a = a * a;
    }
    return result;
}

void printMatrix(const matrix &input){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << input[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    matrix input(n, vector<ll>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> input[i][j];
        }
    }

    printMatrix(multi(input, b));
}