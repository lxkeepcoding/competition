#define _CRT_SECURE_NO_WARNINGS   1

#define G 10.00
#include<iostream>
#include<string>
#include<vector>
using namespace std;

float GetY(float vx,float vy,float x)
{
	return -G / vx / vx/2.00*x*x + vy / vx*x;
}
int main()
{
	int T; 
	vector<string>result;
	cin >> T;
	float vx;
	float vy;
	float x0;
	float x1;
	float y0;
	while (T)
	{
		cin >> vx;
		cin >> vy;
		cin >> x0;
		cin >> x1;
		cin >> y0;
		if (GetY(vx, vy, x0) <= y0)
		{
			result.push_back("No");
		}
		else
		{
			if (GetY(vx, vy, x1) < y0)
			{
				result.push_back("Yes");
			}
			if (GetY(vx, vy, x1) == y0)
			{
				result.push_back("No");
			}
			if (GetY(vx, vy, x1)>y0&&GetY(vx, vy, (2 * x1 - x0)) < y0)
			{
				result.push_back("Yes");
			}
			if (GetY(vx, vy, x1)>y0&&GetY(vx, vy, (2 * x1 - x0)) >= y0)
			{
				result.push_back("No");
			}
		}
		T--;
	}

	for (auto e : result)
	{
		cout << e <<endl;
	}
}

