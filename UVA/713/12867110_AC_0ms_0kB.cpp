/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-28 23:28:27
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

char num[3][202];
int alen, blen;

void res(int len, char num[]) {
	int i;
	char tmp;
	for (i = 0; i < len / 2; i++) {
		tmp = num[i];
		num[i] = num[len - i - 1];
		num[len - i - 1] = tmp;
	}
	return;
}


int main(void) {
	int n, ptr, i, j;
	cin >> n;
	while (n--) {
		cin >> num[0] >> num[1];
		//init
		alen = strlen(num[0]);
		blen = strlen(num[1]);
		res(alen, num[0]);
		res(blen, num[1]);
		for (i = 0; i < 202; i++)
			num[2][i] = '0';
		//adding
		ptr = 0;
		i = alen - 1;
		j = blen - 1;
		while (i >= 0 || j >= 0) {
			if (i >= 0)
				num[2][ptr] += num[0][i--] - '0';
			if (j >= 0)
				num[2][ptr] += num[1][j--] - '0';
			if (num[2][ptr] > '9') {
				num[2][ptr] -= 10;
				num[2][ptr + 1]++;
			}
			ptr++;
		}
		if (num[2][ptr] != '0')
			num[2][ptr + 1] = '\0';
		else
			while (num[2][ptr] == '0')
				num[2][ptr--] = '\0';
		i = 0;
		while (num[2][i] == '0')
			i++;
		while (num[2][i] != '\0')
			putchar(num[2][i++]);
		putchar('\n');
	}
	return 0;
}