/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-02 17:03:37
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

int N, L, P;
struct Gas {
	int pos;
	int fuel;
} arr[10001];

struct GasCmp {
	bool operator () (const Gas &a, const Gas &b) {
		if(a.fuel < b.fuel)
			return true;
		else
			return false;
	}
};

bool cmp(Gas a, Gas b) {
	return a.pos < b.pos;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int nowPos, nowFuel, ans;
	priority_queue<Gas, vector<Gas>, GasCmp> que;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &arr[i].pos, &arr[i].fuel);
	scanf("%d %d", &L, &P);
	//Init
	arr[N].pos = L;
	arr[N].fuel = 0;
	nowPos = 0;
	nowFuel = P;
	ans = 0;
	for(int i = 0; i < N; i++)
		arr[i].pos = L - arr[i].pos;
	sort(arr, arr + N, cmp);
	for(int i = 0; i <= N; i++) {
		int d = arr[i].pos - nowPos;
		while(nowFuel - d < 0) {
			if(que.empty()) {
				printf("-1\n");
				return 0;
			}
			nowFuel += que.top().fuel;
			que.pop();
			ans++;
		}
		nowFuel -= d;
		nowPos = arr[i].pos;
		que.push(arr[i]);
	}
	printf("%d\n", ans);
	return 0;
}