/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-06 23:17:00
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int i, ii, j, jj, n, max, tmp, k;
	while (cin >> i >> j) {
		max = 0;
		//判断i和j的大小 并比较交换
		ii = i;
		jj = j;
		if (i > j)
		{
			//此时tmp作为交换变量
			tmp = i;
			i = j;
			j = tmp;
		}
		for (k = i; k <= j; k++)
		{
			//此时tmp记录函数执行的次数
			tmp = 1;
			n = k;
			while (n != 1) {
				if (n % 2 != 1)
				{
					n /= 2;
					tmp++;
				} else {
					n = 3 * n + 1;
					tmp++;
				}
			}
			if (tmp > max)
			{
				max = tmp;
			}
		}
		cout << ii << " " << jj << " " << max << endl;
	}
	return 0;
}