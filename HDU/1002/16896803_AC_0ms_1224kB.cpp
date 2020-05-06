/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-07 17:24:42
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char strA[1005];
char strB[1005];
int arrA[1005];
int arrB[1005];

int main(void) {
	int t;
	scanf("%d", &t);
	getchar();
	for (int s = 1; s <= t; s++) {
		scanf("%s %s", strA, strB);
		// 将数组清零
		for (int i = 0; i < 1005; i++) {
			arrA[i] = 0;
			arrB[i] = 0;
		}
		// 计算两个数的长度 并按照多的那位在数组中对齐 并向后移动一位(预留出进位的情况)
		int lenA = strlen(strA);
		int lenB = strlen(strB);
		int len = lenA > lenB ? lenA + 1 : lenB + 1;
		// 将字符串转换为数组中的整数
		for (int i = 0; i < lenA; i++)
			arrA[len - lenA + i] = strA[i] - '0';
		for (int i = 0; i < lenB; i++)
			arrB[len - lenB + i] = strB[i] - '0';
		/*
			转换前(下标均由0开始):
			strA:51234
			strB:234
			转换后:
			arrA:051234
			arrB:000234
		*/
		// 将两数组的和相加进位到arrB中
		for (int i = len; i > 0; i--) {
			arrB[i] += arrA[i];
			if (arrB[i] >= 10) {
				arrB[i] %= 10;
				arrB[i - 1]++;
			}
		}
		printf("Case %d:\n", s );
		// 将首位输出(如果有进位的话)
		printf("%s + %s = ", strA, strB );
		if (arrB[0] != 0)
			printf("%d", arrB[0]);
		// 将剩下的输出
		for (int i = 1; i < len; i++)
			printf("%d", arrB[i]);
		putchar('\n');
		if(s!=t)
			putchar('\n');
	}
	return 0;
}