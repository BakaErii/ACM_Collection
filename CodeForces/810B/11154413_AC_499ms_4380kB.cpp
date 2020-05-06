/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-20 21:35:09
 * 换种思路
 */

#include <iostream>
#include <algorithm>

int main(void) {
	//总销售量=原本销售量+增加的销售量
	//增加的销售量=剩下的人数或者是剩下的人数减原本的销售量
	unsigned long long r;
	unsigned long long a[100000], b[100000], c[100000], d[100000];
	//a是总计人数(剩下的人数) b是备货量 c是原销量 d是增加的销售量
	int i, n, f;
	r = 0;
	std::cin >> n >> f;
	for (i = 0; i < n; i++) {
		std::cin >> b[i] >> a[i];
		if (a[i] <= b[i])
		{
			c[i] = a[i];
			a[i] = 0;
			r += c[i];
		} else {
			c[i] = b[i];
			a[i] -= b[i];
			r += c[i];
		}
		if (a[i] <= b[i])
		{
			d[i] = a[i];
		} else {
			d[i] = b[i];
		}
	}
	//之后对D进行排序 选取f个增加的销量累加
	std::sort(d, d + n);
	for (i = n - 1; i > n - f - 1; i--)
	{
		r += d[i];
	}
	std::cout << r << std::endl;
	return 0;
}
