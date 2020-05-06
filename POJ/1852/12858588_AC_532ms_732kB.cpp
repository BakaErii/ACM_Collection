/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-26 15:18:40
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
	cin.tie(0);
	int t, len, n, maxtrv, mintrv, tmp;
	int i;
	cin >> t;
	while (t--) {
		cin >> len >> n;
		cin >> tmp;
		//使第一支蚂蚁作为标准
		maxtrv = max(len - tmp, tmp);
		mintrv = min(len - tmp, tmp);
		//读入剩余数据 最长时间取决于距离长边最长的蚂蚁 最短距离取决于距离短边最长的蚂蚁
		for (i = 1; i < n; i++) {
			cin >> tmp;
			//对短边判断
			if (min(len - tmp, tmp) > mintrv)
				mintrv = min(len - tmp, tmp);
			//对长边判断
			if (max(len - tmp, tmp) > maxtrv)
				maxtrv = max(len - tmp, tmp);
		}
		//输出
		cout << mintrv << " " << maxtrv << '\n';
	}
	return 0;
}