#include <stdio.h>
#include <vector>
#include "leetcode.h"

using namespace std;


//class Solution{
//	public:
//		int RemoveDuplicates(vector<int> &nums){
//
//			if (nums.empty())
//				return 0;
//			int index = 0;
//			for (unsigned int i = 1; i < nums.size(); i++) {
//				if (nums[index] != nums[i])
//					nums[++index] = nums[i];
//			}
//			return index + 1;
//		}
//};


int main(){
	vector<int> n;
	int i;
	for(i=0;i<6;i++){
		n.push_back(i);
	}

	n.clear();
	n.push_back(1);
	n.push_back(2);
	n.push_back(2);
	n.push_back(3);
	n.push_back(4);
	n.push_back(4);
	n.push_back(4);
	Solution s;
	i = s.RemoveDuplicates(n);
	printf("%d",i);
}
