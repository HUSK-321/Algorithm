#include <iostream>
using namespace std;



struct DATA
{
    public:
        int damage;
        int count;
};


void BubbleSort(DATA* arr, int n){
    DATA temp;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i].damage < arr[j].damage){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if(arr[i].damage == arr[j].damage){
                if(arr[i].count < arr[j].count){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

int main(){
    DATA input[2001];
    int enemyHp;
    int howManyWeapon;

    cin >> enemyHp;
    cin >> howManyWeapon;

    for(int i = 0; i < howManyWeapon; i++){
        cin >> input[i].damage >> input[i].count;
    }

    BubbleSort(input, howManyWeapon);

    int res = 0;

    for(int i = 0; i < howManyWeapon; i++){
        while(input[i].count--){
            if(enemyHp <= 0)
                break;

            enemyHp -= input[i].damage;
            res++;
        }
        if(enemyHp <= 0)
                break;
    }
    cout << res;
}