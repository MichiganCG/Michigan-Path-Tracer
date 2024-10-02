#include "main.hpp"
#include "math.hpp"
#include <iostream>

using namespace mpt;

int main()
{
	Float3 test3 = Float3(1.0f, 2.0f, 2.6f);

	std::cout << test3 << Math::magnitude(test3) << std::endl;
	std::cout << test3 << Math::normalize(test3) << std::endl;
	std::cout << test3 << Math::min(test3, test3) << std::endl;
	std::cout << static_cast<Int3>(test3) << Math::squared_magnitude(static_cast<Int3>(test3)) << std::endl;
	return 0;
}
