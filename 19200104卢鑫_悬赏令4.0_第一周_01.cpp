#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//判断素数
bool IsPrimer(int n)
{
	for (int i = 2; i <= sqrt(n); i++) 
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
//寻找素数因数
int FoundPrimer(int dv,int m)
{
	for (int i = 2;; i++)
	{
		if (IsPrimer(i))
		{
			if ((i - m)>=dv)
				return i;
		}
	}
}
//得到最小正整数
int GetAnswer(int dv)
{
	int x = FoundPrimer(dv, 1);
	int y = FoundPrimer(dv, x);
	return x*y;
}
int main()
{
	int input = 0;
	int T = 0;
	cin >> T;
	vector<int>d;
	for (int i = 0; i < T; i++)
	{
		cin>>input;
		d.push_back(input);
	}
	for (int j = 0; j < d.size(); j++)
	{
		cout << GetAnswer(d[j]) << endl;
	}
	return 0;
	
}