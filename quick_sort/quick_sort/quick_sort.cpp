#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> quick_sort(const vector<T>& arr)
{
	if (arr.size() < 2)
		return arr;
	const T* pivot = &arr.front() + arr.size() / 2 - 1;
	vector<T> less;
	vector<T> more;
	for (const T* item = &arr.front(); item <= &arr.back(); item++)
	{
		if (item == pivot)
			continue;
		if (*item < *pivot)
			less.push_back(*item);
		else
			more.push_back(*item);
	}
	vector<T> stored_less = quick_sort(less);
	vector<T> stored_more = quick_sort(more);
	stored_less.push_back(*pivot);
	stored_less.insert(stored_less.end(), stored_more.begin(), stored_more.end());

	return stored_less;
}

int main()
{
	std::vector<int> arr = { 69, 60, 38, 82, 99, 15, 8, 94, 30, 42, 35, 40, 63, 1, 49, 66, 93, 83, 20, 32, 87, 6, 78, 17, 2, 61, 91, 25, 7, 4, 97, 31, 23, 67, 95, 47, 55, 92, 37, 59, 73, 81, 74, 41, 39 };
	std::vector<int> sorted = quick_sort(arr);
	for (int num : sorted) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}