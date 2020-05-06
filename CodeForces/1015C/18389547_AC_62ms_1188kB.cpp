/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-31 23:07:46
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

struct Songs
{
	int a;
	int b;
	int c;
} song[100005];

bool cmp(Songs a, Songs b) {
	return a.c > b.c;
}

unsigned long long int tot, now;
int n, m;
int ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &song[i].a, &song[i].b);
		song[i].c = song[i].a - song[i].b;
		tot += song[i].a;
	}
	sort(song, song + n, cmp);
	for (i = 0 ; i < n; i++)
		if (tot <= m)
			break;
		else {
			tot -= song[i].c;
			ans++;
		}
	if (ans == n && tot > m)
		printf("-1\n");
	else
		printf("%d\n", ans );
	return 0;
}