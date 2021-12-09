#include <iostream>
#include <vector>
using namespace std;

template<typename T>
unsigned int binary_search(const vector<T>& arr, const T& element)
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
	cout << binary_search(data, 3)<<endl;
	cout << binary_search(data, 2) << endl;
	cout << binary_search(data, 44) << endl;
	return 0;
}