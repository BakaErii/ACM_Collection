#include <iostream>

int main(void) {
	int i, n, r, tmp;
	std::cin >> i;
	while (i--)
	{
		r = 0;
		std::cin >> n;
		while (n--) {
			std::cin >> tmp;
			r += tmp;
		}
		std::cout << r << std::endl;
	}
	return 0;
}