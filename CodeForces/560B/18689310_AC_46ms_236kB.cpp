/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-13 15:09:53
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

int maxHeight, maxWidth;

struct Ret {
	int height, width;
	void Rotate() {
		swap(height, width);
		return;
	}
} a, b;

bool Check() {
	if(maxHeight - a.height >= b.height && maxWidth >= b.width && maxWidth >= a.width)
		return true;
	if(maxWidth - a.width >= b.width && maxHeight >= a.height && maxHeight >= b.height)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &maxHeight, &maxWidth);
	scanf("%d %d %d %d", &a.height, &a.width, &b.height, &b.width);
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	a.Rotate();
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	b.Rotate();
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	a.Rotate();
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	swap(maxHeight, maxWidth);
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	a.Rotate();
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	b.Rotate();
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	a.Rotate();
	if(Check() == true) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}