/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-09-03 16:33:23
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
} ret[4];

Rectangle unionRectangle(Rectangle a, Rectangle b) {
	//a.wid->b.wid
	if (a.width == b.width)
		return {a.width, a.height + b.height};
	//a.wid->b.height
	if (a.width == b.height)
		return {a.width, a.height + b.width};
	//a.height->b.wid
	if (a.height == b.width)
		return {a.height, a.width + b.height};
	//a.height->b.height
	if (a.height == b.height)
		return {a.height, a.width + b.width};
	//Unsolve
	return { -1, -1};
}

bool check(Rectangle a, Rectangle b, Rectangle c) {
	//AB-C
	if (unionRectangle(unionRectangle(a, b), c).width != -1)
		return true;
	//AC-B
	if (unionRectangle(unionRectangle(a, c), b).width != -1)
		return true;
	//BC-A
	if (unionRectangle(unionRectangle(b, c), a).width != -1)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; i++)
			scanf("%d %d", &ret[i].width, &ret[i].height);
		if (check(ret[0], ret[1], ret[2]) || check(ret[0], ret[1], ret[3]) || check(ret[0], ret[2], ret[3]) || check(ret[1], ret[2], ret[3]))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}