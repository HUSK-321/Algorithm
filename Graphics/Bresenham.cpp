#include <iostream>
#include <math.h>
using namespace std;


void Set_Pixel(int x, int y){
    // x, y 좌표에 색을 칠함
}

void Bres (int x0, int y0, int xEnd, int yEnd)
{
	int dx = fabs (xEnd - x0), dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    int x, y;
    
	// 어디가 왼쪽이고 오른쪽인지
	if (x0 > xEnd) {
      x = xEnd;
      y = yEnd;
      xEnd = x0;
	}
	else {
		x = x0;
		y = y0; 
	}

 	Set_Pixel (x, y);
  	while (x < xEnd) {
		x++;
    	if (p < 0)
			p += twoDy;
		else { 
			y++;
      		p += twoDyMinusDx;
    	}
    Set_Pixel (x, y);
	}
}
int main(){

}