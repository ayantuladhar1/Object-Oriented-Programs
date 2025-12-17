#include "Header.h"
#include <iostream>
#include <vector>
using namespace std;

Grid::Grid(int _x, int _y)
{
	X = _x;
	Y = _y;

	for (int i = 0; i < X; i++)
	{
		vector<int> a;
		for (int j = 0; j < Y; j++)
		{
			a.push_back(0);
		}
		grid.push_back(a);

	}
}

void Grid::a1random()
{
	int n = (X * Y) / 3;
	for (int i = 0; i <= n; i++) {
		int k = rand() % X;
		int l = rand() % Y;
		grid[k][l] = 1;
	}
	

}

void Grid::a2random()
{
	int n = (X * Y) / 3;
	for (int i = 0; i <= n; i++)
	{
		int k = rand() % X;
		int l = rand() % Y;
		grid[k][l] = 1;
	}

}

void Grid::a3random()
{
	int n = (X * Y) / 3;
	for (int i = 0; i <= n; i++)
	{
		int k = rand() % X;
		int l = rand() % Y;
		grid[k][l] = 1;
	}

}

void Grid::fill (const Grid& a1, const Grid& a2, Grid& a3)
{

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (a1.grid[i][j] == 1 && a2.grid[i][j] == 1)
				a3.grid[i][j] = 1;
			else
				a3.grid[i][j] = 0;
		}
	}
}