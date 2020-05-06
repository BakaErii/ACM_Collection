/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-01 18:06:33
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

string str;
int arr[1000];

int tenpw(int a) {
	int tmp, i;
	tmp = 1;
	for (i = 0; i < a; i++)
		tmp *= 10;
	return tmp;
}

int main(void) {
	int i, j, len, num, sum;
	while (cin >> str) {
		//初始化变量
		sum = 0;
		num = 0;
		arr[num] = 0;
		len = (int)str.length();
		//从后向前读取
		for (i = len - 1; i >= 0; i--) {
			if (str[i] != '5') {
				arr[num] += (str[i] - '0') * tenpw(sum++);
			} else {
				if (sum != 0) {
					arr[++num] = 0;
					sum = 0;
				}
			}
		}
		if (sum != 0) {
			num++;
		}
		//逆序输出
		sort(arr, arr + num );
		for (i = 0; i < num; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", arr[i] );
		}
		printf("\n");
	}
	return 0;
}