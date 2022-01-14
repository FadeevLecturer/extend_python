#include <cstddef>

extern "C"
{
	__declspec(dllexport) int add(int a, int b);
	__declspec(dllexport) double sum(double* array, std::size_t nelem);

}