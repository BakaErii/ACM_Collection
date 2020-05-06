/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-28 20:30:41
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

string str1, str2;

int main(void) {
	int len1, len2, ans, i, offset;
	while (cin >> str1 >> str2) {
		//使str1>=str2
		if (str1.length() < str2.length())
			swap(str1, str2);
		//初始化变量
		len1 = (int)str1.length();
		len2 = (int)str2.length();
		ans = len1 + len2;
		//使str2从左向右扫过 记录最小的可行值
		//最大偏移长度=2*len2+len1
		for (offset = 0; offset < len1 + len2; offset++) {
			//从0~len2是左侧 从len2~len1是中间重合部分 len1~len1+len2是右侧部分
			//三种情况
			if (offset < len2) {
				for (i = 0; i < offset; i++) {
					if ((str1[i] - '0') + (str2[len2 - offset + i] - '0') > 3)
						break;
				}
				if (i ==  offset)
					ans = min(ans, len1 + len2 - offset);
			} else if (offset > len1) {
				for (i = 0; i < len1 + len2 - offset; i++) {
					if ((str1[offset - len2 + i] - '0') + (str2[i] - '0') > 3)
						break;
				}
				if (i == len1 + len2 - offset) {
					ans = min(ans, offset);
				}
			} else {
				for (i = 0; i < len2; i++) {
					if ((str1[offset - len2 + i] - '0') + (str2[i] - '0') > 3)
						break;
				}
				if (i == len2)
					ans = min(ans, len1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}