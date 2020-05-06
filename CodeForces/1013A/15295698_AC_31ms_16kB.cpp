/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-08 20:02:39
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

int tmp, n;
unsigned long long int a1, a2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a1 += tmp;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a2 += tmp;
	}
	if (a1 >= a2)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}