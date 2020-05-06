/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-21 16:36:35
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

int n;
string arr[105];
char ansArr[105][105];
int x, y, ptrX, ptrY, status, chLeft, towards;

int main(void) {
	while (~scanf("%d", &n)) {
		getchar();
		//INIT
		memset(ansArr, 0, sizeof(ansArr));
		towards = 0;
		x = y = 0;
		ptrX = ptrY = 0;
		status = 0;
		chLeft = n * n;
		for (int i = 0; i < n; i++)
			getline(cin,arr[i]);
		while (chLeft > 0) {
			//DealAns
			// printf("%d %d\n", x, y );
			ansArr[ptrX][ptrY] = arr[x][y];
			arr[x][y] = '@';
			switch (towards) {
			case 0:
				if (ptrY + 1 < n && ansArr[ptrX][ptrY + 1] == 0)
					ptrY++;
				else {
					towards = 1;
					ptrX++;
				}
				break;
			case 1:
				if (ptrX + 1 < n && ansArr[ptrX + 1][ptrY] == 0)
					ptrX++;
				else {
					towards = 2;
					ptrY--;
				}
				break;
			case 2:
				if (ptrY - 1 >= 0 && ansArr[ptrX][ptrY - 1] == 0)
					ptrY--;
				else {
					towards = 3;
					ptrX--;
				}
				break;
			case 3:
				if (ptrX - 1 >= 0 && ansArr[ptrX - 1][ptrY] == 0)
					ptrX--;
				else {
					towards = 0;
					ptrY++;
				}
				break;
			}
			// //DealArr
			if (n % 2 == 0) {
				switch (status) {
				case 0:
					if (x == 0) {
						status = 1;
						y++;
					} else {
						status = 3;
						y++;
					}
					break;
				case 1:
					if (y - 1 == 0) {
						status = 2;
					}
					if (x + 1 == n - 1) {
						status = 0;
					}
					x++;
					y--;
					break;
				case 2:
					if (y == 0) {
						status = 3;
						x++;
					} else {
						status = 1;
						x++;
					}
					break;
				case 3:
					if (y + 1 == n - 1) {
						status = 2;
					}
					if (x == 1) {
						status = 0;
					}
					x--;
					y++;
					break;
				}
			} else {
				switch (status) {
				case 0:
					if (x == 0) {
						status = 1;
						y++;
					} else {
						status = 3;
						y++;
					}
					break;
				case 1:
					if (y - 1 == 0) {
						status = 2;
					}
					if (x + 1 == n - 1) {
						status = 0;
					}
					x++;
					y--;
					break;
				case 2:
					if (y == 0) {
						status = 3;
						x++;
					} else {
						status = 1;
						x++;
					}
					break;
				case 3:
					if (x == 1) {
						status = 0;
					}
					if (y + 1 == n - 1) {
						status = 2;
					}
					x--;
					y++;
					break;
				}
			}
			chLeft--;
		}
		for (int i = 0; i < n; i++)
			ansArr[i][n] = '\0';
		for (int i = 0; i < n; i++)
			puts(ansArr[i]);
	}
	return 0;
}