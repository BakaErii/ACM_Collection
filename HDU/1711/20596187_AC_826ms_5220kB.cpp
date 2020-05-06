#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 1000005;

int strA[maxN];
int strB[maxN];
int nxt[maxN];
int lenA,lenB;

void Init()
{
    nxt[0]=-1;
    int i=0,j=-1;
    while(i<lenB)
    {
        if(j==-1||strB[i]==strB[j])
        {
            i++;
            j++;
            nxt[i]=j;
        }
        else
            j=nxt[j];
    }
    return;
}

int KMP()
{
    int ret=-1;
    int i=0,j=0;
    while(i<lenA)
    {
        if(j==-1||strA[i]==strB[j])
        {
            i++;
            j++;
        }
        else
            j=nxt[j];
        if(j==lenB)
        {
            return i-j+1;
        }
    }
    return ret;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&lenA,&lenB);
        for(int i=0;i<lenA;i++)
            scanf("%d",&strA[i]);
        for(int i=0;i<lenB;i++)
            scanf("%d",&strB[i]);
        Init();
        printf("%d\n",KMP());
    }
    return 0;
}
