/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-20 18:39:41
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

int n, n_1, n_2;
int arr[maxN];
double ans;
double tmp, tmpAns;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d", &n, &n_1, &n_2);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n, greater<int>());
	tmp = 0;
	for(int i = 0; i < n_1; i++)
		tmp += arr[i];
	ans = tmp / n_1;
	tmp = 0;
	for(int i = n_1; i < n_1 + n_2; i++)
		tmp += arr[i];
	ans += tmp / n_2;
	// Another
	tmp = 0;
	for(int i = 0; i < n_2; i++)
		tmp += arr[i];
	tmpAns = tmp / n_2;
	tmp = 0;
	for(int i = n_2; i < n_1 + n_2; i++)
		tmp += arr[i];
	tmpAns += tmp / n_1;
	printf("%.8lf\n", max(ans, tmpAns) );
	return 0;
}