#include <iostream>
#include <math.h>
using namespace std;

void Set_Pixel(int x, int y){
    // x, y 좌표에 색을 칠함
}

void DDA(int x1, int y1, int x2, int y2){
    // x, y축의 증분
    int dx = x2 - x1;
    int dy = y2 - y1;
    // 총 칠해야 할 픽셀의 가로(y의 경우 세로) 길이
    int steps;
    // 시작점 지정
    float x = x1, y = y1;

    float x_incre, y_incre;

    if(fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else 
        steps = fabs(dy);
    
    // step가 하나 증가할 때 x, y 좌표가 얼마나 증가할지 지정해준다
    x_incre = dx / steps;
    y_incre = dy / steps;

    // 시작 좌표 x(=x1), y(=y1)을 칠해준다
    Set_Pixel(round(x), round(y));

    for(int i = 0; i < steps; i++){
        x += x_incre;
        y += y_incre;

        Set_Pixel(round(x), round(y));
    }

}
