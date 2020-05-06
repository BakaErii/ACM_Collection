#include<math.h> 
#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
#define N 51000 
using namespace std; 
struct query 
{ 
    int pos,l,r,no; 
}Q[N]; 
int a[N],s[N],ans_up[N],ans_do[N],C[N][3],now; 
bool cmp(query a,query b) 
{ 
    if(a.pos==b.pos) 
    return a.r<b.r; 
    return a.pos<b.pos; 
} 

int GCD(int a, int b) {
    return !b ? a : GCD(b, a % b);
}

void update(int x,int op) 
{ 
    now-=C[s[a[x]]][2]; 
    s[a[x]]+=op; 
    now+=C[s[a[x]]][2]; 
} 
int main() 
{ 
    int n,m,k,i,j,l,r; 
    scanf("%d%d",&n,&m); 
    int bk=sqrt(n); 
    for(i=1;i<=n;i++) 
        scanf("%d",a+i); 
    for(i=0;i<=n;i++) 
    { 
        C[i][0]=1; 
        for(j=1;j<=2;j++) 
            C[i][j]=C[i-1][j]+C[i-1][j-1]; 
    } 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d",&Q[i].l,&Q[i].r); 
        Q[i].no=i,Q[i].pos=Q[i].l/bk; 
    } 
    sort(Q+1,Q+m+1,cmp); 
    l=0,r=0,now=0,s[50001]=1,a[0]=50001; 
    for(i=1;i<=m;i++) 
    { 
        while(l<Q[i].l)  update(l++,-1); 
        while(l>Q[i].l)  update(--l, 1); 
        while(r<Q[i].r)  update(++r, 1); 
        while(r>Q[i].r)  update(r--,-1); 
        ans_up[Q[i].no]=now; 
        ans_do[Q[i].no]=C[r-l+1][2]; 
    } 
    for(i=1;i<=m;i++) 
    { 
        k=GCD(ans_up[i],ans_do[i]); 
        printf("%d/%d\n",ans_up[i]/k,ans_do[i]/k); 
    } 
    return 0; 
}