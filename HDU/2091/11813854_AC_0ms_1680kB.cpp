/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-02 17:41:54
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
	bool isFirst = true;
	int i, j, n, offset;
	char ch;
	while (~scanf("%c", &ch) && ch != '@') {
		scanf("%d", &n);
		getchar();
		if (isFirst != true)
			printf("\n");
		isFirst = false;
		offset = n;
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < offset - i - 1; j++)
				printf(" ");
			for (j = 0; j < i * 2 + 1; j++)
				if (j == 0 || j == i * 2)
					printf("%c", ch);
				else
					printf(" ");
			printf("\n");
		}
		for (i = 0; i < 2 * n - 1; i++)
			printf("%c", ch );
		printf("\n");
	}
	return 0;
}