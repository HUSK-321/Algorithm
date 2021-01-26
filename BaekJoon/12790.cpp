#include <iostream>
using namespace std;
int main(){
    //전투력 = 1*(HP) + 5*(MP) + 2*(공격력) + 2*(방어력)
    int result, hp, mp, atk, def;
    int e_hp, e_mp, e_atk, e_def;
    int sum_hp, sum_mp, sum_atk, sum_def;
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &atk, &def, &e_hp, &e_mp, &e_atk, &e_def);
        sum_hp = hp + e_hp;
        sum_mp = mp + e_mp;
        sum_atk = atk + e_atk;
        sum_def = def + e_def;
        if(sum_hp < 1)
            sum_hp = 1;
        if(sum_mp < 1)
            sum_mp = 1;
        if(sum_atk < 0)
            sum_atk = 0;
        result = sum_hp + (5*sum_mp) + (2*sum_atk) + (2*sum_def);
        printf("%d\n", result);
    }
}