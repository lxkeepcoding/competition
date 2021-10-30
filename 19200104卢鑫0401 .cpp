#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<vector>
using namespace std;

int GetAi(int a1, int d, int n1)
{
	  return a1 + n1*d - d;
}
int GetBi(int a1,int d,int n2)
{
	return n2*(2 * a1 + n2*d - d) / 2;
}
int Geti(int n)
{
	return n*(n + 1) / 2;
}
int main()
{
	int a1;
	int d;
	int T;
	int x;
	int n = 1;
	int i = 1;
	int sum = 0;
	vector<int>k;
	cin >> a1;
	cin >> d;
	cin >> T;
	while (T)
	{
		cin >> x;
		while (sum < x)
		{
			sum += GetBi(a1, d, n);
			n++;
		}
	
		if (sum == x)
		{
			n=n - 1;
			k.push_back(Geti(n));
		}
		else
		{
			n = n - 1;
			sum = sum - GetBi(a1, d, n);
			while (sum < x)
			{
				sum += GetAi(a1,d,i);
				i++;
			}
			k.push_back(Geti(n-1) + i - 1);
		}
		n = 1;
		i = 1;
		sum = 0;
		T--;
	}
	for (auto e : k)
	{
		cout << e << endl;
	}
	return 0;
}