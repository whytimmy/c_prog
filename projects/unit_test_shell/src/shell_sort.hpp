#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include <algorithm>
#include <random>

namespace ShellNameSpace {
	void shell(std::vector<long long> &arr, int lengthArr);
	void shell_sort(std::vector<long long> &arr, int* hammingNumbers, int amountHamming, int lengthArr);
}

#endif
