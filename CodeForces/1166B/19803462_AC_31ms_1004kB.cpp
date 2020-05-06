/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-19 09:57:39
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

const char v[5] = {'a', 'e', 'i', 'o', 'u'};
int k, n, m;

void Init() {
	scanf("%d", &k);
	for (int i = 2; i <= sqrt(k) + 1; i++) {
		if (k % i != 0)
			continue;
		int tmp = k / i;
		if (tmp >= 5 && i >= 5) {
			n = tmp;
			m = i;
			k = -1;
			break;
		}
	}
	return;
}

char str[1005 * 1005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Init();
	if (k != -1) {
		printf("-1\n");
		return 0;
	}
	int ptr = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			str[ptr++] = v[(i + j) % 5];
	str[ptr] = '\0';
	printf("%s\n", str );
	return 0;
}