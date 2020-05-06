/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-06 15:59:33
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

struct player {
	string str;
	int time;
	int rank;
} p[10];

bool cmp(player a, player b) {
	if (a.time == b.time)
		return a.str < b.str;
	return a.time < b.time;
}

int main(void) {
	int kase = 0, min, sec , rank, n, i;
	bool isFirst = true;
	while (cin >> n && n != 0) {
		kase++;
		for (i = 0; i < n; i++) {
			cin >> p[i].str;
			scanf("%d:%d", &min, &sec);
			sec = min * 60 + sec;
			p[i].time = sec;
		}
		sort(p, p + n, cmp);
		//处理排序问题
		rank = 2;
		p[0].rank = 1;
		for (i = 1; i <= n - 1; i++) {
			if (p[i].time == p[i - 1].time) {
				p[i ].rank = p[i - 1].rank;
				rank++;
				continue;
			}
			p[i].rank = rank++;
		}
		//输出
		if (isFirst == false)
			printf("\n");
		isFirst = false;
		printf("Case #%d\n", kase );
		for (i = 0; i < n; i++)
			cout << p[i].str << " " << p[i].rank << endl;
	}
	return 0;
}