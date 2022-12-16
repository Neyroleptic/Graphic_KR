//#define _USE_MATH_DEFINES
//
//#include <SDL.h>
//#include <cmath>
//#include <iostream>
//#include <conio.h>
//
//
//const int frameHeight = 750;
//const int frameWidth = 750;
//const int N = 2;
//const int M = 4;
//const int speed = 5;
//const float S = 1.1;
//const float s = 10.0 / 11;
//const float angle = M_PI / 180;
//const float xA = 100, yA = 300, zA = 0, xB = 100, yB = 300, zB = 200, xC = 300, yC = 300, zC = 200, xH = 300, yH = 300, zH = 0, xV = 200, yV = 100, zV = 100;
//const int color1 = 255, color2 = 230, color3 = 210, color4 = 180, color5 = 150;
//
//
//void multing(float lin[N][M], float matrix[M][M])
//{
//	float res[N][M] = { {0, 0, 0, 0}, {0, 0, 0, 0} };
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			for (int k = 0; k < M; k++)
//			{
//				res[i][j] += (lin[i][k] * matrix[k][j]);
//			}
//		}
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			lin[i][j] = res[i][j];
//		}
//	}
//}
//
//
//void rotateX(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
//	float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M], float angle)
//{
//	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[0][0] + line5[1][0]) / 5,
//		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[0][1] + line5[1][1]) / 5, zc =
//		(line1[0][2] + line2[0][2] + line3[0][2] + line4[0][2] + line5[1][2]) / 5;
//	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
//	1} };
//	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
//	};
//	float m_rotate[M][M] = { {cos(angle), 0, sin(angle), 0}, {0, 1, 0, 0}, {-sin(angle),
//	0, cos(angle), 0}, {0 ,0 , 0, 1} };
//	multing(line1, first_rot);
//	multing(line1, m_rotate);
//	multing(line1, second_rot);
//	multing(line2, first_rot);
//	multing(line2, m_rotate);
//	multing(line2, second_rot);
//	multing(line3, first_rot);
//	multing(line3, m_rotate);
//	multing(line3, second_rot);
//	multing(line4, first_rot);
//	multing(line4, m_rotate);
//	multing(line4, second_rot);
//	multing(line5, first_rot);
//	multing(line5, m_rotate);
//	multing(line5, second_rot);
//	multing(line6, first_rot);
//	multing(line6, m_rotate);
//	multing(line6, second_rot);
//	multing(line7, first_rot);
//	multing(line7, m_rotate);
//	multing(line7, second_rot);
//	multing(line8, first_rot);
//	multing(line8, m_rotate);
//	multing(line8, second_rot);
//}
//
//
//void rotateY(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
//	float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M], float angle)
//{
//	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[0][0] + line5[1][0]) / 5,
//		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[0][1] + line5[1][1]) / 5, zc =
//		(line1[0][2] + line2[0][2] + line3[0][2] + line4[0][2] + line5[1][2]) / 5;
//	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
//	1} };
//	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
//	};
//	float m_rotate[M][M] = { {1, 0, 0, 0}, {0, cos(angle), sin(angle), 0}, {0, -
//	sin(angle), cos(angle), 0}, {0, 0, 0, 1} };
//	multing(line1, first_rot);
//	multing(line1, m_rotate);
//	multing(line1, second_rot);
//	multing(line2, first_rot);
//	multing(line2, m_rotate);
//	multing(line2, second_rot);
//	multing(line3, first_rot);
//	multing(line3, m_rotate);
//	multing(line3, second_rot);
//	multing(line4, first_rot);
//	multing(line4, m_rotate);
//	multing(line4, second_rot);
//	multing(line5, first_rot);
//	multing(line5, m_rotate);
//	multing(line5, second_rot);
//	multing(line6, first_rot);
//	multing(line6, m_rotate);
//	multing(line6, second_rot);
//	multing(line7, first_rot);
//	multing(line7, m_rotate);
//	multing(line7, second_rot);
//	multing(line8, first_rot);
//	multing(line8, m_rotate);
//	multing(line8, second_rot);
//}
//
//
//void rotateZ(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
//	float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M], float angle)
//{
//	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[0][0] + line5[1][0]) / 5,
//		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[0][1] + line5[1][1]) / 5, zc =
//		(line1[0][2] + line2[0][2] + line3[0][2] + line4[0][2] + line5[1][2]) / 5;
//	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
//	1} };
//	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
//	};
//	float m_rotate[M][M] = { {cos(angle), sin(angle), 0, 0}, {-sin(angle), cos(angle), 0,
//	0}, {0, 0, 1, 0}, {0 ,0 , 0, 1} };
//	multing(line1, first_rot);
//	multing(line1, m_rotate);
//	multing(line1, second_rot);
//	multing(line2, first_rot);
//	multing(line2, m_rotate);
//	multing(line2, second_rot);
//	multing(line3, first_rot);
//	multing(line3, m_rotate);
//	multing(line3, second_rot);
//	multing(line4, first_rot);
//	multing(line4, m_rotate);
//	multing(line4, second_rot);
//	multing(line5, first_rot);
//	multing(line5, m_rotate);
//	multing(line5, second_rot);
//	multing(line6, first_rot);
//	multing(line6, m_rotate);
//	multing(line6, second_rot);
//	multing(line7, first_rot);
//	multing(line7, m_rotate);
//	multing(line7, second_rot);
//	multing(line8, first_rot);
//	multing(line8, m_rotate);
//	multing(line8, second_rot);
//}
//
//
//void scaling(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
//	float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M], float S)
//{
//	float xc = (line1[0][0] + line2[0][0] + line3[0][0] + line4[0][0] + line5[1][0]) / 5,
//		yc = (line1[0][1] + line2[0][1] + line3[0][1] + line4[0][1] + line5[1][1]) / 5, zc =
//		(line4[0][2] + line5[1][2]) / 2;
//	float first_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {-xc, -yc, -zc,
//	1} };
//	float second_rot[M][M] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {xc, yc, zc, 1}
//	};
//	float m_scale[M][M] = { {S,0,0,0},{0,S,0,0} ,{0,0,S,0}, {0, 0, 0, 1 } };
//	multing(line1, first_rot);
//	multing(line1, m_scale);
//	multing(line1, second_rot);
//	multing(line2, first_rot);
//	multing(line2, m_scale);
//	multing(line2, second_rot);
//	multing(line3, first_rot);
//	multing(line3, m_scale);
//	multing(line3, second_rot);
//	multing(line4, first_rot);
//	multing(line4, m_scale);
//	multing(line4, second_rot);
//	multing(line5, first_rot);
//	multing(line5, m_scale);
//	multing(line5, second_rot);
//	multing(line6, first_rot);
//	multing(line6, m_scale);
//	multing(line6, second_rot);
//	multing(line7, first_rot);
//	multing(line7, m_scale);
//	multing(line7, second_rot);
//	multing(line8, first_rot);
//	multing(line8, m_scale);
//	multing(line8, second_rot);
//}
//
//
//SDL_Window* Window = NULL;
//SDL_Renderer* Render = NULL;
//
//
//void paintOverSquare(float line1[N][M], float line2[N][M], float line3[N][M], float
//	line4[N][M])
//{
//	float x1 = line1[0][0], y1 = line1[0][1];
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
//	}
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, line1[0][0], line1[0][1], line1[1][0], line1[1][1]);
//	SDL_RenderDrawLine(Render, line2[0][0], line2[0][1], line2[1][0], line2[1][1]);
//	SDL_RenderDrawLine(Render, line3[0][0], line3[0][1], line3[1][0], line3[1][1]);
//	SDL_RenderDrawLine(Render, line4[0][0], line4[0][1], line4[1][0], line4[1][1]);
//}
//
//
//void paintOverTriangle(float line1[N][M], float line2[N][M], float line3[N][M])
//{
//	float x1 = line1[0][0], y1 = line1[0][1];
//	float x2 = line2[0][0], y2 = line2[0][1];
//	float x3 = line3[1][0], y3 = line3[1][1];
//	int miny = fminf(y1, fminf(y2, y3));
//	int maxy = fmaxf(y1, fmaxf(y2, y3));
//	int minx = fminf(x1, fminf(x2, x3));
//	int maxx = fmaxf(x1, fmaxf(x2, x3));
//	int y;
//	int x;
//	int a;
//	int b;
//	int c;
//	int e;
//	for (int y = miny; y <= maxy; y++)
//	{
//		for (int x = maxx; x >= minx; x--)
//		{
//			a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
//			b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
//			c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);
//			if ((a < 0 && b < 0 && c < 0) || (a > 0 && b > 0 && c > 0))
//			{
//				SDL_RenderDrawPoint(Render, x, y);
//			}
//		}
//		x = maxx;
//	}
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, line1[0][0], line1[0][1], line1[1][0], line1[1][1]);
//	SDL_RenderDrawLine(Render, line2[0][0], line2[0][1], line2[1][0], line2[1][1]);
//	SDL_RenderDrawLine(Render, line3[0][0], line3[0][1], line3[1][0], line3[1][1]);
//}
//
//
//int compare(const void* x1, const void* x2) { return (*(int*)x1 - *(int*)x2); }
//
//
//void paintOver(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M])
//{
//	int zc1 = (line1[0][2] + line2[0][2] + line3[0][2] + line4[0][2]) / 4;
//	int zc2 = (line1[0][2] + line6[0][2] + line5[1][2]) / 3;
//	int zc3 = (line2[0][2] + line7[0][2] + line6[1][2]) / 3;
//	int zc4 = (line3[0][2] + line8[0][2] + line7[1][2]) / 3;
//	int zc5 = (line4[0][2] + line5[0][2] + line8[1][2]) / 3;
//	int mxz[5] = { zc1, zc2, zc3, zc4, zc5 };
//	qsort(mxz, 5, sizeof(int), compare);
//	if (mxz[1] == zc1) {
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		paintOverSquare(line1, line2, line3, line4);
//	}
//	if (mxz[1] == zc2) {
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//		paintOverTriangle(line1, line6, line5);
//	}
//	if (mxz[1] == zc3) {
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		paintOverTriangle(line2, line7, line6);
//	}
//	if (mxz[1] == zc4) {
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line8, line7);
//	}
//	if (mxz[1] == zc5) {
//		SDL_SetRenderDrawColor(Render, color5, color5, color5, 255);
//		paintOverTriangle(line4, line5, line8);
//	}
//	if (mxz[2] == zc1) {
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		paintOverSquare(line1, line2, line3, line4);
//	}
//	if (mxz[2] == zc2) {
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//		paintOverTriangle(line1, line6, line5);
//	}
//	if (mxz[2] == zc3) {
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		paintOverTriangle(line2, line7, line6);
//	}
//	if (mxz[2] == zc4) {
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line8, line7);
//	}
//	if (mxz[2] == zc5) {
//		SDL_SetRenderDrawColor(Render, color5, color5, color5, 255);
//		paintOverTriangle(line4, line5, line8);
//	}
//	if (mxz[3] == zc1) {
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		paintOverSquare(line1, line2, line3, line4);
//	}
//	if (mxz[3] == zc2) {
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//		paintOverTriangle(line1, line6, line5);
//	}
//	if (mxz[3] == zc3) {
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		paintOverTriangle(line2, line7, line6);
//	}
//	if (mxz[3] == zc4) {
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line8, line7);
//	}
//	if (mxz[3] == zc5) {
//		SDL_SetRenderDrawColor(Render, color5, color5, color5, 255);
//		paintOverTriangle(line4, line5, line8);
//	}
//	if (mxz[4] == zc1) {
//		SDL_SetRenderDrawColor(Render, color1, color1, color1, 255);
//		paintOverSquare(line1, line2, line3, line4);
//	}
//	if (mxz[4] == zc2) {
//		SDL_SetRenderDrawColor(Render, color2, color2, color2, 255);
//		paintOverTriangle(line1, line6, line5);
//	}
//	if (mxz[4] == zc3) {
//		SDL_SetRenderDrawColor(Render, color3, color3, color3, 255);
//		paintOverTriangle(line2, line7, line6);
//	}
//	if (mxz[4] == zc4) {
//		SDL_SetRenderDrawColor(Render, color4, color4, color4, 255);
//		paintOverTriangle(line3, line8, line7);
//	}
//	if (mxz[4] == zc5) {
//		SDL_SetRenderDrawColor(Render, color5, color5, color5, 255);
//		paintOverTriangle(line4, line5, line8);
//	}
//}
//
//
//bool Init() {
//	bool success = true;
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//		std::cout << SDL_GetError() << std::endl;
//	else {
//		Window = SDL_CreateWindow("Lines", SDL_WINDOWPOS_UNDEFINED,
//			SDL_WINDOWPOS_UNDEFINED, frameWidth, frameHeight, SDL_WINDOW_SHOWN);
//		if (Window == NULL)
//			std::cout << SDL_GetError() << std::endl;
//		else
//			Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
//	}
//	return success;
//}
//
//
//void drawA(int x, int y, int dx)
//{
//	int ch = 1;
//	if (dx < 0)
//		ch = -1;
//	int X = x, Y = y;
//	if (Y - 35 < 0)
//		Y = 36;
//	if (Y - 15 > frameHeight)
//		Y = frameHeight + 14;
//	if (ch == 1 && X - 15 < 0)
//		X = 16;
//	if (ch == -1 && X + 15 > frameWidth)
//		X = frameWidth - 16;
//	int x0 = X - (ch * 15), y0 = Y - 15;
//	int x1 = X - (ch * 10), y1 = Y - 35;
//	int x2 = X - (ch * 5), y2 = y0;
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
//	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
//	SDL_RenderDrawLine(Render, (x1 + x0) / 2, (y0 + y1) / 2, (x2 + x1) / 2, (y0 + y1) /
//		2);
//}
//
//
//void drawB(int x, int y, int dx)
//{
//	int X = x, Y = y;
//	int ch = 1;
//	if (dx < 0)
//		ch = -1;
//	if (Y - 35 < 0)
//		Y = 36;
//	if (Y - 15 > frameHeight)
//		Y = frameHeight + 14;
//	if (ch == 1 && X - 15 < 0)
//		X = 16;
//	if (ch == -1 && X + 27 > frameWidth)
//		X = frameWidth - 28;
//	int x0 = X - (ch * 15), y0 = Y - 15;
//	int x1 = x0, y1 = Y - 35;
//	int x2 = x0 + 10, y2 = y1;
//	int x3 = x2, y3 = (y0 - y1) / 2 + y1 - 2;
//	int x4 = x2 + 2, y4 = y3;
//	int x5 = x4, y5 = y0;
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
//	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
//	SDL_RenderDrawLine(Render, x2, y2, x3, y3);
//	SDL_RenderDrawLine(Render, x4, y4, x5, y5);
//	SDL_RenderDrawLine(Render, x5, y5, x0, y0);
//	SDL_RenderDrawLine(Render, x0, (y0 + y1) / 2 - 2, x4, (y0 + y1) / 2 - 2);
//}
//
//
//void drawC(int x, int y, int dx)
//{
//	int ch = 1;
//	if (dx <= 0)
//		ch = -1;
//	int X = x, Y = y;
//	if (Y - 35 < 0)
//		Y = 36;
//	if (Y - 15 > frameHeight)
//		Y = frameHeight + 14;
//	if (ch == 1 && X - 25 < 0)
//		X = 26;
//	if (ch == -1 && X + 15 > frameWidth)
//		X = frameWidth - 16;
//	int x0 = X - (ch * 15), y0 = Y - 15;
//	int x1 = x0 - 10, y1 = y0;
//	int x2 = x1, y2 = Y - 35;
//	int x3 = x0, y3 = y2;
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
//	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
//	SDL_RenderDrawLine(Render, x2, y2, x3, y3);
//	SDL_RenderDrawLine(Render, (x1 + x0) / 2, (y0 + y1) / 2, (x2 + x1) / 2, (y0 + y1) / 2);
//}
//
//
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
//
//
//void drawV(int x, int y, int dy)
//{
//	int X = x, Y = y;
//	int ch = 1;
//	if (dy >= 0)
//		ch = -1;
//	if (Y - 35 < 0)
//		Y = 36;
//	if (Y - 15 > frameHeight)
//		Y = frameHeight + 14;
//	if (ch == 1 && X - 15 < 0)
//		X = 16;
//	if (ch == -1 && X + 25 > frameWidth)
//		X = frameWidth - 26;
//	int x0 = X - 15, y0 = Y - ch * 30;
//	int x1 = x0 + 5, y1 = y0 + 20;
//	int x2 = x0 + 10, y2 = y0;
//	SDL_SetRenderDrawColor(Render, 255, 0, 0, 0);
//	SDL_RenderDrawLine(Render, x0, y0, x1, y1);
//	SDL_RenderDrawLine(Render, x1, y1, x2, y2);
//}
//
//
//void UP(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
//	line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M]) {
//	line1[0][1] -= speed;
//	line1[1][1] -= speed;
//	line2[0][1] -= speed;
//	line2[1][1] -= speed;
//	line3[0][1] -= speed;
//	line3[1][1] -= speed;
//	line4[0][1] -= speed;
//	line4[1][1] -= speed;
//	line5[0][1] -= speed;
//	line5[1][1] -= speed;
//	line6[0][1] -= speed;
//	line6[1][1] -= speed;
//	line7[0][1] -= speed;
//	line7[1][1] -= speed;
//	line8[0][1] -= speed;
//	line8[1][1] -= speed;
//}
//
//
//void DOWN(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
//	line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M]) {
//	line1[0][1] += speed;
//	line1[1][1] += speed;
//	line2[0][1] += speed;
//	line2[1][1] += speed;
//	line3[0][1] += speed;
//	line3[1][1] += speed;
//	line4[0][1] += speed;
//	line4[1][1] += speed;
//	line5[0][1] += speed;
//	line5[1][1] += speed;
//	line6[0][1] += speed;
//	line6[1][1] += speed;
//	line7[0][1] += speed;
//	line7[1][1] += speed;
//	line8[0][1] += speed;
//	line8[1][1] += speed;
//}
//
//
//void LEFT(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
//	line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M]) {
//	line1[0][0] -= speed;
//	line1[1][0] -= speed;
//	line2[0][0] -= speed;
//	line2[1][0] -= speed;
//	line3[0][0] -= speed;
//	line3[1][0] -= speed;
//	line4[0][0] -= speed;
//	line4[1][0] -= speed;
//	line5[0][0] -= speed;
//	line5[1][0] -= speed;
//	line6[0][0] -= speed;
//	line6[1][0] -= speed;
//	line7[0][0] -= speed;
//	line7[1][0] -= speed;
//	line8[0][0] -= speed;
//	line8[1][0] -= speed;
//}
//
//
//void RIGHT(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M], float
//	line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M]) {
//	line1[0][0] += speed;
//	line1[1][0] += speed;
//	line2[0][0] += speed;
//	line2[1][0] += speed;
//	line3[0][0] += speed;
//	line3[1][0] += speed;
//	line4[0][0] += speed;
//	line4[1][0] += speed;
//	line5[0][0] += speed;
//	line5[1][0] += speed;
//	line6[0][0] += speed;
//	line6[1][0] += speed;
//	line7[0][0] += speed;
//	line7[1][0] += speed;
//	line8[0][0] += speed;
//	line8[1][0] += speed;
//}
//
//
//void TOUSER(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
//	float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M]) {
//	line1[0][2] -= speed;
//	line1[1][2] -= speed;
//	line2[0][2] -= speed;
//	line2[1][2] -= speed;
//	line3[0][2] -= speed;
//	line3[1][2] -= speed;
//	line4[0][2] -= speed;
//	line4[1][2] -= speed;
//	line5[0][2] -= speed;
//	line5[1][2] -= speed;
//	line6[0][2] -= speed;
//	line6[1][2] -= speed;
//	line7[0][2] -= speed;
//	line7[1][2] -= speed;
//	line8[0][2] -= speed;
//	line8[1][2] -= speed;
//}
//
//
//void FROMUSER(float line1[N][M], float line2[N][M], float line3[N][M], float line4[N][M],
//	float line5[N][M], float line6[N][M], float line7[N][M], float line8[N][M]) {
//	line1[0][2] += speed;
//	line1[1][2] += speed;
//	line2[0][2] += speed;
//	line2[1][2] += speed;
//	line3[0][2] += speed;
//	line3[1][2] += speed;
//	line4[0][2] += speed;
//	line4[1][2] += speed;
//	line5[0][2] += speed;
//	line5[1][2] += speed;
//	line6[0][2] += speed;
//	line6[1][2] += speed;
//	line7[0][2] += speed;
//	line7[1][2] += speed;
//	line8[0][2] += speed;
//	line8[1][2] += speed;
//}
//
//
//int main(int argc, char* argv[])
//{
//	float line1[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, line2[N][M] = { {0, 0, 0, 1 },
//	{0, 0, 0, 1} }, line3[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, line4[N][M] = { { 0, 0, 0, 1
//	}, {0, 0, 0, 1} };
//	float line5[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, line6[N][M] = { { 0, 0, 0, 1 },
//	{0, 0, 0, 1} }, line7[N][M] = { { 0, 0, 0, 1 }, {0, 0, 0, 1} }, line8[N][M] = { { 0, 0, 0, 1
//	}, {0, 0, 0, 1} };
//	int dx1, dx3, dy;
//	line1[0][0] = line4[1][0] = line5[0][0] = xA;
//	line1[0][1] = line4[1][1] = line5[0][1] = yA;
//	line1[0][2] = line4[1][2] = line5[0][2] = zA;
//	line1[1][0] = line2[0][0] = line6[0][0] = xB;
//	line1[1][1] = line2[0][1] = line6[0][1] = yB;
//	line1[1][2] = line2[0][2] = line6[0][2] = zB;
//	line2[1][0] = line3[0][0] = line7[0][0] = xC;
//	line2[1][1] = line3[0][1] = line7[0][1] = yC;
//	line2[1][2] = line3[0][2] = line7[0][2] = zC;
//	line3[1][0] = line4[0][0] = line8[0][0] = xH;
//	line3[1][1] = line4[0][1] = line8[0][1] = yH;
//	line3[1][2] = line4[0][2] = line8[0][2] = zH;
//	line5[1][0] = line6[1][0] = line7[1][0] = line8[1][0] = xV;
//	line5[1][1] = line6[1][1] = line7[1][1] = line8[1][1] = yV;
//	line5[1][2] = line6[1][2] = line7[1][2] = line8[1][2] = zV;
//	if (Init())
//	{
//		bool quit = false;
//		SDL_Event ever;
//		std::cout << "---------------------------------------------------------" << std::endl;
//		std::cout << "\t AD, WS, UJ - moving(X, Y, Z)\n\t <>, zx, qe - rotating(X, Y, Z)\n\t + --scaling" << std::endl;
//		std::cout << "---------------------------------------------------------" << std::endl;
//		std::cout << "\n\t\t\tz = " << (line1[0][2] + line2[0][2] + line3[0][2] + line4[0][2]) / 4 << std::endl;
//		while (!quit)
//		{
//			while (SDL_PollEvent(&ever) != 0)
//				if (ever.type == SDL_QUIT)
//					quit = true;
//			dx1 = line1[1][0] - line1[0][0];
//			dy = line5[1][1] - line5[0][1];
//			dx3 = line3[1][0] - line3[0][0];
//			if (_kbhit())
//				switch (_getch()) {
//				case 'w':
//					UP(line1, line2, line3, line4, line5, line6, line7,
//						line8);
//					break;
//				case 's':
//					DOWN(line1, line2, line3, line4, line5, line6, line7,
//						line8);
//					break;
//				case 'a':
//					LEFT(line1, line2, line3, line4, line5, line6, line7,
//						line8);
//					break;
//				case 'd':
//					RIGHT(line1, line2, line3, line4, line5, line6, line7,
//						line8);
//					break;
//				case 'u':
//					FROMUSER(line1, line2, line3, line4, line5, line6, line7,
//						line8);
//					std::cout << "\n\t\t\tz = " << (line1[0][2] + line2[0][2]
//						+ line3[0][2] + line4[0][2]) / 4 << std::endl;
//					break;
//				case 'j':
//					TOUSER(line1, line2, line3, line4, line5, line6, line7,
//						line8);
//					std::cout << "\n\t\t\tz = " << (line1[0][2] + line2[0][2]
//						+ line3[0][2] + line4[0][2]) / 4 << std::endl;
//					break;
//				case ',':
//					rotateX(line1, line2, line3, line4, line5, line6, line7,
//						line8, 1 * angle);
//					break;
//				case '.':
//					rotateX(line1, line2, line3, line4, line5, line6, line7,
//						line8, -1 * angle);
//					break;
//				case 'e':
//					rotateZ(line1, line2, line3, line4, line5, line6, line7,
//						line8, 1 * angle);
//					break;
//				case 'q':
//					rotateZ(line1, line2, line3, line4, line5, line6, line7,
//						line8, -1 * angle);
//					break;
//				case 'z':
//					rotateY(line1, line2, line3, line4, line5, line6, line7,
//						line8, 1 * angle);
//					break;
//				case 'x':
//					rotateY(line1, line2, line3, line4, line5, line6, line7,
//						line8, -1 * angle);
//					break;
//				case '=':
//					scaling(line1, line2, line3, line4, line5, line6, line7,
//						line8, S);
//					break;
//				case '-':
//					scaling(line1, line2, line3, line4, line5, line6, line7,
//						line8, s);
//					break;
//				}
//			SDL_SetRenderDrawColor(Render, 0x00, 0x00, 0x00, 0x00);
//			SDL_RenderClear(Render);
//			paintOver(line1, line2, line3, line4, line5, line6, line7, line8);
//			drawA(line1[0][0], line1[0][1], dx1);
//			drawB(line1[1][0], line1[1][1], dx1);
//			drawC(line3[0][0], line3[0][1], dx3);
//			drawH(line3[1][0], line3[1][1], dx3);
//			drawV(line5[1][0], line5[1][1], dy);
//			SDL_RenderPresent(Render);
//		}
//	}
//	else
//	{
//		std::cout << SDL_GetError() << std::endl;
//	}
//	return 0;
//}
