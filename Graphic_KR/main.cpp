#define _USE_MATH_DEFINES

#include <SDL.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <math.h>

const int frameHeight = 750;
const int frameWidth = 750;
const int N = 2;
const int M = 4;
const int speed = 5;
const float S = 1.1;
const float s = 10.0 / 11;
const float angle = M_PI / 180;
const float xA = 100, yA = 300, zA = 0, xB = 100, yB = 300, zB = 200, xC = 300, yC = 300, zC = 200, xV = 200, yV = 100, zV = 100;
const float xa = 120, ya = 400, za = 0, xb = 120, yb = 400, zb = 150, xc = 300, yc = 500, zc = 250, xv = 150, yv = 200, zv = 150;
const int color1 = 255, color2 = 230, color3 = 210, color4 = 180, color5 = 150;


void multing(float lin[N][M], float matrix[M][M])
{
	float res[N][M] = { {0, 0, 0, 0}, {0, 0, 0, 0} };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < M; k++)
			{
				res[i][j] += (lin[i][k] * matrix[k][j]);
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			lin[i][j] = res[i][j];
		}
	}
}


void rotateX(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M], float angle)
{
	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[1][0] + Line1[0][0] + Line2[0][0] + Line3[0][0] + Line4[1][0]) / 8,
		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[1][1] + Line1[0][1] + Line2[0][1] + Line3[0][1] + Line4[1][1]) / 8,
		zc = (line1[0][2] + line2[0][2] + line3[0][2] + line4[1][2] + Line1[0][2] + Line2[0][2] + Line3[0][2] + Line4[1][2]) / 8;
	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
	1} };
	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
	};
	float m_rotate[M][M] = { {cos(angle), 0, sin(angle), 0}, {0, 1, 0, 0}, {-sin(angle),
	0, cos(angle), 0}, {0 ,0 , 0, 1} };
	multing(line1, first_rot);
	multing(line1, m_rotate);
	multing(line1, second_rot);
	multing(line2, first_rot);
	multing(line2, m_rotate);
	multing(line2, second_rot);
	multing(line3, first_rot);
	multing(line3, m_rotate);
	multing(line3, second_rot);
	multing(line4, first_rot);
	multing(line4, m_rotate);
	multing(line4, second_rot);
	multing(line5, first_rot);
	multing(line5, m_rotate);
	multing(line5, second_rot);
	multing(line6, first_rot);
	multing(line6, m_rotate);
	multing(line6, second_rot);
	multing(Line1, first_rot);
	multing(Line1, m_rotate);
	multing(Line1, second_rot);
	multing(Line2, first_rot);
	multing(Line2, m_rotate);
	multing(Line2, second_rot);
	multing(Line3, first_rot);
	multing(Line3, m_rotate);
	multing(Line3, second_rot);
	multing(Line4, first_rot);
	multing(Line4, m_rotate);
	multing(Line4, second_rot);
	multing(Line5, first_rot);
	multing(Line5, m_rotate);
	multing(Line5, second_rot);
	multing(Line6, first_rot);
	multing(Line6, m_rotate);
	multing(Line6, second_rot);
}


void rotateY(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M], float angle)
{
	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[1][0] + Line1[0][0] + Line2[0][0] + Line3[0][0] + Line4[1][0]) / 8,
		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[1][1] + Line1[0][1] + Line2[0][1] + Line3[0][1] + Line4[1][1]) / 8,
		zc = (line1[0][2] + line2[0][2] + line3[0][2] + line4[1][2] + Line1[0][2] + Line2[0][2] + Line3[0][2] + Line4[1][2]) / 8;
	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
	1} };
	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
	};
	float m_rotate[M][M] = { {1, 0, 0, 0}, {0, cos(angle), sin(angle), 0}, {0, -
	sin(angle), cos(angle), 0}, {0, 0, 0, 1} };
	multing(line1, first_rot);
	multing(line1, m_rotate);
	multing(line1, second_rot);
	multing(line2, first_rot);
	multing(line2, m_rotate);
	multing(line2, second_rot);
	multing(line3, first_rot);
	multing(line3, m_rotate);
	multing(line3, second_rot);
	multing(line4, first_rot);
	multing(line4, m_rotate);
	multing(line4, second_rot);
	multing(line5, first_rot);
	multing(line5, m_rotate);
	multing(line5, second_rot);
	multing(line6, first_rot);
	multing(line6, m_rotate);
	multing(line6, second_rot);
	multing(Line1, first_rot);
	multing(Line1, m_rotate);
	multing(Line1, second_rot);
	multing(Line2, first_rot);
	multing(Line2, m_rotate);
	multing(Line2, second_rot);
	multing(Line3, first_rot);
	multing(Line3, m_rotate);
	multing(Line3, second_rot);
	multing(Line4, first_rot);
	multing(Line4, m_rotate);
	multing(Line4, second_rot);
	multing(Line5, first_rot);
	multing(Line5, m_rotate);
	multing(Line5, second_rot);
	multing(Line6, first_rot);
	multing(Line6, m_rotate);
	multing(Line6, second_rot);
	
}


void rotateZ(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M],  float angle)
{
	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[1][0] + Line1[0][0] + Line2[0][0] + Line3[0][0] + Line4[1][0]) / 8,
		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[1][1] + Line1[0][1] + Line2[0][1] + Line3[0][1] + Line4[1][1]) / 8,
		zc = (line1[0][2] + line2[0][2] + line3[0][2] + line4[1][2] + Line1[0][2] + Line2[0][2] + Line3[0][2] + Line4[1][2]) / 8;
	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
	1} };
	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
	};
	float m_rotate[M][M] = { {cos(angle), sin(angle), 0, 0}, {-sin(angle), cos(angle), 0,
	0}, {0, 0, 1, 0}, {0 ,0 , 0, 1} };
	multing(line1, first_rot);
	multing(line1, m_rotate);
	multing(line1, second_rot);
	multing(line2, first_rot);
	multing(line2, m_rotate);
	multing(line2, second_rot);
	multing(line3, first_rot);
	multing(line3, m_rotate);
	multing(line3, second_rot);
	multing(line4, first_rot);
	multing(line4, m_rotate);
	multing(line4, second_rot);
	multing(line5, first_rot);
	multing(line5, m_rotate);
	multing(line5, second_rot);
	multing(line6, first_rot);
	multing(line6, m_rotate);
	multing(line6, second_rot);
	multing(Line1, first_rot);
	multing(Line1, m_rotate);
	multing(Line1, second_rot);
	multing(Line2, first_rot);
	multing(Line2, m_rotate);
	multing(Line2, second_rot);
	multing(Line3, first_rot);
	multing(Line3, m_rotate);
	multing(Line3, second_rot);
	multing(Line4, first_rot);
	multing(Line4, m_rotate);
	multing(Line4, second_rot);
	multing(Line5, first_rot);
	multing(Line5, m_rotate);
	multing(Line5, second_rot);
	multing(Line6, first_rot);
	multing(Line6, m_rotate);
	multing(Line6, second_rot);
}


void scaling(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M], float S)
{
	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[1][0] + Line1[0][0] + Line2[0][0] + Line3[0][0] + Line4[1][0]) / 8,
		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[1][1] + Line1[0][1] + Line2[0][1] + Line3[0][1] + Line4[1][1]) / 8, 
		zc = (line1[0][2] + line2[0][2] + line3[0][2] + line4[1][2] + Line1[0][2] + Line2[0][2] + Line3[0][2] + Line4[1][2]) / 8;
	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc, 1} };
	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1} };
	float m_scale[M][M] = { {S,0,0,0},{0,S,0,0} ,{0,0,S,0}, {0, 0, 0, 1 } };
	multing(line1, first_rot);
	multing(line1, m_scale);
	multing(line1, second_rot);
	multing(line2, first_rot);
	multing(line2, m_scale);
	multing(line2, second_rot);
	multing(line3, first_rot);
	multing(line3, m_scale);
	multing(line3, second_rot);
	multing(line4, first_rot);
	multing(line4, m_scale);
	multing(line4, second_rot);
	multing(line5, first_rot);
	multing(line5, m_scale);
	multing(line5, second_rot);
	multing(line6, first_rot);
	multing(line6, m_scale);
	multing(line6, second_rot);
	multing(Line1, first_rot);
	multing(Line1, m_scale);
	multing(Line1, second_rot);
	multing(Line2, first_rot);
	multing(Line2, m_scale);
	multing(Line2, second_rot);
	multing(Line3, first_rot);
	multing(Line3, m_scale);
	multing(Line3, second_rot);
	multing(Line4, first_rot);
	multing(Line4, m_scale);
	multing(Line4, second_rot);
	multing(Line5, first_rot);
	multing(Line5, m_scale);
	multing(Line5, second_rot);
	multing(Line6, first_rot);
	multing(Line6, m_scale);
	multing(Line6, second_rot);
}


SDL_Window* Window = NULL;
SDL_Renderer* Render = NULL;


//void paintOverSquare(float line1[N][M], float line2[N][M], float line3[N][M], float
//	line4[N][M])
//{
//	/*float x1 = line1[0][0], y1 = line1[0][1];
//	float x2 = line2[0][0], y2 = line2[0][1];
//	float x3 = line3[0][0], y3 = line3[0][1];
//	float x4 = line4[0][0], y4 = line4[0][1];
//	int miny = fminf(y1, fminf(y2, fminf(y3, y4)));
//	int maxy = fmaxf(y1, fmaxf(y2, fmaxf(y3, y4)));
//	int minx = fminf(x1, fminf(x2, fminf(x3, x4)));
//	int maxx = fmaxf(x1, fmaxf(x2, fmaxf(x3, x4)));
//	int y;
//	int x;
//	int a;
//	int b;
//	int c;
//	int d;
//	int e;
//	for (int y = miny; y <= maxy; y++)
//	{
//		for (int x = maxx; x >= minx; x--)
//		{
//			a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
//			b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
//			c = (x3 - x) * (y4 - y3) - (x4 - x3) * (y3 - y);
//			d = (x4 - x) * (y1 - y4) - (x1 - x4) * (y4 - y);
//			if ((a < 0 && b < 0 && c < 0 && d < 0) || (a > 0 && b > 0 && c > 0 && d > 0))
//			{
//				SDL_RenderDrawPoint(Render, x, y);
//			}
//		}
//		x = maxx;
//	}*/
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, line1[0][0], line1[0][1], line1[1][0], line1[1][1]);
//	SDL_RenderDrawLine(Render, line2[0][0], line2[0][1], line2[1][0], line2[1][1]);
//	SDL_RenderDrawLine(Render, line3[0][0], line3[0][1], line3[1][0], line3[1][1]);
//	SDL_RenderDrawLine(Render, line4[0][0], line4[0][1], line4[1][0], line4[1][1]);
//}


void paintOverTriangle(float line1[N][M], float line2[N][M], float line3[N][M], int num_lines)
{
	float x1 = line1[0][0], y1 = line1[0][1];
	float x2 = line1[1][0], y2 = line1[1][1];
	float x3 = line2[1][0], y3 = line2[1][1];
	float xmin, xmax;
	float k12, k23, k31;

	x1 == x2 ? k12 = 0 : k12 = (y2 - y1) / (x2 - x1);
	x2 == x3 ? k23 = 0 : k23 = (y3 - y2) / (x3 - x2);
	x1 == x3 ? k31 = 0 : k31 = (y1 - y3) / (x1 - x3);

	float b12 = y1 - k12 * x1, b23 = y2 - k23 * x2, b31 = y3 - k31 * x3;
	float X, Y1, Y2;

	xmin = fmin(fmin(x1, x2), x3);
	xmax = fmax(fmax(x1, x2), x3);

	for (X = xmin; X < xmax; X++)
	{
		if (xmin == x1 && xmax == x3) {
			Y1 = X * k31 + b31;
			if (X < x2) {
				Y2 = X * k12 + b12;
			}
			else {
				Y2 = X * k23 + b23;
			}
		}
		else if (xmin == x1) {
			Y1 = X * k12 + b12;
			if (X < x3) {
				Y2 = X * k31 + b31;
			}
			else {
				Y2 = X * k23 + b23;
			}
		}
		else if (xmin == x2 && xmax == x3) {
			Y1 = X * k23 + b23;
			if (X < x1) {
				Y2 = X * k12 + b12;
			}
			else {
				Y2 = X * k31 + b31;
			}
		}
		else if (xmin == x2) {
			Y1 = X * k12 + b12;
			if (X < x3) {
				Y2 = X * k23 + b23;
			}
			else {
				Y2 = X * k31 + b31;
			}
		}
		else if (xmin == x3 && xmax == x1) {
			Y1 = X * k31 + b31;
			if (X < x2) {
				Y2 = X * k23 + b23;
			}
			else {
				Y2 = X * k12 + b12;
			}
		}
		else if (xmin == x3) {
			Y1 = X * k23 + b23;
			if (X < x1) {
				Y2 = X * k31 + b31;
			}
			else {
				Y2 = X * k12 + b12;
			}
		}
		SDL_RenderDrawLine(Render, X, Y1, X, Y2);
	}
	/*float x1 = line1[0][0], y1 = line1[0][1];	
	float x2 = line1[1][0], y2 = line1[1][1];
	float x3 = line2[1][0], y3 = line2[1][1];
	int miny = fminf(y1, fminf(y2, y3));
	int maxy = fmaxf(y1, fmaxf(y2, y3));
	int minx = fminf(x1, fminf(x2, x3));
	int maxx = fmaxf(x1, fmaxf(x2, x3));
	int y;
	int x;
	int a;
	int b;
	int c;
	int e;
	for (int y = miny; y <= maxy; y++)
	{
		for (int x = maxx; x >= minx; x--)
		{
			a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
			b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
			c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);
			if ((a < 0 && b < 0 && c < 0) || (a > 0 && b > 0 && c > 0))
			{
				SDL_RenderDrawPoint(Render, x, y);
			}
		}
		x = maxx;
	}*/

	//SDL_RenderDrawLine(Render, line3[0][0], line3[0][1], line3[1][0], line3[1][1]);
	
	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);

	if (num_lines == 12) {
		SDL_RenderDrawLine(Render, line1[0][0], line1[0][1], line1[1][0], line1[1][1]);
		SDL_RenderDrawLine(Render, line2[0][0], line2[0][1], line2[1][0], line2[1][1]);
	}
	else if (num_lines == 3){
		SDL_RenderDrawLine(Render, line3[0][0], line3[0][1], line3[1][0], line3[1][1]);
		SDL_RenderDrawLine(Render, line2[0][0], line2[0][1], line2[1][0], line2[1][1]);
	}
	else  if (num_lines == 255){
		SDL_RenderDrawLine(Render, line1[0][0], line1[0][1], line1[1][0], line1[1][1]);
		SDL_RenderDrawLine(Render, line2[0][0], line2[0][1], line2[1][0], line2[1][1]);
		SDL_RenderDrawLine(Render, line3[0][0], line3[0][1], line3[1][0], line3[1][1]);
	}
	/*SDL_RenderDrawLine(Render, x1, y1, x2, y2);
	SDL_RenderDrawLine(Render, x2, y2, x3, y3);
	SDL_RenderDrawLine(Render, x3, y3, x1, y1);*/
}

void paintOverQuadrilateral(float line1[N][M], float line2[N][M], float line3[N][M], int color)
{
	float line_help1[N][M] = { {0,0,0,1}, {0,0,0,1} }, line_help2[N][M] = { {0,0,0,1}, {0,0,0,1} };
	line_help1[0][0] = line1[1][0]; line_help1[0][1] = line1[1][1]; line_help1[1][2] = line1[1][2];
	line_help1[1][0] = line2[1][0]; line_help1[1][1] = line2[1][1]; line_help1[1][2] = line2[1][2];
	line_help2[0][0] = line2[1][0]; line_help2[0][1] = line2[1][1]; line_help2[0][2] = line2[1][2];
	line_help2[1][0] = line3[1][0]; line_help2[1][1] = line3[1][1]; line_help2[1][2] = line3[1][2];
	paintOverTriangle(line1, line2, line_help1, 12);
	SDL_SetRenderDrawColor(Render, color, color - 10, color - 20, 255);
	paintOverTriangle(line_help1, line_help2, line3, 3);
}


bool compare(int x1, int x2) { return x1 > x2; }


//void paintOverSecond(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float points[3][3])
//{
//	/*int zc1 = (line1[0][2] + line2[0][2] + line3[0][2]) / 3;
//	int zc2 = (line1[0][2] + line1[1][2] + line4[1][2]) / 3;
//	int zc3 = (line2[0][2] + line2[1][2] + line4[1][2]) / 3;
//	int zc4 = (line3[0][2] + line3[1][2] + line4[1][2]) / 3;*/
//	int zc1_sec = (line1[0][2] + line2[0][2] + line3[0][2]) / 3;
//	int zc2_sec = (line1[0][2] + line1[1][2] + line4[1][2]) / 3;
//	int zc3_sec = (line2[0][2] + line2[1][2] + line4[1][2]) / 3;
//	int zc4_sec = (line3[0][2] + line3[1][2] + line4[1][2]) / 3;
//	int mxz_sec[4] = { zc1_sec, zc2_sec, zc3_sec, zc4_sec };
//	float line1_cut[N][M] = { {0,0,0,1}, {0,0,0,1} }, line2_cut[N][M] = { {0,0,0,1}, {0,0,0,1} };
//
//	for (int i = 0; i < 4; i++)
//	{
//		std::cout << mxz_sec[i] << std::endl;
//	}
//
//	printf("----\n");
//
//	std::sort(mxz_sec, mxz_sec + 4, compare);
//
//	for (int i = 0; i < 4; i++)
//	{
//		std::cout << mxz_sec[i] << std::endl;
//	}
//
//	if (mxz_sec[1] == zc1_sec) {
//		SDL_SetRenderDrawColor(Render, color1, color1-10, color1-20, 255);
//		paintOverTriangle(line1, line2, line3, 0);
//	}
//	if (mxz_sec[1] == zc2_sec) {
//		SDL_SetRenderDrawColor(Render, color2, color2-10, color2-20, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line4[0][i];
//			line1_cut[1][i] = points[0][i];
//			line2_cut[0][i] = line5[0][i];
//			line2_cut[1][i] = points[1][i];
//		}
//		paintOverQuadrilateral(line1, line1_cut, line2_cut, color2);
//	}
//	if (mxz_sec[1] == zc3_sec) {
//		SDL_SetRenderDrawColor(Render, color3, color3-10, color3-20, 255);
//		//printf("check bcv");
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line5[0][i];
//			line1_cut[1][i] = points[1][i];
//			line2_cut[0][i] = line6[0][i];
//			line2_cut[1][i] = points[2][i];
//		}
//		paintOverQuadrilateral(line2, line1_cut, line2_cut, color3);
//	}
//	if (mxz_sec[1] == zc4_sec) {
//		SDL_SetRenderDrawColor(Render, color4, color4-10, color4-20, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line6[0][i];
//			line1_cut[1][i] = points[2][i];
//			line2_cut[0][i] = line1[0][i];
//			line2_cut[1][i] = points[0][i];
//		}
//		paintOverQuadrilateral(line3, line1_cut, line2_cut, color4);
//	}
//	if (mxz_sec[2] == zc1_sec) {
//		SDL_SetRenderDrawColor(Render, color1, color1 - 10, color1 - 20, 255);
//		paintOverTriangle(line1, line2, line3, 0);
//	}
//	if (mxz_sec[2] == zc2_sec) {
//		SDL_SetRenderDrawColor(Render, color2, color2 - 10, color2 - 20, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line4[0][i];
//			line1_cut[1][i] = points[0][i];
//			line2_cut[0][i] = line5[0][i];
//			line2_cut[1][i] = points[1][i];
//		}
//		paintOverQuadrilateral(line1, line1_cut, line2_cut, color2);
//	}
//	if (mxz_sec[2] == zc3_sec) {
//		SDL_SetRenderDrawColor(Render, color3, color3 - 10, color3 - 20, 255);
//		//printf("check bcv");
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line5[0][i];
//			line1_cut[1][i] = points[1][i];
//			line2_cut[0][i] = line6[0][i];
//			line2_cut[1][i] = points[2][i];
//		}
//		paintOverQuadrilateral(line2, line1_cut, line2_cut, color3);
//	}
//	if (mxz_sec[2] == zc4_sec) {
//		SDL_SetRenderDrawColor(Render, color4, color4 - 10, color4 - 20, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line6[0][i];
//			line1_cut[1][i] = points[2][i];
//			line2_cut[0][i] = line1[0][i];
//			line2_cut[1][i] = points[0][i];
//		}
//		paintOverQuadrilateral(line3, line1_cut, line2_cut, color4);
//	}if (mxz_sec[3] == zc1_sec) {
//		SDL_SetRenderDrawColor(Render, color1, color1 - 10, color1 - 20, 255);
//		paintOverTriangle(line1, line2, line3, 0);
//	}
//	if (mxz_sec[3] == zc2_sec) {
//		SDL_SetRenderDrawColor(Render, color2, color2 - 10, color2 - 20, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line4[0][i];
//			line1_cut[1][i] = points[0][i];
//			line2_cut[0][i] = line5[0][i];
//			line2_cut[1][i] = points[1][i];
//		}
//		paintOverQuadrilateral(line1, line1_cut, line2_cut, color2);
//	}
//	if (mxz_sec[3] == zc3_sec) {
//		SDL_SetRenderDrawColor(Render, color3, color3 - 10, color3 - 20, 255);
//		//printf("check bcv");
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line5[0][i];
//			line1_cut[1][i] = points[1][i];
//			line2_cut[0][i] = line6[0][i];
//			line2_cut[1][i] = points[2][i];
//		}
//		paintOverQuadrilateral(line2, line1_cut, line2_cut, color3);
//	}
//	if (mxz_sec[3] == zc4_sec) {
//		SDL_SetRenderDrawColor(Render, color4, color4 - 10, color4 - 20, 255);
//		for (int i = 0; i < 3; i++)
//		{
//			line1_cut[0][i] = line6[0][i];
//			line1_cut[1][i] = points[2][i];
//			line2_cut[0][i] = line1[0][i];
//			line2_cut[1][i] = points[0][i];
//		}
//		paintOverQuadrilateral(line3, line1_cut, line2_cut, color4);
//	}
//}
//
//void paintOver(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M], float points[3][3])
//{
//	/*int zc1 = (line1[0][2] + line2[0][2] + line3[0][2]) / 3;
//	int zc2 = (line1[0][2] + line1[1][2] + line4[1][2]) / 3;
//	int zc3 = (line2[0][2] + line2[1][2] + line4[1][2]) / 3;
//	int zc4 = (line3[0][2] + line3[1][2] + line4[1][2]) / 3;*/
//	int zc1 = (line1[0][2] + line2[0][2] + line3[0][2]) / 3;
//	int zc2 = (line1[0][2] + line1[1][2] + line4[1][2]) / 3;
//	int zc3 = (line2[0][2] + line2[1][2] + line4[1][2]) / 3;
//	int zc4 = (line3[0][2] + line3[1][2] + line4[1][2]) / 3;
//	int mxz[4] = { zc1, zc2, zc3, zc4};
//	for (int i = 0; i < 4; i++)
//	{
//		std::cout << mxz[i] << std::endl;
//	}
//	/*system("pause");
//	qsort(mxz, 4, sizeof(int), compare);*/
//	printf("---\n");
//	std::sort(mxz, mxz + 4, compare);
//	for (int i = 0; i < 4; i++)
//	{
//		std::cout << mxz[i] << std::endl;
//	}
//	
//	if (mxz[1] == zc1) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		//printf("check abc");
//		paintOverTriangle(line1, line2, line3, 0);
//		
//	}
//	if (mxz[1] == zc2) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//
//		paintOverTriangle(line1, line4, line5, 0);
//	}
//	if (mxz[1] == zc3) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		//printf("check bcv");
//		paintOverTriangle(line2, line5, line6, 0);
//	}
//	if (mxz[1] == zc4) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line6, line4, 0);
//	}
//	//paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6);
//	if (mxz[2] == zc1) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		paintOverTriangle(line1, line2, line3, 0);
//	}
//	if (mxz[2] == zc2) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//		paintOverTriangle(line1, line4, line5, 0);
//	}
//	if (mxz[2] == zc3) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		paintOverTriangle(line2, line5, line6, 0);
//	}
//	if (mxz[2] == zc4) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line6, line4, 0);
//	}
//	//paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6);
//	if (mxz[3] == zc1) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		paintOverTriangle(line1, line2, line3, 0);
//	}
//	if (mxz[3] == zc2) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//		paintOverTriangle(line1, line4, line5, 0);
//	}
//	if (mxz[3] == zc3) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		paintOverTriangle(line2, line5, line6, 0);
//	}
//	if (mxz[3] == zc4) {
//		paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6, points);
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line6, line4, 0);
//	}
//	//paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6);
//}

//


float* gauss(float a[3][3], float y[3], int n)
{
	float* x, max;
	int k, index;
	const float eps = 0.00001;  // точность
	x = new float[n];
	k = 0;
	while (k < n)
	{
		// Поиск строки с максимальным a[i][k]
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		// Перестановка строк
		if (max < eps)
		{
			// нет ненулевых диагональных элементов
			/*std::cout << "Решение получить невозможно из-за нулевого столбца ";
			std::cout << index << " матрицы A" << std::endl;*/
			return 0;
		}
		for (int j = 0; j < n; j++)
		{
			float temp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = temp;
		}
		float temp = y[k];
		y[k] = y[index];
		y[index] = temp;
		// Нормализация уравнений
		for (int i = k; i < n; i++)
		{
			float temp = a[i][k];
			if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] / temp;
			y[i] = y[i] / temp;
			if (i == k)  continue; // уравнение не вычитать само из себя
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] - a[k][j];
			y[i] = y[i] - y[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = y[k];
		for (int i = 0; i < k; i++)
			y[i] = y[i] - a[i][k] * x[k];
	}
	return x;
}

float* equation_plane(float line1[N][M], float line2[N][M], float line3[N][M]) {
	
	float A1 = line1[1][0] - line1[0][0];
	//std::cout << A1 << " ";
	float B1 = line1[1][1] - line1[0][1];
	//std::cout << B1 << " ";
	float C1 = line1[1][2] - line1[0][2];
	//std::cout << C1 << " ";
	float A2 = line2[1][0] - line1[0][0];
	//std::cout << A2 << " ";
	float B2 = line2[1][1] - line1[0][1];
	//std::cout << B2 << " ";
	float C2 = line2[1][2] - line1[0][2];
	//std::cout << C2 << " ";
	float a = B1 * C2 - B2 * C1;
	float b = A2 * C1 - A1 * C2;
	float c = A1 * B2 - B1 * A2;
	float d = (-a * line1[0][0] - b * line1[0][1] - c * line1[0][2]);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(2);
	//int abc[4] = { a, b, c, d };
	float* abc = new float[4];
	abc[0] = a; abc[1] = b; abc[2] = c; abc[3] = d;
	///*for (int i = 0; i < 4; i++)
	//{
	//	std::cout << abc[i] << std::endl;
	//}*/
	//std::cout << "Equation of plane is " << a << " x + " << b << " y + " << c << " z + " << d << " = 0\n" ;
	return abc;
}

void findLine(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], 
	float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M],
	float points[3][3])
{
	float* abc1 = new float[4]; //float* abc2 = new float[4];
	
	abc1 = equation_plane(line1, line2, line3);
	
	float x1 = Line4[0][0], x2 = Line4[1][0], y1 = Line4[0][1], y2 = Line4[1][1], z1 = Line4[0][2], z2 = Line4[1][2];
	//std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << z1 << " " << z2 << "\n ";
	float a[3][3];
	float y[3], *x;
	int n = 3;
	/*a = new float* [n];
	a[0] = new float[n];*/
	a[0][0] = y2 - y1;
	a[0][1] = x1 - x2;
	a[0][2] = 0;
	//a[1] = new float[n];
	a[1][0] = 0;
	a[1][1] = z2 - z1;
	a[1][2] = y1 - y2;
	//a[2] = new float[n];
	a[2][0] = abc1[0];
	a[2][1] = abc1[1];
	a[2][2] = abc1[2];
	//y = new float[n];
	y[0] = (y2 - y1) * x1 - (x2 - x1) * y1;
	y[1] = (z2 - z1) * y1 - (y2 - y1) * z1;
	y[2] = -abc1[3];
	//sysout(a, y, n);
	x = gauss(a, y, n);
	for (int i = 0; i < n; i++) {
		points[0][i] = x[i];
		//std::cout << "x[" << i << "]=" << x[i] << std::endl;
	}
	//std::cin.get(); std::cin.get();

	x1 = Line5[0][0], x2 = Line5[1][0], y1 = Line5[0][1], y2 = Line5[1][1], z1 = Line5[0][2], z2 = Line5[1][2];
	//std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << z1 << " " << z2 << "\n ";
	//a = new float* [n];
	//a[0] = new float[n];
	a[0][0] = y2 - y1;
	a[0][1] = x1 - x2;
	a[0][2] = 0;
	//a[1] = new float[n];
	a[1][0] = 0;
	a[1][1] = z2 - z1;
	a[1][2] = y1 - y2;
	//a[2] = new float[n];
	a[2][0] = abc1[0];
	a[2][1] = abc1[1];
	a[2][2] = abc1[2];
	//y = new float[n];
	y[0] = (y2 - y1) * x1 - (x2 - x1) * y1;
	y[1] = (z2 - z1) * y1 - (y2 - y1) * z1;
	y[2] = -abc1[3];
	//sysout(a, y, n);
	x = gauss(a, y, n);
	for (int i = 0; i < n; i++) {
		points[1][i] = x[i];
		//std::cout << "x[" << i << "]=" << x[i] << std::endl;
	}
	//std::cin.get(); std::cin.get();

	x1 = Line6[0][0], x2 = Line6[1][0], y1 = Line6[0][1], y2 = Line6[1][1], z1 = Line6[0][2], z2 = Line6[1][2];
	//std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << z1 << " " << z2 << "\n ";
	//a = new float* [n];
	//a[0] = new float[n];
	a[0][0] = y2 - y1;
	a[0][1] = x1 - x2;
	a[0][2] = 0;
	//a[1] = new float[n];
	a[1][0] = 0;
	a[1][1] = z2 - z1;
	a[1][2] = y1 - y2;
	//a[2] = new float[n];
	a[2][0] = abc1[0];
	a[2][1] = abc1[1];
	a[2][2] = abc1[2];
	//y = new float[n];
	y[0] = (y2 - y1) * x1 - (x2 - x1) * y1;
	y[1] = (z2 - z1) * y1 - (y2 - y1) * z1;
	y[2] = -abc1[3];
	//sysout(a, y, n);
	x = gauss(a, y, n);
	for (int i = 0; i < n; i++) {
		points[2][i] = x[i];
		//std::cout << "x[" << i << "]=" << x[i] << std::endl;
	}
	//std::cin.get(); std::cin.get();
}

//void findLine(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M])
//{
//	float* abc1 = new float[4]; float* abc2 = new float[4];
//	abc1 = equation_plane(line1, line2, line3);
//
//	float k1, k2, k3;
//	float B1, B2, B3;
//	//std::copy(equation_plane(line1, line2, line3), equation_plane(line1, line2, line3) + 3, abc);
//
//	/*for (int i = 0; i < 4; i++)
//	{
//		std::cout << abc[i] << std::endl;
//	}*/
//
//	abc2 = equation_plane(Line3, Line5, Line6);
//
//	float a1 = abc1[0], b1 = abc1[1], c1 = abc1[2], d1 = abc1[3];
//	float a2 = abc2[0], b2 = abc2[1], c2 = abc2[2], d2 = abc2[3];
//
//	long float x1 = (-b1 * ((a2 * d1 - a1 * d2) / (a1 * b2 - a2 * b1)) - d1) / a1, y1 = (a2 * d1 - a1 * d2) / (a1 * b2 - a2 * b1);
//	long float x2 = 0, y2 = (-c1 * ((b2 * d1 - b1 * d1) / (b1 * c2 - b2 * c1)) - d1) / b1;
//
//	if (a1 == 0) {
//		x1 = 0;
//	}
//	else if (a1 * b2 - a2 * b1 == 0){
//		x1 = -d1/a1;
//	}
//	if (a1 * b2 - a2 * b1 == 0) {
//		y1 = 0;
//	}
//	if (b1 == 0) {
//		y2 = 0;
//	}
//	else if (b1 * c2 - b2 * c1 == 0) {
//		y2 = -d1 / b1;
//	}
//	
//	k1 = (y2 - y1) / (x2 - x1);
//	B1 = y1 - k1 * x1;
//	if (x2 - x1 == 0)
//		k1 = 0;
//
//	std::cout << "\n" << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n";
//
//	/*SDL_SetRenderDrawColor(Render, 255, 255, 0, 255);
//	SDL_RenderDrawLine(Render, x1, y1, x2, y2);*/
//
//	abc2 = equation_plane(Line1, Line3, Line4);
//	//system("pause");
//
//	a1 = abc1[0], b1 = abc1[1], c1 = abc1[2], d1 = abc1[3];
//	a2 = abc2[0], b2 = abc2[1], c2 = abc2[2], d2 = abc2[3];
//
//	x1 = (-b1 * ((a2 * d1 - a1 * d2) / (a1 * b2 - a2 * b1)) - d1) / a1, y1 = (a2 * d1 - a1 * d2) / (a1 * b2 - a2 * b1);
//	x2 = 0, y2 = (-c1 * ((b2 * d1 - b1 * d1) / (b1 * c2 - b2 * c1)) - d1) / b1;
//
//	if (a1 == 0) {
//		x1 = 0;
//	}
//	else if (a1 * b2 - a2 * b1 == 0) {
//		x1 = -d1 / a1;
//	}
//	if (a1 * b2 - a2 * b1 == 0) {
//		y1 = 0;
//	}
//	if (b1 == 0) {
//		y2 = 0;
//	}
//	else if (b1 * c2 - b2 * c1 == 0) {
//		y2 = -d1 / b1;
//	}
//
//	k2 = (y2 - y1) / (x2 - x1);
//	if (x2 - x1 == 0)
//		k2 = 0;
//	B2 = y1 - k1 * x1;
//
//	/*SDL_SetRenderDrawColor(Render, 255, 255, 0, 255);
//	SDL_RenderDrawLine(Render, x1, y1, x2, y2);*/
//
//	abc2 = equation_plane(Line2, Line4, Line5);
//
//	a1 = abc1[0], b1 = abc1[1], c1 = abc1[2], d1 = abc1[3];
//	a2 = abc2[0], b2 = abc2[1], c2 = abc2[2], d2 = abc2[3];
//
//	x1 = (-b1 * ((a2 * d1 - a1 * d2) / (a1 * b2 - a2 * b1)) - d1) / a1, y1 = (a2 * d1 - a1 * d2) / (a1 * b2 - a2 * b1);
//	x2 = 0, y2 = (-c1 * ((b2 * d1 - b1 * d1) / (b1 * c2 - b2 * c1)) - d1) / b1;
//
//	if (a1 == 0) {
//		x1 = 0;
//	}
//	else if (a1 * b2 - a2 * b1 == 0) {
//		x1 = -d1 / a1;
//	}
//	if (a1 * b2 - a2 * b1 == 0) {
//		y1 = 0;
//	}
//	if (b1 == 0) {
//		y2 = 0;
//	}
//	else if (b1 * c2 - b2 * c1 == 0) {
//		y2 = -d1 / b1;
//	}
//
//	k3 = (y2 - y1) / (x2 - x1);
//	if (x2 - x1 == 0)
//		k3 = 0;
//	B3 = y1 - k1 * x1;
//
//	float X1, Y1, X2, Y2, X3, Y3;
//
//	std::cout << "\n\n" << k1 << " " << k2 << " " << k3 << "\n" << B1 << " " << B2 << " " << B3 << "\n\n";
//
//	X1 = (B2 - B1) / (k1 - k2);
//	Y1 = k1 * X1 + B1;
//	X2 = (B3 - B2) / (k2-k3);
//	Y2 = k2 * X2 + B2;
//	X3 = (B3 - B1) / (k1 - k3);
//	Y3 = k3 * X3 + B3;
//	//std::cout << "\n\n" << X1 << " " << X2 << " " << X3 << "\n" << Y1 << " " << Y2 << " " << Y3 << "\n\n";
//	SDL_SetRenderDrawColor(Render, 255, 255, 0, 255);
//	/*SDL_RenderDrawLine(Render, X1, Y1, X2, Y2);
//	SDL_RenderDrawLine(Render, X2, Y2, X3, Y3);
//	SDL_RenderDrawLine(Render, X3, Y3, X1, Y1);*/
//	//SDL_SetRenderDrawColor(Render, 255, 255, 0, 255);
//	//SDL_RenderDrawLine(Render, x1, y1, x2, y2);
//
//	//std::copy(equation_plane(Line1, Line2, Line3), equation_plane(line1, line2, line3) + 3, abc);
//	/*for (int i = 0; i < 4; i++)
//	{
//		std::cout << abc[i] << std::endl;
//	}*/
//}

void paintOver(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M],
	float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M],
	float points[3][3])
{
	/*int zc1 = (line1[0][2] + line2[0][2] + line3[0][2]) / 3;
	int zc2 = (line1[0][2] + line1[1][2] + line4[1][2]) / 3;
	int zc3 = (line2[0][2] + line2[1][2] + line4[1][2]) / 3;
	int zc4 = (line3[0][2] + line3[1][2] + line4[1][2]) / 3;*/
	int zc1 = (line1[0][2] + line2[0][2] + line3[0][2]) / 3;
	int zc2 = (line1[0][2] + line1[1][2] + line4[1][2]) / 3;
	int zc3 = (line2[0][2] + line2[1][2] + line4[1][2]) / 3;
	int zc4 = (line3[0][2] + line3[1][2] + line4[1][2]) / 3;
	int zc1_sec = (Line1[0][2] + Line2[0][2] + Line3[0][2]) / 3;
	int zc2_sec = (Line1[0][2] + Line1[1][2] + Line4[1][2]) / 3;
	int zc3_sec = (Line2[0][2] + Line2[1][2] + Line4[1][2]) / 3;
	int zc4_sec = (Line3[0][2] + Line3[1][2] + Line4[1][2]) / 3;
	int mxz[8] = { zc1, zc2, zc3, zc4, zc1_sec, zc2_sec, zc3_sec, zc4_sec };
	float line1_cut[N][M] = { {0,0,0,1}, {0,0,0,1} }, line2_cut[N][M] = {{0,0,0,1}, {0,0,0,1}};
	//for (int i = 0; i < 4; i++)
	//{
	//	std::cout << mxz[i] << std::endl;
	//}
	/*system("pause");
	qsort(mxz, 4, sizeof(int), compare);*/
	//printf("---\n");
	std::sort(mxz, mxz + 8, compare);
	/*for (int i = 0; i < 4; i++)
	{
		std::cout << mxz[i] << std::endl;
	}*/

	for (int i = 1; i < 8; i++)
	{
		if (mxz[i] == zc1) {
			SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
			//printf("check abc");
			paintOverTriangle(line1, line2, line3, 255);

		}
		if (mxz[i] == zc2) {
			SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);

			paintOverTriangle(line1, line4, line5, 255);
		}
		if (mxz[i] == zc3) {
			SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
			//printf("check bcv");
			paintOverTriangle(line2, line5, line6, 255);
		}
		if (mxz[i] == zc4) {
			SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
			paintOverTriangle(line3, line6, line4, 255);
		}
		if (mxz[i] == zc1_sec) {
			SDL_SetRenderDrawColor(Render, color1, color1 - 10, color1 - 20, 255);
			//printf("check abc");
			paintOverTriangle(Line1, Line2, Line3, 255);

		}
		if (mxz[i] == zc2_sec) {
			SDL_SetRenderDrawColor(Render, color2, color2 - 10, color2 - 20, 255);
			for (int i = 0; i < 3; i++)
			{
				line1_cut[0][i] = Line4[0][i];
				line1_cut[1][i] = points[0][i];
				line2_cut[0][i] = Line5[0][i];
				line2_cut[1][i] = points[1][i];
			}

			paintOverQuadrilateral(Line1, line1_cut, line2_cut, color2);
		}
		if (mxz[i] == zc3_sec) {
			SDL_SetRenderDrawColor(Render, color3, color3 - 10, color3 - 20, 255);
			for (int i = 0; i < 3; i++)
			{
				line1_cut[0][i] = Line5[0][i];
				line1_cut[1][i] = points[1][i];
				line2_cut[0][i] = Line6[0][i];
				line2_cut[1][i] = points[2][i];
			}
			//printf("check bcv");
			paintOverQuadrilateral(Line2, line1_cut, line2_cut, color3);
		}
		if (mxz[i] == zc4_sec) {
			SDL_SetRenderDrawColor(Render, color4, color4 - 10, color4 - 20, 255);
			for (int i = 0; i < 3; i++)
			{
				line1_cut[0][i] = Line6[0][i];
				line1_cut[1][i] = points[2][i];
				line2_cut[0][i] = Line4[0][i];
				line2_cut[1][i] = points[0][i];
			}
			paintOverQuadrilateral(Line3, line1_cut, line2_cut, color4);
		}
	}
	
}


bool Init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << SDL_GetError() << std::endl;
	else {
		Window = SDL_CreateWindow("Lines", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, frameWidth, frameHeight, SDL_WINDOW_SHOWN);
		if (Window == NULL)
			std::cout << SDL_GetError() << std::endl;
		else
			Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	}
	return success;
}


void drawA(int x, int y, int dx)
{
	int ch = 1;
	if (dx < 0)
		ch = -1;
	int X = x, Y = y;
	if (Y - 35 < 0)
		Y = 36;
	if (Y - 15 > frameHeight)
		Y = frameHeight + 14;
	if (ch == 1 && X - 15 < 0)
		X = 16;
	if (ch == -1 && X + 15 > frameWidth)
		X = frameWidth - 16;
	int x0 = X - (ch * 15), y0 = Y - 15;
	int x1 = X - (ch * 10), y1 = Y - 35;
	int x2 = X - (ch * 5), y2 = y0;
	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
	SDL_RenderDrawLine(Render, (x1 + x0) / 2, (y0 + y1) / 2, (x2 + x1) / 2, (y0 + y1) /
		2);
}


void drawB(int x, int y, int dx)
{
	int X = x, Y = y;
	int ch = 1;
	if (dx < 0)
		ch = -1;
	if (Y - 35 < 0)
		Y = 36;
	if (Y - 15 > frameHeight)
		Y = frameHeight + 14;
	if (ch == 1 && X - 15 < 0)
		X = 16;
	if (ch == -1 && X + 27 > frameWidth)
		X = frameWidth - 28;
	int x0 = X - (ch * 15), y0 = Y - 15;
	int x1 = x0, y1 = Y - 35;
	int x2 = x0 + 10, y2 = y1;
	int x3 = x2, y3 = (y0 - y1) / 2 + y1 - 2;
	int x4 = x2 + 2, y4 = y3;
	int x5 = x4, y5 = y0;
	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
	SDL_RenderDrawLine(Render, x2, y2, x3, y3);
	SDL_RenderDrawLine(Render, x4, y4, x5, y5);
	SDL_RenderDrawLine(Render, x5, y5, x0, y0);
	SDL_RenderDrawLine(Render, x0, (y0 + y1) / 2 - 2, x4, (y0 + y1) / 2 - 2);
}


void drawC(int x, int y, int dx)
{
	int ch = 1;
	if (dx <= 0)
		ch = -1;
	int X = x, Y = y;
	if (Y - 35 < 0)
		Y = 36;
	if (Y - 15 > frameHeight)
		Y = frameHeight + 14;
	if (ch == 1 && X - 25 < 0)
		X = 26;
	if (ch == -1 && X + 15 > frameWidth)
		X = frameWidth - 16;
	int x0 = X - (ch * 15), y0 = Y - 15;
	int x1 = x0 - 10, y1 = y0;
	int x2 = x1, y2 = Y - 35;
	int x3 = x0, y3 = y2;
	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
	SDL_RenderDrawLine(Render, x2, y2, x3, y3);
	SDL_RenderDrawLine(Render, (x1 + x0) / 2, (y0 + y1) / 2, (x2 + x1) / 2, (y0 + y1) / 2);
}


//void drawH(int x, int y, int dx)
//{
//	int X = x, Y = y;
//	int ch = 1;
//	if (dx <= 0)
//		ch = -1;
//	if (Y - 35 < 0)
//		Y = 36;
//	if (Y - 15 > frameHeight)
//		Y = frameHeight + 14;
//	if (ch == 1 && X - 15 < 0)
//		X = 16;
//	if (ch == -1 && X + 25 > frameWidth)
//		X = frameWidth - 26;
//	int x0 = X - (ch * 15), y0 = Y - 15;
//	int x1 = x0, y1 = Y - 35;
//	int x2 = x0 + 10, y2 = y0;
//	int x3 = x2, y3 = y1;
//	int x4 = x1, y4 = (y1 + y0) / 2;
//	int x5 = x2, y5 = y4;
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
//	SDL_RenderDrawLine(Render, x2, y2, x3, y3);
//	SDL_RenderDrawLine(Render, x4, y4, x5, y5);
//}


void drawV(int x, int y, int dy)
{
	int X = x, Y = y;
	int ch = 1;
	if (dy >= 0)
		ch = -1;
	if (Y - 35 < 0)
		Y = 36;
	if (Y - 15 > frameHeight)
		Y = frameHeight + 14;
	if (ch == 1 && X - 15 < 0)
		X = 16;
	if (ch == -1 && X + 25 > frameWidth)
		X = frameWidth - 26;
	int x0 = X - 15, y0 = Y - ch * 30;
	int x1 = x0 + 5, y1 = y0 + 20;
	int x2 = x0 + 10, y2 = y0;
	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
}


void UP(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
	line5[N][M], float line6[N][M]) {
	line1[0][1] -= speed;
	line1[1][1] -= speed;
	line2[0][1] -= speed;
	line2[1][1] -= speed;
	line3[0][1] -= speed;
	line3[1][1] -= speed;
	line4[0][1] -= speed;
	line4[1][1] -= speed;
	line5[0][1] -= speed;
	line5[1][1] -= speed;
	line6[0][1] -= speed;
	line6[1][1] -= speed;
}


void DOWN(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
	line5[N][M], float line6[N][M]) {
	line1[0][1] += speed;
	line1[1][1] += speed;
	line2[0][1] += speed;
	line2[1][1] += speed;
	line3[0][1] += speed;
	line3[1][1] += speed;
	line4[0][1] += speed;
	line4[1][1] += speed;
	line5[0][1] += speed;
	line5[1][1] += speed;
	line6[0][1] += speed;
	line6[1][1] += speed;
}


void LEFT(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
	line5[N][M], float line6[N][M]) {
	line1[0][0] -= speed;
	line1[1][0] -= speed;
	line2[0][0] -= speed;
	line2[1][0] -= speed;
	line3[0][0] -= speed;
	line3[1][0] -= speed;
	line4[0][0] -= speed;
	line4[1][0] -= speed;
	line5[0][0] -= speed;
	line5[1][0] -= speed;
	line6[0][0] -= speed;
	line6[1][0] -= speed;
}


void RIGHT(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
	line5[N][M], float line6[N][M]) {
	line1[0][0] += speed;
	line1[1][0] += speed;
	line2[0][0] += speed;
	line2[1][0] += speed;
	line3[0][0] += speed;
	line3[1][0] += speed;
	line4[0][0] += speed;
	line4[1][0] += speed;
	line5[0][0] += speed;
	line5[1][0] += speed;
	line6[0][0] += speed;
	line6[1][0] += speed;
}


void TOUSER(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
	float line5[N][M], float line6[N][M]) {
	line1[0][2] -= speed;
	line1[1][2] -= speed;
	line2[0][2] -= speed;
	line2[1][2] -= speed;
	line3[0][2] -= speed;
	line3[1][2] -= speed;
	line4[0][2] -= speed;
	line4[1][2] -= speed;
	line5[0][2] -= speed;
	line5[1][2] -= speed;
	line6[0][2] -= speed;
	line6[1][2] -= speed;
}


void FROMUSER(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
	float line5[N][M], float line6[N][M]) {
	line1[0][2] += speed;
	line1[1][2] += speed;
	line2[0][2] += speed;
	line2[1][2] += speed;
	line3[0][2] += speed;
	line3[1][2] += speed;
	line4[0][2] += speed;
	line4[1][2] += speed;
	line5[0][2] += speed;
	line5[1][2] += speed;
	line6[0][2] += speed;
	line6[1][2] += speed;
}


void shadow(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
	line5[N][M], float line6[N][M])
{
	float mas[4][4] = { {line1[0][0], line1[0][1], line1[0][2], 1}, {line2[0][0], line2[0][1], line2[0][2], 1}, {line3[0][0], line3[0][1], line3[0][2], 1}, {line4[1][0], line4[1][1], line4[1][2], 1} };
	float win[4][4] = { {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1} };
	int xLight = -500;
	int yLight = -500;
	int zLight = 500;
	int xPl[3];
	int yPl[3];
	int zPl[3];
	xPl[0] = 0; yPl[0] = 780; zPl[0] = -80;
	xPl[1] = 300; yPl[1] = 780; zPl[1] = 20;
	xPl[2] = 150; yPl[2] = 900; zPl[2] = 180;

	int A = (yPl[1] - yPl[0]) * (zPl[2] - zPl[0]) - (yPl[2] - yPl[0]) * (zPl[1] - zPl[0]);
	int B = (zPl[1] - zPl[0]) * (xPl[2] - xPl[0]) - (zPl[2] - zPl[0]) * (xPl[1] - xPl[0]);
	int C = (xPl[1] - xPl[0]) * (yPl[2] - yPl[0]) - (xPl[2] - xPl[0]) * (yPl[1] - yPl[0]);
	int D = -(A * xPl[0] + B * yPl[0] + C * zPl[0]);
	int m = 0;
	int n = 0;
	int p = 0;
	int xSh[4], ySh[4], zSh[4];
	float t = 0;
	for (int i = 0; i < 4; i++)
	{
		m = xLight - mas[i][0];
		n = yLight - mas[i][1];
		p = zLight - mas[i][2];
		t = (float)(-A * mas[i][0] - B * mas[i][1] - C * mas[i][2] - D) / (A * m + B * n + C * p);
		xSh[i] = m * t + mas[i][0];
		ySh[i] = n * t + mas[i][1];
		zSh[i] = p * t + mas[i][2];
		
		//SDL_RenderDrawPoint(render, xSh[i], ySh[i]);


	}
	win[0][0] = xSh[0]; win[0][1] = ySh[0]; win[0][2] = zSh[0];
	win[1][0] = xSh[1]; win[1][1] = ySh[1]; win[1][2] = zSh[1];
	win[2][0] = xSh[2]; win[2][1] = ySh[2]; win[2][2] = zSh[2];
	win[3][0] = xSh[3]; win[3][1] = ySh[3]; win[3][2] = zSh[3];

	SDL_SetRenderDrawColor(Render, 100, 100, 100, 255);
	float Line1[N][M] = { { win[0][0], win[0][1], win[0][2], 1}, { win[1][0], win[1][1], win[1][2], 1}}, Line2[N][M] = { { win[1][0], win[1][1], win[1][2], 1}, { win[2][0], win[2][1], win[2][2], 1} }, Line3[N][M] = { { win[2][0], win[2][1], win[2][2], 1}, { win[0][0], win[0][1], win[0][2], 1} };
	paintOverTriangle(Line1, Line2, Line3, 1);
	
	SDL_SetRenderDrawColor(Render, 100, 100, 100, 255);
	float Line11[N][M] = {{win[0][0], win[0][1], win[0][2], 1}, {win[1][0], win[1][1], win[1][2], 1}}, Line12[N][M] = {{win[0][0], win[0][1], win[0][2], 1}, {win[3][0], win[3][1], win[3][2], 1}}, Line13[N][M] = {{win[1][0], win[1][1], win[1][2], 1}, {win[3][0], win[3][1], win[3][2], 1}};
	paintOverTriangle(Line11, Line12, Line13, 1);
	
	SDL_SetRenderDrawColor(Render, 100, 100, 100, 255);
	float Line21[N][M] = { {win[1][0], win[1][1], win[1][2], 1}, {win[2][0], win[2][1], win[2][2], 1} }, Line22[N][M] = { {win[1][0], win[1][1], win[1][2], 1}, {win[3][0], win[3][1], win[3][2], 1} }, Line23[N][M] = { {win[2][0], win[2][1], win[2][2], 1}, {win[3][0], win[3][1], win[3][2], 1} };
	paintOverTriangle(Line21, Line22, Line23, 1);
	
	SDL_SetRenderDrawColor(Render, 100, 100, 100, 255);
	float Line31[N][M] = { {win[2][0], win[2][1], win[2][2], 1}, {win[0][0], win[0][1], win[0][2], 1} }, Line32[N][M] = { {win[2][0], win[2][1], win[2][2], 1}, {win[3][0], win[3][1], win[3][2], 1} }, Line33[N][M] = { {win[0][0], win[0][1], win[0][2], 1}, {win[3][0], win[3][1], win[3][2], 1} };
	paintOverTriangle(Line31, Line32, Line33, 1);
	//FillColor(win[0][0], win[0][1], win[4][0], win[4][1], win[5][0], win[5][1], win[1][0], win[1][1], render);
	//FillColor(win[0][0], win[0][1], win[3][0], win[3][1], win[7][0], win[7][1], win[4][0], win[4][1], render);
	//FillColor(win[4][0], win[4][1], win[5][0], win[5][1], win[6][0], win[6][1], win[7][0], win[7][1], render);
	//FillColor(win[5][0], win[5][1], win[1][0], win[1][1], win[2][0], win[2][1], win[6][0], win[6][1], render);
	//FillColor(win[3][0], win[3][1], win[7][0], win[7][1], win[6][0], win[6][1], win[2][0], win[2][1], render);


	//// NEPRAV
	//FillColor(win[1][0], win[1][1], win[5][0], win[5][1], win[7][0], win[7][1], win[2][0], win[2][1], render);
	//// NEPRAV
	//FillColor(win[4][0], win[4][1], win[5][0], win[5][1], win[7][0], win[7][1], win[6][0], win[6][1], render);

	//// NEPRAV
	//FillColor(win[0][0], win[0][1], win[4][0], win[4][1], win[6][0], win[6][1], win[3][0], win[3][1], render);
	//FillColor(win[4][0], win[4][1], win[5][0], win[5][1], win[1][0], win[1][1], win[0][0], win[0][1], render);
	//FillColor(win[6][0], win[6][1], win[7][0], win[7][1], win[2][0], win[2][1], win[3][0], win[3][1], render);

}

//void shadow(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M],
//	float Line1[N][M], float Line2[N][M], float Line3[N][M], float Line4[N][M], float Line5[N][M], float Line6[N][M])
//{
//	float X1 = Line1[0][0], Y1 = Line1[0][1], Z1 = Line1[0][2];
//	float X2 = Line2[0][0], Y2 = Line2[0][1], Z2 = Line2[0][2];
//	float X3 = Line3[0][0], Y3 = Line3[0][1], Z3 = Line3[0][2];
//	float X4 = Line4[0][0], Y4 = Line4[0][1], Z4 = Line4[0][2];
//	float X5 = Line5[1][1], Y5 = Line5[1][1], Z5 = Line5[1][2];
//	float x1 = line1[0][0], y1 = line1[0][1], z1 = line1[0][2];
//	float x2 = line2[0][0], y2 = line2[0][1], z2 = line2[0][2];
//	float x3 = line3[0][0], y3 = line3[0][1], z3 = line3[0][2];
//	float x4 = line4[0][0], y4 = line4[0][1], z4 = line4[0][2];
//	float x5 = line5[1][1], y5 = line5[1][1], z5 = line5[1][2];
//	float x_light = 0, y_light = 0, z_light = 0;
//	float k, b;
//	float points[3][2];
//	float length;
//	k = Y1 / X1;
//	length = sqrt(Y1 * Y1 + X1 * X1);
//	points[0][1] = length * 1.5;
//	points[0][0] = length * 1.5 / k;
//	k = Y2 / X2;
//	length = sqrt(Y2 * Y2 + X2 * X2);
//	points[1][1] = length * 1.5;
//	points[1][0] = length * 1.5 / k;
//	k = Y5 / X5;
//	length = sqrt(Y5 * Y5 + X5 * X5);
//	points[2][1] = length * 1.5;
//	points[2][0] = length * 1.5 / k;
//	std::cout << "sdasdasd"<<"\n\n";
//
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//			std::cout << points[i][j] << "\n";
//	SDL_SetRenderDrawColor(Render, 0, 255, 0, 255);
//	SDL_RenderDrawLine(Render, points[0][0], points[0][1], points[1][0], points[1][1]);
//	SDL_RenderDrawLine(Render, points[1][0], points[1][1], points[2][0], points[2][1]);
//	SDL_RenderDrawLine(Render, points[2][0], points[2][1], points[0][0], points[0][1]);
//	
//	
//}

int main(int argc, char* argv[])
{
	float line1[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, line2[N][M] = { {0, 0, 0, 1 }, {0, 0, 0, 1} }, line3[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} };
	float line4[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1 } }, line5[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, line6[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} };
	int dx1, dx3, dy;
	int Dx1, Dx3, Dy;
	float Line1[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, Line2[N][M] = { {0, 0, 0, 1 }, {0, 0, 0, 1} }, Line3[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} };
	float Line4[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1 } }, Line5[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, Line6[N][M] = { { 0, 0, 0, 1 },
	{0, 0, 0, 1} };
	float cut_points[3][3];
	line1[0][0] = line3[1][0] = line4[0][0] = xA;
	line1[0][1] = line3[1][1] = line4[0][1] = yA;
	line1[0][2] = line3[1][2] = line4[0][2] = zA;
	line1[1][0] = line2[0][0] = line5[0][0] = xB;
	line1[1][1] = line2[0][1] = line5[0][1] = yB;
	line1[1][2] = line2[0][2] = line5[0][2] = zB;
	line2[1][0] = line3[0][0] = line6[0][0] = xC;
	line2[1][1] = line3[0][1] = line6[0][1] = yC;
	line2[1][2] = line3[0][2] = line6[0][2] = zC;
	line4[1][0] = line5[1][0] = line6[1][0] = xV;
	line4[1][1] = line5[1][1] = line6[1][1] = yV;
	line4[1][2] = line5[1][2] = line6[1][2] = zV;

	Line1[0][0] = Line3[1][0] = Line4[0][0] = xa;
	Line1[0][1] = Line3[1][1] = Line4[0][1] = ya;
	Line1[0][2] = Line3[1][2] = Line4[0][2] = za;
	Line1[1][0] = Line2[0][0] = Line5[0][0] = xb;
	Line1[1][1] = Line2[0][1] = Line5[0][1] = yb;
	Line1[1][2] = Line2[0][2] = Line5[0][2] = zb;
	Line2[1][0] = Line3[0][0] = Line6[0][0] = xc;
	Line2[1][1] = Line3[0][1] = Line6[0][1] = yc;
	Line2[1][2] = Line3[0][2] = Line6[0][2] = zc;
	Line4[1][0] = Line5[1][0] = Line6[1][0] = xv;
	Line4[1][1] = Line5[1][1] = Line6[1][1] = yv;
	Line4[1][2] = Line5[1][2] = Line6[1][2] = zv;

	rotateY(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, M_PI / 6);
	//equation_plane(Line1, Line2, Line3);
	

	if (Init())
	{
		bool quit = false;
		SDL_Event ever;
		std::cout << "---------------------------------------------------------" << std::endl;
		std::cout << "\t AD, WS, UJ - moving(X, Y, Z)\n\t <>, zx, qe - rotating(X, Y, Z)\n\t + --scaling" << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
		std::cout << "\n\t\t\tz = " << (line1[0][2] + line2[0][2] + line3[0][2] + line4[0][2]) / 4 << std::endl;
		while (!quit)
		{
			while (SDL_PollEvent(&ever) != 0)
				if (ever.type == SDL_QUIT)
					quit = true;
			//dx1 = line1[1][0] - line1[0][0];
			//dy = line5[1][1] - line5[0][1];
			//dx3 = line3[1][0] - line3[0][0];
			Dx1 = Line1[1][0] - Line1[0][0];
			Dy = Line5[1][1] - Line5[0][1];
			Dx3 = Line3[1][0] - Line3[0][0];
			if (_kbhit())
				switch (_getch()) {
				case 'w':
					UP(line1, line2, line3, line4, line5, line6);
					UP(Line1, Line2, Line3, Line4, Line5, Line6);
					break;
				case 's':
					DOWN(line1, line2, line3, line4, line5, line6);
					DOWN(Line1, Line2, Line3, Line4, Line5, Line6);
					break;
				case 'a':
					LEFT(line1, line2, line3, line4, line5, line6);
					LEFT(Line1, Line2, Line3, Line4, Line5, Line6);
					break;
				case 'd':
					RIGHT(line1, line2, line3, line4, line5, line6);
					RIGHT(Line1, Line2, Line3, Line4, Line5, Line6);
					break;
				case 'u':
					FROMUSER(line1, line2, line3, line4, line5, line6);
					FROMUSER(Line1, Line2, Line3, Line4, Line5, Line6);
					std::cout << "\n\t\t\tz = " << (line1[0][2] + line2[0][2]
						+ line3[0][2] + line4[0][2]) / 4 << std::endl;
					break;
				case 'j':
					TOUSER(line1, line2, line3, line4, line5, line6);
					TOUSER(Line1, Line2, Line3, Line4, Line5, Line6);
					std::cout << "\n\t\t\tz = " << (line1[0][2] + line2[0][2]
						+ line3[0][2] + line4[0][2]) / 4 << std::endl;
					break;
				case ',':
					rotateX(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, 1 * angle);					
					break;
				case '.':
					rotateX(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, -1 * angle);
					break;
				case 'e':
					rotateZ(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, 1 * angle);
					break;
				case 'q':
					rotateZ(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, -1 * angle);
					break;
				case 'z':
					rotateY(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, 1 * angle);
					break;
				case 'x':
					rotateY(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, -1 * angle);
					break;
				case '=':
					scaling(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, S);
					break;
				case '-':
					scaling(Line1, Line2, Line3, Line4, Line5, Line6, line1, line2, line3, line4, line5, line6, s);
					break;
				}
			SDL_SetRenderDrawColor(Render, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(Render);
			
			//paintOverSecond(Line1, Line2, Line3, Line4, Line5, Line6);
			findLine(line1, line2, line3, line4, line5, line6, Line1, Line2, Line3, Line4, Line5, Line6, cut_points);
			shadow(line1, line2, line3, line4, line5, line6);
			paintOver(line1, line2, line3, line4, line5, line6, Line1, Line2, Line3, Line4, Line5, Line6, cut_points);
			

			SDL_SetRenderDrawColor(Render, 255, 255, 255, 0x00);
			//paintOverTriangle(line1, line4, line5, 0);

			//system("pause");
			//drawA(line1[0][0], line1[0][1], dx1);
			//drawB(line1[1][0], line1[1][1], dx1);
			//drawC(line3[0][0], line3[0][1], dx3);
			//drawH(line3[1][0], line3[1][1], dx3);
			//drawV(line5[1][0], line5[1][1], dy);
			SDL_RenderPresent(Render);
		}
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
	}
	return 0;
}
