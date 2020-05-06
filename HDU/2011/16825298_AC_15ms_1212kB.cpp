#include<stdio.h>
int main()
{
    int sta,i,bl;
    double ans;
    scanf("%d",&sta);
    for(i=1;i<=sta;i++)
    {
	scanf("%d",&bl);
        int x;
        double per;
        for(ans=0,x=1;x<=bl;x++)
        {
            per = (double)1/x;
            ans += per*(x%2*2-1);
        }
        printf("%.2f\n",ans);
    }
    return 0;
}