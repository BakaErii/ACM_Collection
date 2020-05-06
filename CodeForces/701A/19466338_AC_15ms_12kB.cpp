/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-27 09:03:09
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

const int maxN = 105;

int n;
int arr[maxN];
int vis[maxN];
int cnt[maxN][2];
double sum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sum /= n / 2;
	for(int i = 1; i <= n / 2; i++)
		for(int j = 1; j <= n; j++) {
			if(vis[j] == false && cnt[i][0] == 0) {
				vis[j] = true;
				cnt[i][0] = j;
			}
			if(vis[j] == false && arr[j] + arr[cnt[i][0]] == sum) {
				vis[j] = true;
				cnt[i][1] = j;
				break;
			}
		}
	for(int i = 1; i <= n / 2; i++)
		printf("%d %d\n", cnt[i][0], cnt[i][1]);
	return 0;
}