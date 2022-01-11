#include <iostream>
#include <numeric>
#include "libshared.h"

int add(int a, int b){
	return a + b;
}

double sum(double* array, std::size_t nelem){
	return std::accumulate(array, array + nelem, 0.);
}
