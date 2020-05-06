/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-11 20:34:00
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

const int maxN = 15;

int arr[maxN];
char str[100005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		switch (str[i]) {
		case 'L':
			for (int i = 0; i < 10; i++)
				if (arr[i] == 0) {
					arr[i] = 1;
					break;
				}
			break;
		case 'R':
			for (int i = 9; i >= 0 ; i--)
				if (arr[i] == 0) {
					arr[i] = 1;
					break;
				}
			break;
		default:
			arr[str[i] - '0'] = 0;
			break;
		}
	for (int i = 0; i < 10; i++)
		printf("%d", arr[i]);
	putchar('\n');
	return 0;
}