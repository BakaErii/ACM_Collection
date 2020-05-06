/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-28 22:54:42
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

string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" , "Saturday"};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calDayofYear(int n) {
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
		return 366;
	return 365;
}

int calDayofMonth(int n, int y) {
	if (calDayofYear(y) == 366 && n == 2)
		return month[1] + 1;
	return month[n - 1];
}

int main(void) {
	int n, tmpn, year, month, day;
	while (cin >> n) {
		if (n == -1)
			return 0;
		tmpn = n;
		year = 2000;
		month = 1;
		while (tmpn >= calDayofYear(year))
			tmpn -= calDayofYear(year++);
		while (tmpn >= calDayofMonth(month, year))
			tmpn -= calDayofMonth(month++, year);
		day = tmpn + 1;
		printf("%d-%02d-%02d ", year, month, day );
		if (n == 0)
			cout << "Saturday" << endl;
		else
			cout << week[(n - 1) % 7] << endl;
	}
	return 0;
}