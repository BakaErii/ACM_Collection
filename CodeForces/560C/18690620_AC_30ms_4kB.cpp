#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()
{
	int a[6],max=0,ans=0,b=0,c=0,d=0;
	for(int i=1;i<=6;i++)
	{
		cin>>a[i];
	}
	int n=a[2]+a[3]+a[4];
	ans=(1+2*n-1)*n/2;
	b=(1+2*a[2]-1)*a[2]/2;
	c=(1+2*a[4]-1)*a[4]/2;
	d=(1+2*a[6]-1)*a[6]/2;
	ans=ans-b-c-d;
	printf("%d\n",ans);
	return 0;
}
