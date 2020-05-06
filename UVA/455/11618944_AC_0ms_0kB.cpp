/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-18 17:14:57
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	int t, i, j, len, cmplen, ans;
	cin >> t;
	getchar();
	while (t--) {
		getchar();
		getline(cin, str);
		//初始化变量
		len = (int)str.length();
		ans = len;
		for (i = 1; i < len; i++) {
			if (str[0] == str[i]) {
				cmplen = i;
				//假设当前周期是cmplen
				for (j = i; j < len; j++)
				{
					//以当前的周期来判断剩下的字符是否满足条件
					if (str[j % cmplen] != str[j])
						break;
				}
				if (j == len) {
					//字符成立 判断字符长度是否成立
					if ((len - cmplen) % cmplen == 0) {
						ans = cmplen;
						break;
					}
				}
			}
		}
		cout << ans << endl;
		if (t != 0)
			cout << endl;
	}
	return 0;
}