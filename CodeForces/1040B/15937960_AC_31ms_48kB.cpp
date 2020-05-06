/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-09-14 16:07:02
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

int arr[10000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int minOp, tmp;
	scanf("%d %d", &n, &k);
	//calMinOp
	tmp = n % (2 * k + 1);
	minOp = n / (2 * k + 1) + 1;
	//calStep
	int cnt = 0;
	if(tmp != 0) {
		int ptr = tmp;
		if(tmp > k)
			goto els;
		arr[cnt++] = ptr;
		for(int i = 1; i < minOp; i++) {
			ptr += 2 * k + 1;
			arr[cnt++] = ptr;
		}
	} else {
		minOp--;
els:
		;
		int ptr = k + 1;
		arr[cnt++] = ptr;
		for(int i = 1; i < minOp; i++) {
			ptr += 2 * k + 1;
			arr[cnt++] = ptr;
		}
	}
	cout << minOp << endl;
	for(int i = 0; i < cnt; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}