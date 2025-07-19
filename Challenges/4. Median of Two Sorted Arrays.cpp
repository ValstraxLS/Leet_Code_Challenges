//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
//The overall run time complexity should be O(log (m+n)).
//
// 
//
//Example 1:
//
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//
//Example 2:
//
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//
// 
//
//Constraints:
//
//    nums1.length == m
//    nums2.length == n
//    0 <= m <= 1000
//    0 <= n <= 1000
//    1 <= m + n <= 2000
//    -106 <= nums1[i], nums2[i] <= 106


#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		double median;

		std::vector<int> v;
		v.reserve(nums1.size() + nums2.size());

		std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(v));

		if (v.size() % 2 == 0) {
			median = (v[v.size()/2 - 1] + v[v.size()/2])/2.0;
		}
		else {
			median = v[v.size()/2.0];
		}
		return median; 
	}
};


int main() {
	Solution s;
	
	double r1;
	std::vector<int> n1_1 = {1, 3};
	std::vector<int> n1_2 = {2};
	std::cout << "Example 1 \n";
	r1 = s.findMedianSortedArrays(n1_1, n1_2);
	std::cout << "Output: " << r1 << std::endl;
	if (r1 == 2.00000) {
		std::cout << "Result: TRUE\n";
	}
	else {
		std::cout << "Result: FALSE\n";
	}

	double r2;
	std::vector<int> n2_1 = {1, 2};
	std::vector<int> n2_2 = {3, 4};
	std::cout << "Example 2 \n";
	r2 = s.findMedianSortedArrays(n2_1, n2_2);
	std::cout << "Output: " << r2 << std::endl;
	if (r2 == 2.50000) {
		std::cout << "Result: TRUE\n";
	}
	else {
		std::cout << "Result: FALSE\n";
	}

	return 0;
}
