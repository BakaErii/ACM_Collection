/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-02 17:28:46
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



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, N, tmp;
	unsigned long long int ans = 0;
	priority_queue<int, vector<int>, greater<int> > que;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &tmp);
		que.push(tmp);
	}
	while(que.size() >= 2) {
		int tmp1, tmp2;
		tmp1 = que.top();
		que.pop();
		tmp2 = que.top();
		que.pop();
		ans += tmp1 + tmp2;
		que.push(tmp1 + tmp2);
	}
	printf("%llu\n", ans );
	return 0;
}