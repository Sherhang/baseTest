//make -f makefile_c++11
#include <iostream>
#include <vector>
using namespace std;


template <class T>
int partSort(T& nums, int low, int high);
template <class T>
void quickSort(T& nums, int left, int right);

int main(int argc, char* argv[])
{
	vector<string> nums = {"hello","hang" ,"ye", "heaa"};
	quickSort(nums, 0, nums.size());
	for (auto& num : nums)
	{
		cout << num << ' ';
	}
        cout<<endl;
	return 0;
}

template <class T>
int partSort(T& nums, int low, int high)
{
	auto& pivot = nums[high - 1];
	int left = low, right = high - 1;
	while (left < right)
	{
		while (left < right && nums[left] <= pivot) left++;
		while (left < right && nums[right] >= pivot) right--;
		swap(nums[left], nums[right]);
	}
	swap(nums[left], nums[high - 1]);
	return left;
}

template <class T>
void quickSort(T& nums, int low, int high)
{
	int pivot = 0;
	if (low +1< high )
	{
		pivot = partSort(nums, low, high);
		quickSort(nums, low, pivot);
		quickSort(nums, pivot + 1, high);
	}
	return;
}
