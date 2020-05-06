/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-20 14:18:28
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

int main(void) {
	int i, nlen, num[10], ptr;
	char n[20], m[20], ans[20];
	gets(n);
	gets(m);
	nlen = strlen(n);
	ptr = 0;
	//init
	for (i = 0; i < 10; i++)
		num[i] = 0;
	//对n中元素进行提取
	for (i = 0; i < nlen; i++)
		num[(int)(n[i] - '0')]++;
	//将除0外最小的元素置于最前
	for (i = 1; i < 9; i++)
		if (num[i] != 0) {
			ans[ptr++] = i + '0';
			num[i]--;
			break;
		}
	//将零置入之后
	while (num[0]--)
		ans[ptr++] = '0';
	//从小到大将剩余的数放置在数组中
	for (i = 1; i < 10; i++)
		while (num[i] != 0) {
			ans[ptr++] = i + '0';
			num[i]--;
		}
	//为数组最后加上结束符
	ans[ptr] = '\0';
	//比较输入M以及答案
	if (strcmp(ans, m) == 0)
		cout << "OK" << endl;
	else
		cout << "WRONG_ANSWER" << endl;
	return 0;
}