/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-23 15:52:32
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

const int maxN = 1001;

int arrDp[maxN][maxN >> 1 | 1];
int arrCost[maxN][maxN >> 1 | 1];
string str;

struct Node {
	int pi;
	int ji;
} arr[maxN];

bool cmp(Node a, Node b) {
	if(a.pi == b.pi)
		return a.ji < b.ji;
	return a.pi > b.pi;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, sum;
	int isPetraFirst = 0;
	cin >> t;
	while(t--) {
		cin >> n >> str;
		//Init
		sum = 0;
		isPetraFirst = 0;
		memset(arrDp, 0, sizeof(arrDp));
		memset(arrCost, 0, sizeof(arrCost));
		//Special Judge
		if(str == "Petra")
			isPetraFirst = 1;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i].pi >> arr[i].ji;
			sum += arr[i].pi;
		}
		sort(arr + 1, arr + n + 1, cmp);
		//CalDP&Cost
		for(int i = 1; i <= n - isPetraFirst; i++) {
			for(int j = 1; j <= (i + 1) / 2; j++)
				//Update
				if(arrDp[i - 1][j] > arrDp[i - 1][j - 1] + arr[i + isPetraFirst].ji) {
					arrDp[i][j] = arrDp[i - 1][j];
					arrCost[i][j] = arrCost[i - 1][j];
				} else if(arrDp[i - 1][j] == arrDp[i - 1][j - 1] + arr[i + isPetraFirst].ji) {
					arrDp[i][j] = arrDp[i - 1][j];
					arrCost[i][j] = min(arrCost[i - 1][j], arrCost[i - 1][j - 1] + arr[i + isPetraFirst].pi);
				} else {
					arrDp[i][j] = arrDp[i - 1][j - 1] + arr[i + isPetraFirst].ji;
					arrCost[i][j] = arrCost[i - 1][j - 1] + arr[i + isPetraFirst].pi;
				}
		}
		printf("%d %d\n", sum - arrCost[n - isPetraFirst][(n - isPetraFirst + 1) / 2], arrDp[n - isPetraFirst][(n - isPetraFirst + 1) / 2] );
	}
	return 0;
}