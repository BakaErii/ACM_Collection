/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-21 19:26:03
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

int p[10001];

using namespace std;

int main(void) {
	int i, n, m, xbloc, xaloc;
	int l, r, x;
	//读入数据
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> p[i];
	//循环
	while (m--) {
		cin >> l >> r >> x;
		//升序排列 判断选定区间内有多少个比原来x位置元素小的元素 推断出x的相对位移
		//在位移前的相对位置
		xbloc = x - l;
		//开始排序
		xaloc = 0;
		for (i = l - 1; i < r; i++)
			if (p[i] < p[x - 1])
				xaloc++;
		//此时xaloc是排序之后的相对位置
		//判断
		if (xaloc == xbloc)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}