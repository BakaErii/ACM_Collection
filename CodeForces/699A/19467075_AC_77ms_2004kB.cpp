/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-27 10:03:45
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

const int maxN = 200005;

int n;
struct Node {
	int to;
	int dis;
} N[maxN];

char str[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0x3f3f3f3f;
	scanf("%d", &n);
	scanf("%s", str);
	for(int i = 0; i < n; i++) {
		scanf("%d", &N[i].dis);
		if(str[i] == 'L')
			N[i].to = 0;
		else
			N[i].to = 1;
	}
	for(int i = 1; i < n; i++)
		if(N[i].to == 0 && N[i - 1].to == 1)
			ans = min(ans, (N[i].dis - N[i - 1].dis) / 2);
	printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans );
	return 0;
}