#include <iostream>

#include "isroseok/Rose.h"

int main() {
	const bool ok = Rose::isOK();
	std::cout << "OK? " << std::boolalpha << ok << '\n';
}
