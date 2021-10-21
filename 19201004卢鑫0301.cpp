#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<vector>
using namespace std;
vector<int> bubble_sort(vector<int> v)
{
	for (int i = 0; i < v.size() - 1; i++)
	for (int j = 0; j < v.size() - 1 - i; j++)
	{
		if (v[j] < v[j + 1])
		{
			int temp = v[j];
			v[j] = v[j + 1];
			v[j + 1] = temp;
		}
	}
	return v;
}
int main()
{
	int T;
	int n;
	int k;
	int num;
	int maxsum;
	vector<int>way_min;
	vector<int>v1;
	cin >> T;
	while (T)
	{
		v1.clear();
		cin >> n;
		cin >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			v1.push_back(num);
		}
		vector<int>v2 = bubble_sort(v1);
		maxsum = v2[0] + v2[1] + v2[2];
		if (k%maxsum == 0)
			way_min.push_back((k / maxsum)*3);
		else if (k%maxsum <= v2[0])
			way_min.push_back((k / maxsum) * 3 + 1);
		else if (k%maxsum>v2[0] && k%maxsum<=(v2[0]+v2[1]))
			way_min.push_back((k / maxsum) * 3 + 2);
		else if (k%maxsum>(v2[0]+v2[1]))
			way_min.push_back((k / maxsum) * 3 + 3);
		v2.clear();
		T--;
	}
	for (auto e : way_min)
	{
		cout << e << endl;
	}
	return 0;
}