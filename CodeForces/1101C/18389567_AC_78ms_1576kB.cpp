/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-13 12:06:08
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

const int maxN = 100005;

struct Segment
{
	int l, r;
	int id;
} seg[maxN];

bool cmp(Segment a, Segment b) {
	if (a.r != b.r)
		return a.r < b.r;
	if (a.l != b.l)
		return a.l < b.l;
	return a.id < b.id;
}

int arr[maxN];
int t, n;
bool isSolved;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &t);
	while (t--) {
		isSolved = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &seg[i].l, &seg[i].r);
			seg[i].id = i;
		}
		sort(seg, seg + n, cmp);
		int minLeft = seg[n - 1].l;
		for (int i = n - 2; i >= 0; i--) {
			if (seg[i].r < minLeft) {
				for (int j = 0; j < n; j++)
					arr[j] = 2;
				for (int j = 0; j <= i; j++)
					arr[seg[j].id] = 1;
				for (int j = 0; j < n; j++)
					printf("%d ", arr[j] );
				putchar('\n');
				isSolved = true;
				break;
			}
			minLeft = min(minLeft, seg[i].l);
		}
		if (!isSolved)
			printf("-1\n");
	}
	return 0;
}