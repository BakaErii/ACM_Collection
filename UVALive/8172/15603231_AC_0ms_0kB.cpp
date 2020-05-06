/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-21 16:09:03
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

int m, n, x;
int fish, infish;
struct Cats
{
	int left;
	int c;
} cats[105];

bool cmp(Cats a, Cats b) {
	return a.c < b.c;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d %d", &m, &n, &x)) {
		memset(cats, 0, sizeof(cats));
		fish = m;
		infish = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &cats[i].c);
		sort(cats, cats + n, cmp);
		// //perload
		for (int i = 0; i < n; i++) {
			if (fish > 0) {
				cats[i].left = cats[i].c;
				fish--;
				infish++;
			}
		}
		for (int i = 0; i < x - 1; i++) {
			for (int j = 0; j < n; j++) {
				cats[j].left--;
				if (cats[j].left == 0) {
					infish--;
					if (fish > 0) {
						fish--;
						infish++;
						cats[j].left = cats[j].c;
					}
				}
			}
		}
		// for(int i=0;i<n;i++)
		// 	printf("%d ",cats[i].left );
		// putchar('\n');
		for (int j = 0; j < n; j++) {
			cats[j].left--;
			if (cats[j].left == 0)
				infish--;
		}
		printf("%d %d\n", fish, infish );
	}
	return 0;
}