#include<iostream>
using namespace std;
int main()
{
	char c,a[41][41];
	int i,j,h,n,k=0;
	while(cin >>c)
	{

		if(c =='@')
			break;
		cin >>n;
		if(k)
			cout << endl;
		k=1;
		h=n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<h;j++)
			{
				if(i!=n-1)
				{
					if(j==n-1-i || j==n-1+i)
						a[i][j]=c;
					else
						a[i][j]=' ';
				}
				else
					a[i][j]=c;
				cout << a[i][j];
			}
			h++;
			cout <<endl;
		}
	}
	return 0;
}