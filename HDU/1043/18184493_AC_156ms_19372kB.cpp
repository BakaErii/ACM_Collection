/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-11 01:11:20
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

const int maxN = 362885;

const int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
const char df[] = {'l', 'r', 'd', 'u'};
vector<char> ansPath[maxN];
bool vis[maxN];

struct Status
{
	vector<char> path;
	int arr[10];
	int xLoc;
	int hash;
};

int CalHash(int arr[]) {
	int tot = 0;
	for (int i = 0; i < 9; i++) {
		int currI = 0;
		for (int j = i + 1; j < 9; j++)
			if (arr[j] < arr[i])
				currI++;
		tot += currI * (fac[9 - i - 1]);
	}
	return tot + 1;
}

void BFS() {
	queue<Status> que;
	Status firstStatus, nowStatus, nextStatus;
	for (int i = 0; i < 8; i++)
		firstStatus.arr[i] = i + 1;
	firstStatus.arr[9] = 0;
	firstStatus.hash = CalHash(firstStatus.arr);
	firstStatus.xLoc = 8;
	que.push(firstStatus);
	vis[firstStatus.hash] = true;
	while (!que.empty()) {
		nowStatus = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int X = nowStatus.xLoc / 3 + dx[i];
			int Y = nowStatus.xLoc % 3 + dy[i];
			if (X >= 0 && X < 3 && Y >= 0 && Y < 3) {
				nextStatus = nowStatus;
				nextStatus.xLoc = X * 3 + Y;
				nextStatus.arr[nowStatus.xLoc] = nextStatus.arr[nextStatus.xLoc];
				nextStatus.arr[nextStatus.xLoc] = 0;
				nextStatus.hash = CalHash(nextStatus.arr);
				nextStatus.path.push_back(df[i]);
				if (vis[nextStatus.hash] == false) {
					vis[nextStatus.hash] = true;
					ansPath[nextStatus.hash] = nextStatus.path;
					que.push(nextStatus);
				}
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char str[5];
	int arr[10], hashValue;
	BFS();
	while (~scanf("%s", str)) {
		arr[0] = str[0] == 'x' ? 0 : str[0] - '0';
		for (int i = 0; i < 8; i++) {
			scanf("%s", str);
			arr[i + 1] = str[0] == 'x' ? 0 : str[0] - '0';
		}
		hashValue = CalHash(arr);
		if (vis[hashValue] == true) {
			for (int i = (int)ansPath[hashValue].size() - 1; i >= 0; i--)
				putchar(ansPath[hashValue][i]);
			putchar('\n');
		} else
			printf("unsolvable\n");
	}
	return 0;
}