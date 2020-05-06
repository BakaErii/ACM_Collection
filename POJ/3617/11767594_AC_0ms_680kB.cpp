/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-29 16:48:37
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

char str[2000], ans[2001];

int main(void) {
	int i, j, n, lptr, rptr;
	//获取输入
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		str[i] = getchar();
		getchar();
	}
	//比较判断并存放结果于ans中
	lptr = 0;
	rptr = n - 1;
	for (i = 0; i < n; i++) {
		if (str[lptr] < str[rptr]) {
			//左小于右
			ans[i] = str[lptr++];
		} else if (str[lptr] == str[rptr]) {
			//左等于右
			for (j = 1; j < n - i ; j++) {
				if (str[lptr + j] != str[rptr - j]) {
					if (str[lptr + j] < str[rptr - j])
						ans[i] = str[lptr++];
					else
						ans[i] = str[rptr--];
					break;
				}
			}
			//全串相等的特殊情况
			if (j == n - i )
				ans[i] = str[lptr++];
		} else {
			//左大于右
			ans[i] = str[rptr--];
		}
	}
	//输出
	for (i = 0; i < n; i++) {
		putchar(ans[i]);
		if ((i + 1) % 80 == 0)
			putchar('\n');
	}
	putchar('\n');
	return 0;
}