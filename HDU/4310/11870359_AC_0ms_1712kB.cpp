/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-06 21:17:51
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

struct enemy
{
	int dps;
	int hp;
	double con;
} e[20];

bool cmp(enemy a, enemy b) {
	return a.con > b.con;
}

int main(void) {
	int i, n, time, ans;
	while (cin >> n) {
		time = 0;
		ans = 0;
		for (i = 0; i < n; i++) {
			cin >> e[i].dps >> e[i].hp;
			e[i].con = (double)e[i].dps / (double)e[i].hp;
		}
		sort(e, e + n, cmp);
		for (i = 0; i < n; i++) {
			time += e[i].hp;
			ans += time * e[i].dps;
		}
		cout << ans << endl;
	}
	return 0;
}