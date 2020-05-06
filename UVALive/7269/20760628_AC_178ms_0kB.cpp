/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-25 14:54:39
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

int n, x, y;

void SpecialPrint(int x) {
	switch (x) {
	case 1:
		printf("1 1\n");
		break;
	case 2:
		printf("1 1\n");
		printf("1 2 1 3\n");
		break;
	case 3:
		printf("1 2\n");
		printf("1 3 2 3\n");
		printf("1 1 2 1 2 2\n");
		break;
	case 4:
		printf("1 4\n");
		printf("1 5 2 5\n");
		printf("1 1 2 1 2 2\n");
		printf("1 2 1 3 2 3 2 4\n");
		break;
	case 5:
		printf("3 4\n");
		printf("1 4 1 5\n");
		printf("2 4 2 5 3 5\n");
		printf("2 2 2 3 3 3 3 2\n");
		printf("3 1 2 1 1 1 1 2 1 3\n");
		break;
	}
	return;
}

void PrintSnake(int val) {
	if (val % 2 == 0) {
		for (int i = x - 1; i >= 1; i--)
			printf("%d %d ", i, y );
		y++;
		for (int i = 1; i <= x + 1; i++)
			printf("%d %d ", i, y );
		y--;
		x++;
	} else {
		for (int i = 1; i <= y; i++)
			printf("%d %d ", x, i );
		printf("%d %d ", x - 1, y );
		y += 2;
	}
	putchar('\n');
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	while (~scanf("%d", &n)) {
		// INIT
		x = 3;
		y = 6;
		if (n % 2 == 0)
			tmp = n / 2;
		else
			tmp = (n + 1) / 2;
		printf("%d %d\n", tmp, (n + 1) * n / 2 / tmp );
		// Draw
		if (n <= 5) {
			SpecialPrint(n);
			continue;
		}
		SpecialPrint(5);
		if (n % 2 == 0) {
			for (int i = 6; i < n; i++)
				PrintSnake(i);
			for (int i = x; i >= 1; i--)
				printf("%d %d ", i, y );
			for (int i = 1; i <= x; i++)
				printf("%d %d ", i, y + 1 );
			putchar('\n');
		} else {
			for (int i = 6; i <= n ; i++)
				PrintSnake(i);
		}
	}
	return 0;
}