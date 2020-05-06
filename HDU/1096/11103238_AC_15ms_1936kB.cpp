#include <iostream>

int main(void) {
	int n, i, r, tmp;
	std::cin >> n;
	while (n--) {
		std::cin >> i;
		r = 0;
		while (i--) {
			std::cin >> tmp;
			r += tmp;
		}
		std::cout << r << std::endl;
		if (n != 0)
		{
			std::cout << std::endl;
		}
	}
	return 0;
}