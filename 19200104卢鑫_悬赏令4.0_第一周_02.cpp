#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
size_t F_GetTen(string str)
{
	size_t num = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		num = num * 2 + (str[i] - '0');
	}
	return num;
}
size_t G_GetLength(string str)
{
	return str.length();
}
void GetAnswer(string str, size_t length)
{
	int n = floor(length / 2);
	for (size_t i = 0; i <n; i++)
	{
		for (size_t j = n-1; j<length; j++)
		{
			string s1(str.substr(i,j+i));
			for (size_t k = 0; k < n; k++)
			{
				for (size_t l = n-1; l < length; l++)
				{
					string s2(str.substr(k,k+l));
					if (F_GetTen(s1) % F_GetTen(s2) == 0
						&& F_GetTen(s1) != 0 && F_GetTen(s2)!=0
						&& G_GetLength(s1) >= G_GetLength(s2) 
						&& (i != k || (j + i )!= (l + k)))
					{
						cout << ++i << " " <<i+j << " " << ++k << " " << k+l << endl;
						goto part;
					}
				}
			}
		}
	}
part:;
}
int main()
{
	int T=0;
	size_t length;
	string s;
	vector<size_t>_length;
	vector<string>_s;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> length;
		_length.push_back(length);
		cin >> s;
		_s.push_back(s);
	}
	for (int i = 0; i < T; i++)
	{
		GetAnswer(_s[i], _length[i]);
	}
	return 0;
}