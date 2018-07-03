#include<graphics.h>
#include<stdio.h>
#include<math.h>

typedef struct {
	int x;
	int y;
	int z;
}Point;

static const int MapLength = 500;
static Point points[8];
static const float PI = 3.1415926;

void InitBackGround();
void DrewCube(int angle1, int angle2);
void DrewLine(Point p1, Point p2);

void main() {
	InitBackGround();
	int angle1 = 45;
	int angle2 = 45;
	IMAGE img;
	getimage(&img, 0, 0, MapLength, MapLength);
	setlinestyle(PS_SOLID,4);
	for (int i = 0; i < 4; i++) {
		points[i].x = 50 - (i & 1) * 100;
		points[i].y = 50 - (i>>1 & 1) * 100;
		points[i].z = -50;
		points[i+4].x = 50 - (i & 1) * 100;
		points[i+4].y = 50 - (i >> 1 & 1) * 100;
		points[i+4].z = 50;
	}
	int x1, x2, y1, y2;
	x1 = x2 = y1 = y2 = 0;
	MOUSEMSG m;
	bool start = false;
	DrewCube(angle1, angle2);
	while (true) {
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			x1 = m.x;
			y1 = m.y;
			start = true;
			break;
		case WM_LBUTTONUP:
			start = false;
			break;
		case WM_MOUSEMOVE:
			if (start) {
				x2 = m.x;
				y2 = m.y;
				angle1 += (y1 - y2) * 360 / MapLength;
				angle2 += (x1 - x2) * 360 / MapLength;
				angle1 = angle1 % 360;
				angle2 = angle2 % 360;
				putimage(0, 0, &img);
				DrewCube(angle1, angle2);
				x1 = x2;
				y1 = y2;
			}
		default:
			break;
		}
		
	}
	closegraph();
}

void InitBackGround() {
	initgraph(MapLength, MapLength);
	setbkcolor(RGB(84,255,159));
	cleardevice();
}

void DrewCube(int angle1,int angle2) {
	Point cp[8];
	for (int i = 0; i < 8; i++) {
		float a = angle1 *  PI/180;
		cp[i].x =points[i].x*cos(a)-points[i].y*sin(a);
		cp[i].y = points[i].x*sin(a)+points[i].y*cos(a);
		cp[i].z = points[i].z;
	}

	for (int i = 0; i < 8; i++) {
		float a = angle2 *  PI / 180;
		cp[i].x = cp[i].x*cos(a) - cp[i].z*sin(a);
		cp[i].z = cp[i].x*sin(a) + cp[i].z*cos(a);
	}

	DrewLine(cp[0], cp[1]);
	DrewLine(cp[0], cp[2]);
	DrewLine(cp[0], cp[4]);
	DrewLine(cp[1], cp[3]);

	DrewLine(cp[2], cp[3]);
	DrewLine(cp[1], cp[5]);
	DrewLine(cp[2], cp[6]);
	DrewLine(cp[3], cp[7]);

	DrewLine(cp[4], cp[5]);
	DrewLine(cp[4], cp[6]);
	DrewLine(cp[5], cp[7]);
	DrewLine(cp[6], cp[7]);
}

void DrewLine(Point p1, Point p2) {
	line(p1.x+MapLength/2, p1.y + MapLength / 2, p2.x + MapLength / 2, p2.y + MapLength / 2);
}