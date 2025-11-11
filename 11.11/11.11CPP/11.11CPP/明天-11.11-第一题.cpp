#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[10005];
int n, cnt;
void move(int x)//将空位移动到目标处
{
	int i;
	for (i = 1; i <= 2 * n + 2; i++) if (s[i] == '-') break;//查找空位
	swap(s[i], s[x]); swap(s[i + 1], s[x + 1]);
	printf("step%2d:%s\n", cnt++, s + 1);
}
void f(int x)
{
	if (x > 4)
	{
		move(x);
		move(2 * x - 1);
		f(x - 1);
	}
	if (x == 4)//剩4个时特殊处理
	{
		move(4);
		move(8);
		move(2);
		move(7);
		move(1);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		s[i] = 'o';
		s[n + i] = '*';
	}
	s[2 * n + 1] = '-'; s[2 * n + 2] = '-'; s[2 * n + 3] = '\0';
	printf("step%2d:%s\n", cnt++, s + 1);
	f(n);
	return 0;
}

