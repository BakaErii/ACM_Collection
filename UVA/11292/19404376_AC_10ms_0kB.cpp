/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-04-16 23:22:24
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

const int maxN = 20005;

int arrD[maxN];
int arrB[maxN];

int n, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
		for (int i = 0; i < n; i++)
			scanf("%d", &arrD[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &arrB[i]);
		sort(arrD, arrD + n);
		sort(arrB, arrB + m);
		int ptr = 0;
		int cost = 0;
		int dead = 0;
		for (int i = 0; i < n; i++)
			while (ptr < m)
				if (arrB[ptr] >= arrD[i]) {
					cost += arrB[ptr];
					ptr++;
					dead++;
					break;
				} else
					ptr++;
		if (dead == n)
			printf("%d\n", cost );
		else
			printf("Loowater is doomed!\n");

	}
	return 0;
}