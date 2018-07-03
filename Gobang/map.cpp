#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>

static const int MapLengh = 600;
static const int OrinPoint = 50;
static const int ArrayLengh = (MapLengh - OrinPoint*2) / 50+1;
static int Topo[ArrayLengh][ArrayLengh] = { 0 };
static enum {
	White = 1,
	Black = 2
};

void InitMap();
void DrawChess(int x, int y,int color);
bool WinOrNot(int sign);
int JudgeZero(int O, int add);
int AiChesser(int sign, int *nx, int *ny);
bool JudgeFull();

void main() {
	InitMap();
	
	MOUSEMSG m;
	while (1) {
		m = GetMouseMsg();
		int x, y;
		switch (m.uMsg){
		    case WM_LBUTTONUP:
				x = (int)((m.x - OrinPoint) / 50.0 + 0.5);
				y = (int)((m.y - OrinPoint) / 50.0 + 0.5);
			    if (Topo[x][y] ==0) {
				    Topo[x][y] = White;
				    DrawChess(x, y, White);
					
					if (WinOrNot(White)) {
						TCHAR s[] =_T( "YOU WIN!");
						setfillcolor(RGB(220, 20, 60));
						fillcircle(MapLengh / 2, MapLengh / 2, MapLengh );
						settextstyle(50, 50, _T("ËÎÌå"));
						settextcolor(BLUE);		
						setbkmode(TRANSPARENT);		
						outtextxy(MapLengh / 2-180, MapLengh / 2-50, s);
					}else {
						int next_x = -1;
						int next_y = -1;
						AiChesser(White, &next_x, &next_y);
						Topo[next_x][next_y] = Black;
						DrawChess(next_x, next_y, Black%2);
						if (WinOrNot(Black)) {
							TCHAR s[] = _T("YOU DIE!");
							setfillcolor(RGB(0, 0, 0));
							fillcircle(MapLengh / 2, MapLengh / 2, MapLengh);
							settextstyle(50, 50, _T("ËÎÌå"));
							settextcolor(BLUE);
							setbkmode(TRANSPARENT);
							outtextxy(MapLengh / 2 - 180, MapLengh / 2 - 50, s);
						}
						if (JudgeFull()) {
							TCHAR s[] = _T("NO SPACE!");
							setfillcolor(YELLOW);
							fillcircle(MapLengh / 2, MapLengh / 2, MapLengh);
							settextstyle(50, 50, _T("ËÎÌå"));
							settextcolor(BLUE);
							setbkmode(TRANSPARENT);
							outtextxy(MapLengh / 2 - 180, MapLengh / 2 - 50, s);
						}
					}
			    }
			    break;
		    default:
				break;
		}
	}
	closegraph();
}

void DrawChess(int x, int y,int color) {
	x *= 50;
	y *= 50;

	x += OrinPoint;
	y += OrinPoint;
	setfillcolor(RGB(255*color,255*color,255*color));
	setlinecolor(RGB(255- 255 * color, 255 - 255 * color, 255 - 255 * color));
	setlinestyle(PS_SOLID, 4);
	fillcircle(x, y, 20);
}

void InitMap() {
	//±³¾°
	initgraph(MapLengh,MapLengh);
	setbkcolor(RGB(255, 165, 0));
	cleardevice();

	//»­Íø¸ñ
	setlinecolor(RGB(0, 0, 0));
	setlinestyle(PS_SOLID, 8);
	for (int i = 0,j=MapLengh-2*OrinPoint,k=OrinPoint; i < 2; i++) {
		line(k, k + i * j, k+j, k + i * j);
		line(k + i * j, k, k + i * j, k+j);
	}
	setlinestyle(PS_SOLID, 4);
	for (int i = 1, j = MapLengh - 2 * OrinPoint, k = OrinPoint; i < ArrayLengh - 1; i++) {
		line(k, k + i * 50, k + j, k + i * 50);
		line(k + i * 50, k, k + i * 50, k + j);
	}
}

bool WinOrNot(int sign) {
	for (int i = 0; i < ArrayLengh;i++) {
		int sum1 = 0;
		int sum2 = 0;
		for (int j = 0; j < ArrayLengh; j++) {
			if (sign == Topo[i][j]) {
				sum1++;
				if (sum1 == 5) {
					return true;
				}
			}else {
				sum1 = 0;
			}

			if (sign == Topo[j][i]) {
				sum2++;
				if (sum2 == 5) {
					return true;
				}
			}
			else {
				sum2 = 0;
			}
		}
		sum1 = 0;
		sum2 = 0;
		for (int j = ArrayLengh-1; j >=0; j--) {
			if (sign == Topo[i][j]) {
				sum1++;
				if (sum1 == 5) {
					return true;
				}
			}
			else {
				sum1 = 0;
			}

			if (sign == Topo[j][i]) {
				sum2++;
				if (sum2 == 5) {
					return true;
				}
			}
			else {
				sum2 = 0;
			}
		}
	}

	for (int i = 0; i < ArrayLengh; i++) {
		int sum = 0;
		for (int j = 0,k=i; j < ArrayLengh&&k<ArrayLengh; j++,k++)
		{
			if (sign == Topo[k][j]) {
				sum++;
				if (sum == 5) {
					return true;
				}
			}
			else {
				sum = 0;
			}
		}
		sum = 0;
		for (int j = 0, k = i; j < ArrayLengh&&k >=0; j++, k--) {
			if (sign == Topo[k][j]) {
				sum++;
				if (sum == 5) {
					return true;
				}
			}
			else {
				sum = 0;
			}
		}
		sum = 0;
		for (int j = ArrayLengh-1, k = i; j >=0&&k >= 0; j--, k--) {
			if (sign == Topo[k][j]) {
				sum++;
				if (sum == 5) {
					return true;
				}
			}
			else {
				sum = 0;
			}
		}
		sum = 0;
		for (int j = ArrayLengh-1, k = i; j < ArrayLengh&&k<ArrayLengh; j--, k++)
		{
			if (sign == Topo[k][j]) {
				sum++;
				if (sum == 5) {
					return true;
				}
			}
			else {
				sum = 0;
			}
		}
	}
	return false;
}

int JudgeZero(int n, int add) {
	if (n == 0) {
		return add*add;
	}
	return 0;
}

int knn(int sum,int x1,int x2) {
	int n = 0;
	if (x1 == 0) {
		n++;
	}
	if (x2 == 0) {
		n++;
	}

	if (sum > 1 && n > 0) {
		sum += n;
		sum += sum / 4;
	}
	else {
		sum = 1;
	}
	return sum;
}

int AiChesser(int sign,int *nx,int *ny) {
	int map[ArrayLengh][ArrayLengh] = { 0 };

	for (int i = 0; i < ArrayLengh; i++) {

		for (int j = 0,k=i,x=i,y=0,sum=0; j < ArrayLengh&&k<ArrayLengh; j++,k++) {
			if (sign == Topo[k][j]) {
				sum++;
			}
			else {
				if (sum > 0) {
					sum=knn(sum, Topo[x][y], Topo[k][j]);
					map[x][y] += JudgeZero(Topo[x][y], sum);
					map[k][j] += JudgeZero(Topo[k][j], sum);
				}

				x = k;
				y = j;
				sum = 0;
			}
		}

		for (int j = 0, k = i, x = i, y = 0, sum = 0; j < ArrayLengh&&k >= 0; j++, k--) {
			if (sign == Topo[k][j]) {
				sum++;
			}
			else {
				if (sum > 0) {
					sum = knn(sum, Topo[x][y], Topo[k][j]);
					map[x][y] += JudgeZero(Topo[x][y], sum);
					map[k][j] += JudgeZero(Topo[k][j], sum);
				}
				x = k;
				y = j;
				sum = 0;
			}
		}

		for (int j = ArrayLengh-1, k = i, x = i, y = ArrayLengh - 1, sum = 0; j >=0&&k >= 0; j--, k--) {
			if (sign == Topo[k][j]) {
				sum++;
			}
			else {
				if (sum > 0) {
					sum = knn(sum, Topo[x][y], Topo[k][j]);
					map[x][y] += JudgeZero(Topo[x][y], sum);
					map[k][j] += JudgeZero(Topo[k][j], sum);
				}
				x = k;
				y = j;
				sum = 0;
			}
		}

		for (int j = ArrayLengh-1, k = i, x = i, y = ArrayLengh - 1, sum = 0; j >=0&&k<ArrayLengh; j--, k++) {
			if (sign == Topo[k][j]) {
				sum++;
			}
			else {
				if (sum > 0) {
					sum = knn(sum, Topo[x][y], Topo[k][j]);
					map[x][y] += JudgeZero(Topo[x][y], sum);
					map[k][j] += JudgeZero(Topo[k][j], sum);
				}
				x = k;
				y = j;
				sum = 0;
			}
		}

		for (int j = 0,sum=0,x=i,y=0; j < ArrayLengh; j++) {
			if (sign == Topo[i][j]) {
				sum++;
			}
			else {
				if (sum > 0) {
					sum = knn(sum, Topo[x][y], Topo[i][j]);
					map[x][y] += JudgeZero(Topo[x][y], sum);
					map[i][j] += JudgeZero(Topo[i][j], sum);
				}
				x = i;
				y = j;
				sum = 0;
			}
		}

		for (int j = 0, sum = 0, x = 0, y = i; j < ArrayLengh; j++) {
			if (sign == Topo[j][i]) {
				sum++;
			}
			else {
				if (sum > 0) {
					sum = knn(sum, Topo[x][y], Topo[j][i]);
					map[x][y] += JudgeZero(Topo[x][y], sum);
					map[j][i] += JudgeZero(Topo[j][i], sum);
				}
				x = j;
				y = i;
				sum = 0;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < ArrayLengh; i++){
		for (int j = 0; j < ArrayLengh; j++) {
			if (max < map[i][j]) {
				max = map[i][j];
				*nx = i;
				*ny = j;
			}
		}
	}
	int bx = -1;
	int by = -1;
	if (sign==White&&max <= AiChesser(Black, &bx, &by)) {
		*nx = bx;
		*ny = by;
	}
	return max;

}

bool JudgeFull() {
	for (int i = 0; i < ArrayLengh; i++) {
		for (int j = 0; j < ArrayLengh; j++) {
			if (Topo[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}