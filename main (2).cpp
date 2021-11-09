#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

int a, b;
int prime[10000];
int mark[10000];

int isprime(int num)
{
	int i;
	int t = sqrt(num);

	for(i = 2; i <= t; i++)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}

void init()
{
	int i;

	memset(prime,0,sizeof(prime));
	for(i = 1001; i < 10000; i += 2)
	{
		prime[i] = isprime(i);
	}
}

void bfs()
{
	int i, j;
	int num, w, nn;
	char tmp[5], tt;
	typedef pair<int,int> type;
	queue <type> que;
	type t;

	memset(mark,0,sizeof(mark));
	mark[a] = 1;
	que.push(make_pair(a,0));
	while(!que.empty())
	{
		t = que.front();
		que.pop();
		num = t.first;
		w = t.second;
		sprintf(tmp, "%d", num);
		for(i = 0; i < 4; i++)
		{
			for(j = 0+(i==0); j < 10; j++)
			{
				if(j+'0'==tmp[i])
					continue;
				tt = tmp[i];
				tmp[i] = j+'0';
				nn = atoi(tmp);
				tmp[i] = tt;
				if(mark[nn]==0&&prime[nn])
				{
					mark[nn] = 1;
					if(nn==b)
					{
						printf("%d\n",w+1);
						return ;
					}
					que.push(make_pair(nn,w+1));
				}
			}
		}
	}
	puts("Impossible");
}

int main()
{
	int cas;

	scanf("%d",&cas);
	init();
	while(cas--)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			puts("0");
			continue;
		}
		bfs();
	}
	return 1;
}