/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-19 18:17:36
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

int calInt(char ch) {
	if ('0' <= ch && ch <= '9')
		return ch - '0' ;
	else if ('A' <= ch && ch <= 'Z')
		return ch - 'A' + 10 ;
	else
		return ch - 'a' + 36 ;
}

char str[233333];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, sum, len, tmp, base;
	while (gets(str)) {
		//toInt
		len = strlen(str);
		sum = 0;
		base = 0;
		for (int i = 0; i < len; i++) {
			tmp = calInt(str[i]);
			base = max(base, tmp);
			sum += tmp;
		}
		if (base == 0)
			printf("2\n");
		else {
			for (i = base; i < 62; i++)
				if (sum % i == 0)
					break;
			if (i == 62)
				printf("such number is impossible!\n");
			else
				printf("%d\n", i + 1 );
		}
	}
	return 0;
}