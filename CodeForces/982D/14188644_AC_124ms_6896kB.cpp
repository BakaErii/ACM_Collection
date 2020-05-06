/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-06-05 19:12:24
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

set<pair<int, int>> que;
set<int> part;
map<int, int> mp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, k, l, r, tmp, ans, ptr, maxCnt;
    scanf("%d", &k);
    for(i = 1; i <= k; i++) {
        scanf("%d", &tmp);
        que.insert(make_pair(tmp, i));
    }
    //INIT
    part.insert(0);
    part.insert(k + 1);
    mp[k] = 1;
    ans = que.rbegin()->first + 1;
    maxCnt = 1;
    for(i = 0; i < k-1; i++) {
        auto it = que.rbegin();
        ptr = it->second;
        que.erase(*it);
        l = *(--part.lower_bound(ptr));
        r = *(part.upper_bound(ptr));
        part.insert(ptr);
        mp[r - l - 1]--;
        if(mp[r - l - 1] == 0)
            mp.erase(r - l - 1);
        mp[ptr - l - 1]++;
        mp[r - ptr - 1]++;
        mp.erase(0);
        if(mp.size() == 1 && mp.begin()->second >= maxCnt) {
            maxCnt = mp.begin()->second;
            ans = que.rbegin()->first + 1;
            //printf("%d\n",ans );
        }
    }
    printf("%d\n", ans );
    return 0;
}