/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-24 13:10:49
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

struct Rectangle
{
	int width, height;
} R[4];

Rectangle MergeRectangle(Rectangle a , Rectangle b) {
	if (a.width == b.width)
		return {a.width, a.height + b.height};
	if (a.width == b.height)
		return {a.width, a.height + b.width};
	if (a.height == b.width)
		return {b.width, b.height + a.width};
	if (a.height == b.height)
		return {a.width + b.width, a.height};
	return { -1, -1};
}

bool Check(Rectangle a, Rectangle b, Rectangle c) {
	if (MergeRectangle(MergeRectangle(a, b), c).width != -1)
		return true;
	if (MergeRectangle(MergeRectangle(a, c), b).width != -1)
		return true;
	if (MergeRectangle(MergeRectangle(b, c), a).width != -1)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d %d %d %d %d", &R[0].width, &R[0].height, &R[1].width, &R[1].height, &R[2].width, &R[2].height, &R[3].width, &R[3].height);
		if (Check(R[0], R[1], R[2]) || Check(R[0], R[1], R[3]) || Check(R[0], R[2], R[3]) || Check(R[1], R[2], R[3]))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}