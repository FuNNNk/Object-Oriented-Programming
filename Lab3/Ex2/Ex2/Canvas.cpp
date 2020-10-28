#define _CRT_SECURE_NO_WARNINGS
#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height)
{
	this->height = height;
	this->width = width;
	canvas = (char**)malloc(height * sizeof(char*));
	for (int i = 0; i < height; i++) 
		canvas[i] = (char*)malloc((width) * sizeof(char));
	for (int i = 0; i < height; i++) {
		memset(canvas[i], ' ', (width)* sizeof(char) );
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (sqrt((x - i) * (x - i) + (y - j) * (y - j)) <= float(ray+ 0.5) && 
				sqrt((x - i) * (x - i) + (y - j) * (y - j)) >= float(ray - 0.5))
				canvas[i][j] = ch;
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (sqrt((x - i) * (x - i) + (y - j) * (y - j)) <= float(ray + 0.5))
				canvas[i][j] = ch;
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			if(i==top || i==bottom || j==left || j==right)
				canvas[i][j] = ch;
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			canvas[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	canvas[x][y]=ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int deltax = x2 - x1;
	int deltay = y2 - y1;
	int x = x1;
	int y = y1;
	int p = 2 * deltay - deltax;
	while(x<x2) {
		if (p >= 0) {
			canvas[x][y] = ch;
			y = y + 1;
			p = p + 2 * deltay - 2 * deltax;
		}
		else {
			canvas[x][y] = ch;
			p = p + 2 * deltay;
		}
		x=x+1;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			printf("%c ", canvas[i][j]);
		}
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++) {
		memset(canvas[i], ' ', (width) * sizeof(char));
	}
}
