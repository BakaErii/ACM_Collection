/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-24 18:03:04
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

set<char> st;
int ans = 0;
char str[205];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	getchar();
	scanf("%s", str);
	for(int i = 0; i < n; i++) {
		int ptr = i;
		st.clear();
		while(ptr <= n && 'a' <= str[ptr] && str[ptr] <= 'z')
			st.insert(str[ptr++]);
		ans = max(ans, (int)st.size());
	}
	printf("%d\n", ans );
	return 0;
}