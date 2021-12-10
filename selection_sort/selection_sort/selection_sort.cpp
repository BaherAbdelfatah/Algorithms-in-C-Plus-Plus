#include <iostream>
#include <vector>
using namespace std;

template <typename T>
unsigned int find_smallest(const vector<T>& arr)
{
	T smallest = arr[0];
	unsigned int s_index = 0;
	
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			s_index = i;
		}
	}
	
	return s_index;
}

template <typename T>
vector<T> selection_sort(vector<T> arr)
{
	vector<T> result;
	while(!arr.empty())
	{
		unsigned int index = find_smallest(arr);
		result.push_back(arr[index]);
		arr.erase(arr.begin()+index);
	}

	return result;
}

int main()
{
	vector<float> arr = { 1.2, 1.0, 3, 0 ,-1, 0.5, 100, -99 };
	vector<float> sorted = selection_sort(arr);

	cout << "Sorted array: ";
	for (auto num : sorted)
		cout << num << " ";
	cout << endl;
	return 0;
}