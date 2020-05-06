/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-29 18:45:26
 *
 */

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

struct Seat
{
    int id;
    int w;
    bool operator < (const Seat &a) const
    {
        return w < a.w;
    }
} arr[200005];
int vis[400010];
char str[400010];

bool cmp(Seat a, Seat b)
{
    return a < b;
}

priority_queue<Seat> que;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n, ptr;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].w);
        arr[i].id = i + 1;
    }
    getchar();
    gets(str);
    sort(arr, arr + n, cmp);
    //init
    ptr = 0;
    for(i = 0; i < 2 * n; i++)
    {
        if(str[i] == '0')
        {
            vis[i] = arr[ptr].id;
            que.push(arr[ptr]);
            ptr++;
        }
        else
        {
            vis[i] = que.top().id;
            que.pop();
        }
    }
    for(i=0;i<2*n;i++){
    	if(i!=0)
    		putchar(' ');
    	printf("%d",vis[i] );
    }
    putchar('\n');
    return 0;
}