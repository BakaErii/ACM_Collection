/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-10 15:26:02
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	int s, n, i, j, k, len;
	char data[9];
	while (cin >> s >> data && s != 0) {
		//初始化变量
		len = strlen(data);
		//控制行数的输出
		for (i = 0; i < 2 * s + 3; i++)
		{
			//控制每个数的输出
			for (j = 0; j < len; j++ )
			{
				//控制每一列的输出
				switch (data[j] - '0') {
				case 0:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf(" ");
							else
								printf("|");
					}
					break;
				case 1:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if ( k != s + 1)
								printf(" ");
							else
								printf("|");
					}
					break;
				case 2:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == 0 && i > s + 1)
								printf("|");
							else if (k == s + 1 && i < s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				case 3:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				case 4:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == 0 && i < s + 1)
								printf("|");
							else if (k == s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				case 5:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == 0 && i < s + 1)
								printf("|");
							else if (k == s + 1 && i > s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				case 6:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == 0 && i < s + 1)
								printf("|");
							else if ((k == s + 1 || k == 0) && i > s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				case 7:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if ( k != s + 1)
								printf(" ");
							else
								printf("|");
					}
					break;
				case 8:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == 0 || k == s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				case 9:
					//判断首末中
					if (i == 0)
					{
						//首
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k !=  s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == 2 * s + 2) {
						//末
						for (k = 0; k < s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else if (i == s + 1) {
						//中
						for (k = 0; k <  s + 2; k++)
							if (k != 0 && k != s + 1)
								printf("-");
							else
								printf(" ");
					} else {
						for (k = 0; k <  s + 2; k++)
							if (k == 0 && i < s + 1)
								printf("|");
							else if (k == s + 1)
								printf("|");
							else
								printf(" ");
					}
					break;
				}
				//输出数中间的空格
				if (j != len - 1)
					printf(" ");
			}
			//输出完毕换行
			printf("\n");
		}
		//额外的换行
		printf("\n");
	}
	return 0;
}