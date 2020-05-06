#include <bits/stdc++.h>

using namespace std;

char maze[50][51];
int sx,sy,n,m;

int fuck(string cs)
{
    int d[4] = {0,1,2,3};
    int ans=0;
    string tcs;
    do
    {
        int tmpx=sx;
        int tmpy=sy;
        tcs=cs;
        for(int i=0; i<(int)tcs.length(); i++)
            if(tcs[i]-'0'==d[0])
                tcs[i]='U';
            else if(tcs[i]-'0'==d[1])
                tcs[i]='L';
            else if(tcs[i]-'0'==d[2])
                tcs[i]='R';
            else
                tcs[i]='D';
        for(int i=0; i<(int)tcs.length(); i++)
        {
            switch(tcs[i])
            {
            case 'U':
                if(tmpx-1>=0&&maze[tmpx-1][tmpy]!='#')
                    tmpx--;
                else
                    goto FOREND;
                if(maze[tmpx][tmpy]=='E')
                {
                    ans++;
                    goto FOREND;
                }
                break;
            case 'L':
                if(tmpy-1>=0&&maze[tmpx][tmpy-1]!='#')
                    tmpy--;
                else
                    goto FOREND;
                if(maze[tmpx][tmpy]=='E')
                {
                    ans++;
                    goto FOREND;
                }
                break;
            case 'R':
                if(tmpy+1<m&&maze[tmpx][tmpy+1]!='#')
                    tmpy++;
                else
                    goto FOREND;
                if(maze[tmpx][tmpy]=='E')
                {
                    ans++;
                    goto FOREND;
                }
                break;
            case 'D':
                if(tmpx+1<n&&maze[tmpx+1][tmpy]!='#')
                    tmpx++;
                else
                    goto FOREND;
                if(maze[tmpx][tmpy]=='E')
                {
                    ans++;
                    goto FOREND;
                }
                break;
            }
        }
        FOREND:
        ;
    }
    while ( next_permutation(d,d+4) );
    return ans;
}

int main(void)
{
    cin>>n>>m;
    getchar();
    for(int i=0;i<n;i++)
        gets(maze[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    if(maze[i][j]=='S'){
        sx=i;
        sy=j;
        break;
    }
    string str;
    cin>>str;
    cout<<fuck(str)<<endl;
    return 0;
}