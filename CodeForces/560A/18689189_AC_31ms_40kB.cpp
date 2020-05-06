#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n,a[10000],flag=0,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			flag=1;
	}
	if(flag==1)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(a[i]!=i+1)
			{
				printf("%d\n",i+1);
				return 0;
			}
		}
	}
}
