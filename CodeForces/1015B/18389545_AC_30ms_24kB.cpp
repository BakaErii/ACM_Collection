/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-15 14:25:09
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

int n;
string strA, strB;
vector<int> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> strA >> strB;
	for (int i = 0; i < n; i++) {
		if (strA[i] == strB[i])
			continue;
		int pos = -1;
		for (int j = i + 1; j < n; j++)
			if (strA[j] == strB[i]) {
				pos = j;
				break;
			}
		if (pos == -1) {
			printf("-1\n");
			return 0;
		}
		for (int j = pos - 1; j >= i; j--) {
			swap(strA[j], strA[j + 1]);
			ans.push_back(j);
		}
	}
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d ", it + 1 );
	putchar('\n');
	return 0;
}