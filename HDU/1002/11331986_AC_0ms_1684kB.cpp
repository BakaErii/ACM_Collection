/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-30 21:51:50
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	int n, i, len1, len2, ptr, add;
	add = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		int num1[1000] = {0}, num2[1000] = {0};
		char cnum1[1000], cnum2[1000];
		scanf("%s %s", cnum1, cnum2);
		//获取两个字符串的长度 并进行分割 将数据存入数组(从后向前存储)
		len1 = strlen(cnum1);
		len2 = strlen(cnum2);
		//将字符串转换为数组
		ptr = 999;
		for (i = len1; i >= 0; i--)
		{
			num1[ptr--] = cnum1[i] - '0';
		}
		//将字符串转换为数组
		ptr = 999;
		for (i = len2; i >= 0; i--)
		{
			num2[ptr--] = cnum2[i] - '0';
		}
		//将两个数组从后向前相加 将1向2加
		for (i = 999; i >= 0; i--)
		{
			num2[i] += num1[i];
			if (num2[i] >= 10)
			{
				num2[i] %= 10;
				num2[i - 1]++;
			}
		}
		//先输出case和公式
		printf("Case %d:\n", ++add);
		printf("%s + %s = ", cnum1, cnum2);
		int isFirst = 0;
		for (i = 0; i < 999; i++)
		{
			if (isFirst == 0)
			{
				if (num2[i] != 0)
				{
					isFirst = 1;
					printf("%d", num2[i] );
				}
			} else {
				printf("%d", num2[i] );
			}
		}
		printf("\n");
		if (n != 0)
			printf("\n");
	}
	return 0;
}