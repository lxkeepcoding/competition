#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	int num;
	int addmax = 0;
	int x = 0;
	int y = 0;
	int max;
	int max1;          
	int a;
	int b;
	int c;
	cin >> T;
	vector<int>v;
	vector<vector<int> >A;
	vector<vector<int> >B;
	vector<vector<int> >C;
	A.clear();
	for (int i = 0; i < T; i++)
	{
		v.clear();
		for (int j = 0; j < T; j++)
		{
			cin >> num;
			v.push_back(num);
		}
		A.push_back(v);
	}
	B.clear();
	for (int k = 0; k < T; k++)
	{
		v.clear();
		for (int l = 0; l < T; l++)
		{
			cin >> num;
			v.push_back(num);
		}
		B.push_back(v);
	}
	C.clear();
	for (int m = 0; m < T; m++)
	{
		v.clear();
		for (int n = 0; n < T; n++)
		{
			num = A[m][n] + B[m][n];
			v.push_back(num);
			if (m != n&&num>addmax)
			{
				addmax = num;
				x = m;
				y = n;
			}
		}
		C.push_back(v);
	}
	if (T == 3)
	{
		max1 = (C[0][1] + C[0][2] + C[1][2]) / 2 - C[0][1]>
			(C[0][1] + C[0][2] + C[1][2]) / 2 - C[0][2] ? (C[0][1] + C[0][2] + C[1][2]) / 2 - C[0][1] : 
			(C[0][1] + C[0][2] + C[1][2]) / 2 - C[0][2];
		max = max1 > (C[0][1] + C[0][2] + C[1][2]) / 2 - C[1][2] 
			? max1 : (C[0][1] + C[0][2] + C[1][2]) / 2 - C[1][2];
	}
	else
	{
		if (x != 0 && y != T)
		{
			a = (C[x][y] + C[0][y] + C[0][x]) / 2 - C[x][y];
			b = (C[x][y] + C[0][y] + C[0][x]) / 2 - C[0][y];
			c = (C[x][y] + C[0][y] + C[0][x]) / 2 - C[0][x];
			max1 = a > b ? a : b;
			max = max1 > c ? max1 : c;
		}
		if (x == 0 && y != T)
		{
			a = (C[0][y]+C[0][y+1]+C[y][y+1]) / 2 - C[x][y];
			b = (C[0][y] + C[0][y + 1] + C[y][y + 1]) / 2 - C[0][y+1];
			c = (C[0][y] + C[0][y + 1] + C[y][y + 1]) / 2 - C[y][y+1];
			max1 = a > b ? a : b;
			max = max1 > c ? max1 : c;
		}
		if (x != 0 && y == T)
		{
			a = (C[x][T] + C[x - 1][T] + C[x][x - 1]) / 2 - C[x][y];
			b = (C[x][T] + C[x - 1][T] + C[x][x - 1]) / 2 - C[x-1][T];
			c = (C[x][T] + C[x - 1][T] + C[x][x - 1]) / 2 - C[x][x-1];
			max1 = a > b ? a : b;
			max = max1 > c ? max1 : c;
		}
		if (x == 0 && y == T)
		{
			a = (C[0][T] + C[0][T - 1] + C[T - 1][T]) / 2 - C[0][T];
			b = (C[0][T] + C[0][T - 1] + C[T - 1][T]) / 2 - C[0][T-1];
			c = (C[0][T] + C[0][T - 1] + C[T - 1][T]) / 2 - C[T-1][T];
			max1 = a > b ? a : b;
			max = max1 > c ? max1 : c;
		}
	}
	cout << max << endl;
}