#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int first = left, last = right;
    int key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) --last;
        if (first < last) nums[first++] = nums[last];

        while (first < last && nums[first] <= key) ++first;
        if (first < last) nums[last--] = nums[first];
    }
    nums[first] = key;

    quickSort(nums, left, first - 1);
    quickSort(nums, first + 1, right);
}

int main() {
    vector<int> nums = {10, 8, 4, 6, 9, 10, 123, 6, 2, 14, 3, 8, 5};
    quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}