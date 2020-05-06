/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-18 23:42:21
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

#define PI 3.14159265359

using namespace std;

int main(void) {
	int i, n;
	double r, year, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		//计算相对的半径
		r = sqrt(x * x + y * y);
		//根据半径计算年份 并向下取整
		year = PI * r * r / 2 / 50;
		printf("Property %d: This property will begin eroding in year %d.\n", i + 1, (int)ceil(year));
	}
	printf("END OF OUTPUT.\n");
	return 0;
}