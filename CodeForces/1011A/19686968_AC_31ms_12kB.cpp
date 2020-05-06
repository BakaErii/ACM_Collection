/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-05-11 09:04:41
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

const int maxN = 55;

int arrD[maxN];
char str[maxN];
int n, k, minAns = -1;

vector<char> V;

void DFS(int x, int val, int d) {
	if(d == k) {
		if(minAns == -1)
			minAns = val;
		else
			minAns = min(minAns, val);
		return;
	}
	if(x >= (int)V.size())
		return;
	for(int i = x + 1; i < (int)V.size(); i++)
		if(V[i] > V[x] + 1)
			DFS(i, val + (V[i] - 'a' + 1), d + 1);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	for(int i = 0; i < n; i++)
		arrD[str[i] - 'a']++;
	V.push_back('\0');
	for(int i = 0; i < 26; i++)
		if(arrD[i] != 0)
			V.push_back('a' + i);
	DFS(0, 0, 0);
	printf("%d\n", minAns );
	return 0;
}