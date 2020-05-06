/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-29 19:38:15
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

vector<int> tree[100001];
int son[100001];
int ans;

void DFS(int x, int pre)
{
    son[x] = 1;
    for(auto i : tree[x])
        if(i != pre)
        {
            DFS(i, x);
            son[x] += son[i];
            if(son[i] % 2 == 0)
                ans++;
        }
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n, u, v;
    scanf("%d", &n);
    if(n % 2 != 0)
    {
        printf("-1\n");
        return 0;
    }
    for(i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS(1, 0);
    printf("%d\n", ans );
    return 0;
}