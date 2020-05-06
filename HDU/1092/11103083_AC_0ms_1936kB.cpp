#include <iostream>

int main(void) {
	int n, r, tmp;
	while (std::cin >> n && n != 0) {
		r = 0;
		while (n--) {
			std::cin >> tmp;
			r += tmp;
		}
		std::cout<<r<<std::endl;
	}
	return 0;
}