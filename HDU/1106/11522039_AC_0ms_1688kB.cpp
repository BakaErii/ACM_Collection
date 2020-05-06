/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-11 21:47:23
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int tenpw(int a);

int main(void) {
	char str[1001];
	int num[1000], numptr, isNull, i, j, len;
	while (~scanf("%s", str)) {
		//变量初始化
		len = strlen(str);
		numptr = 0;
		isNull = 1;
		//对字符串的逆序处理
		for (i = --len; i >= 0; i--)
		{
			//读入并相减判断
			if (str[i] == '5' ) {
				if (isNull == 0)
					numptr++;
				//如果为空什么都不做
			} else {
				//处理数据部分
				isNull = 0;
				num[numptr] = 0;
				//对读入的第一个数进行处理
				num[numptr] += str[i] - '0';
				//对接下来的数进行处理
				for (j = 1; (str[i - j] != '5') && (i - j >= 0); j++)
				{
					num[numptr] += (str[i - j] - '0') * tenpw(j);
				}
				//结束处理
				isNull = 1;
				numptr++;
				i -= j;
			}
		}
		//排序
		sort(num, num + numptr);
		//吐出来
		for (i = 0; i < numptr; i++)
		{
			printf("%d", num[i] );
			if(i!=numptr-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

int tenpw(int a) {
	int i, tmp;
	tmp = 1;
	for (i = 0; i < a; i++ )
	{
		tmp *= 10;
	}
	return tmp;
}