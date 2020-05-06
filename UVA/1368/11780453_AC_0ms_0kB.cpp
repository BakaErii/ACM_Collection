/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-30 13:37:03
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

string str[50];
char ans[1001];
int arr[4];

int main(void) {
	int i, j, t, m, n, hans;
	scanf("%d", &t);
	while (t--) {
		//初始化变量
		hans = 0;
		scanf("%d %d", &m, &n);
		for (i = 0; i < m; i++)
			cin >> str[i];
		//找出每一列最多的那个元素 即为最小解 如果元素个数相同 按照小字典序选择
		for (i = 0; i < n; i++) {
			memset(arr, 0, sizeof(arr));
			for (j = 0; j < m; j++)
				switch (str[j][i]) {
				case 'A': arr[0]++; break;
				case 'C': arr[1]++; break;
				case 'G': arr[2]++; break;
				case 'T': arr[3]++; break;
				}
			if (arr[0] >= arr[1] && arr[0] >= arr[2] && arr[0] >= arr[3]) {
				ans[i] = 'A';
				hans += arr[1] + arr[2] + arr[3];
			}
			else if (arr[1] >= arr[0] && arr[1] >= arr[2] && arr[1] >= arr[3]) {
				ans[i] = 'C';
				hans += arr[0] + arr[2] + arr[3];
			}
			else if (arr[2] >= arr[0] && arr[2] >= arr[1] && arr[2] >= arr[3]) {
				ans[i] = 'G';
				hans += arr[1] + arr[0] + arr[3];
			}
			else {
				ans[i] = 'T';
				hans += arr[1] + arr[2] + arr[0];
			}
		}
		ans[i] = '\0';
		puts(ans);
		cout << hans << endl;
	}
	return 0;
}