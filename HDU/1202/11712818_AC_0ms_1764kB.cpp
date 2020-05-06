/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-25 16:06:43
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
	int i, n;
	double score, scoresum, point, pointsum, r, ans;
	while (cin >> n) {
		//初始化变量
		scoresum = 0;
		pointsum = 0;
		for (i = 0; i < n; i++) {
			cin >> score >> r;
			//判断是否舍弃
			if (r == -1)
				continue;
			//转换分数
			if (r >= 90)
				point = 4;
			else if (r >= 80)
				point = 3;
			else if (r >= 70)
				point = 2;
			else if (r >= 60)
				point = 1;
			else
				point = 0;
			//计算
			scoresum += score * point;
			pointsum += score;
		}
		if (pointsum != 0) {
			ans = scoresum / pointsum;
			printf("%.2lf\n", ans );
		}else
			printf("-1\n");
	}
	return 0;
}