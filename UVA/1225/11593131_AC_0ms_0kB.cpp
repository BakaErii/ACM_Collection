/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-16 21:15:24
 *
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int t, n, i, tmp, bit;
	int ans[10];
	cin >> t;
	while (t--) {
		cin >> n;
		//数组归零
		memset(ans, 0, sizeof(ans));
		for (i = 1; i <= n; i++) {
			//对每个循环进行处理
			tmp = i;
			while (tmp != 0) {
				bit = tmp % 10;
				tmp /= 10;
				switch (bit) {
				case 0: ans[0]++; break;
				case 1: ans[1]++; break;
				case 2: ans[2]++; break;
				case 3: ans[3]++; break;
				case 4: ans[4]++; break;
				case 5: ans[5]++; break;
				case 6: ans[6]++; break;
				case 7: ans[7]++; break;
				case 8: ans[8]++; break;
				case 9: ans[9]++; break;
				}
			}
		}
		//输出
		for (i = 0; i < 10; i++)
		{
			cout << ans[i];
			if (i != 9)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}