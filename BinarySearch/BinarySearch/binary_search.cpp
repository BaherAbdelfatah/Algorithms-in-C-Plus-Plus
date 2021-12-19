#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int binary_search(const vector<T> arr, T x, unsigned int left, unsigned int right)
{
	if (right >= left)
	{
		unsigned int mid = (left + right) / 2;
		if (arr[mid] == x)
			return mid;
		else if (arr[mid] < x)
			return binary_search(arr, x, mid + 1, right);
		else
			return binary_search(arr, x, left, mid - 1);
	}
	return -1;
}

template<typename T>
int binary_search(const vector<T>& arr, const T& element)
{
	unsigned int low = 0;
	unsigned int high = arr.size() - 1;
	unsigned int mid;

	while (low <= high)
	{
		mid = (high + low) / 2;
		if (arr[mid] < element)
			low = mid + 1;
		else if (arr[mid] > element)
			high = mid - 1;
		else if (arr[mid] == element)
			return mid;
	}

	return -1;
}

int main()
{
	vector<int> data = { 2, 10, 23, 44, 100, 121 };
	cout << binary_search(data, 3) << endl;
	cout << binary_search(data, 2) << endl;
	cout << binary_search(data, 44) << endl;
	vector<int> array = { 1, 3, 5, 7, 9 };
	cout << binary_search(array, 9, 0, array.size() - 1) << endl;
	return 0;
}
