/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-06-06 15:03:52
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

const int maxN = 1 << 23;
int arr[maxN], ans, bit, n, m;
bool vis[maxN];
set<int> st;

void DFS(int x) {
    if(vis[x] == true)
        return;
    vis[x] = true;
    if(st.count(x) == 1)
        DFS(bit ^ x);
    for(int i = 0; i < n; i++)
        if((x & (1 << i) ))
            DFS(x ^ (1 << i));
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d", &n, &m);
    bit = (1 << n) - 1;
    for(int i = 1; i <= m; i++) {
        scanf("%d", &arr[i]);
        st.insert(arr[i]);
    }
    for(int i = 1; i <= m; i++)
        if(vis[arr[i]] == false) {
            vis[arr[i]] = true;
            ans++;
            DFS(bit ^ arr[i]);
        }
    printf("%d\n", ans );
    return 0;
}