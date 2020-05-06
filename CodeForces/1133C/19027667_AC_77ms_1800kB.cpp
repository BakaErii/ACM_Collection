/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-01 07:39:32
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
#include <deque>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int maxN = 200005;

int n, ans = 1;
int arr[maxN];

deque<int> dQue;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		if(dQue.empty() == true) {
			dQue.push_back(arr[i]);
			continue;
		}
		while(!dQue.empty() && (arr[i] - dQue.front()) > 5)
			dQue.pop_front();
		dQue.push_back(arr[i]);
		ans = max(ans, (int)dQue.size());
	}
	printf("%d\n", ans);
	return 0;
}