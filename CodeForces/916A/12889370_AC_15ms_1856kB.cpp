/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 22:39:57
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
	int x, h, m, ans, tmph, tmpm, flag;
	cin >> x >> h >> m;
	ans = 0;
	while (true) {
		flag = 0;
		tmph = h;
		tmpm = m;
		//对H处理
		while (tmph > 0) {
			if (tmph % 10 == 7) {
				flag = 1;
				break;
			}
			tmph /= 10;
		}
		//对M处理
		while (tmpm > 0) {
			if (tmpm % 10 == 7) {
				flag = 1;
				break;
			}
			tmpm /= 10;
		}
		if (flag == 1)
			break;
		//向前推进
		ans++;
		m -= x;
		if (m < 0) {
			m += 60;
			h--;
		}
		if (h < 0)
			h = 23;
	}
	cout << ans << endl;
	return 0;
}