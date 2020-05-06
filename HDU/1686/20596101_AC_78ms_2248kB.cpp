#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 1000005;

char strA[maxN];
char strB[maxN];
int nxt[maxN];
int lenA,lenB;

void Init()
{
    nxt[0]=-1;
    lenA=strlen(strA);
    lenB=strlen(strB);
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
    int ret=0;
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
            ret++;
            j=nxt[j];
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
        scanf("%s",strB);
        scanf("%s",strA);
        Init();
        printf("%d\n",KMP());
    }
    return 0;
}
