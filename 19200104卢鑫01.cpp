#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long long n;
	long long k;
	long long num;
	long long count = 0;
	vector<long long>a;
	cin >> n;
	cin >> k;
	for (long long i = 0; i < n; i++)
	{
		cin >> num;
		a.push_back(num);
	}
	for (long long i = 0; i < n-1; i++)
	{
		for (long long j = i + 1; j < n; j++)
		{
			if ((a[i]-a[j])%k==0)
				count++;
		}
	}
	cout << count << endl;
}