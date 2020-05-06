/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 18:37:12
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, t, y, aimy, m, d, ans;
	cin >> t;
	while (t--) {
		scanf("%d-%d-%d", &y, &m, &d);
		ans = 0;
		aimy = y + 18;
		//判断生日是否存在
		if (m == 2 && d == 29)
			if (!(aimy % 400 == 0 || (aimy % 4 == 0 && aimy % 100 != 0))) {
				cout << "-1" << endl;
				continue;
			}
		//判断今年是不是闰年
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
			if (m <= 2)
				ans++;
		for (i = y + 1; i < aimy; i++)
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
				ans++;
		//判断最后那年是不是闰年
		if (aimy % 400 == 0 || (aimy % 4 == 0 && aimy % 100 != 0))
			if (m > 2)
				ans++;
		//增加之后输出
		ans += 365 * 18 ;
		cout << ans << endl;
	}
	return 0;
}