#include<iostream>
#include<cstring>
#include<cmath>
int min(int a,int b)
{
	if(a>=b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
using namespace std;
int main()
{
	int n,m,g,t,flag=1;
	cin>>n>>m;
	char a[1000];
	cin>>a;
	int cha;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='G')
		{
			g=i;
		}
		else if(a[i]=='T')
		{
			t=i;
		}
	}
	int aa=min(g,t);
	int bb=max(g,t);
	for(int i=aa;i<bb;i+=m)
	{
		if(a[i]=='#')
		{
			printf("NO\n");
			return 0;
		}		
	}
	if(abs(g-t)%m==0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
