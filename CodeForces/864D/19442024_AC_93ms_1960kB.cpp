/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-24 18:03:04
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

int arr[200005];
int cnt[200005];
bool vis[200005];
bool bef[200005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0, n, ptr = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
		vis[arr[i]] = true;
	}
	for(int i = 0; i < n; i++) {
		if(cnt[arr[i]] > 1) {
			while(vis[ptr] == true)
				ptr++;
			if(ptr > arr[i] && bef[arr[i]] == false) {
				bef[arr[i]] = true;
				continue;
			}
			cnt[arr[i]]--;
			arr[i] = ptr;
			ans++;
			vis[ptr] = true;
		}
		bef[arr[i]] = true;
	}
	printf("%d\n", ans );
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i] );
	putchar('\n');
	return 0;
}