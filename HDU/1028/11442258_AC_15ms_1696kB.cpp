/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-06 23:00:28
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int i, j;
	//整数拆分 推导数组
	//向后多推导一个 r[n]即为组合可能
	int r[121] = {1};
	for (i = 1; i <= 121; i++)
	{
		for (j = i; j <= 121; j++)
		{
			r[j] += r[j - i];
		}
	}
	int n;
	while (cin >> n )
		cout << r[n] << endl;
	return 0;
}