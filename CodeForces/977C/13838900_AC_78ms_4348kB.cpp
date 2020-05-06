/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-08 07:49:55
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

int arr[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, ans;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	//Check
	if(k == 0) {
		ans = arr[0] - 1;
	} else {
		if(arr[k - 1] == arr[k])
			ans = -1;
		else
			ans = arr[k - 1];
	}
	if(ans<=0||ans>1000000000)
		ans=-1;
	printf("%d\n",ans );
	return 0;
}