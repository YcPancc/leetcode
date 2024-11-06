/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		// 统计每个元素的频率
		unordered_map<int, int> freqMap;
		for (int num : nums) {
			freqMap[num]++;
		}

		// 使用优先队列（最小堆）来维护频率最高的 k 个元素
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

		for (auto &entry : freqMap) {
			minHeap.push({entry.second, entry.first});
			if (minHeap.size() > k) {
				minHeap.pop();
			}
		}

		// 从优先队列中提取元素，得到结果
		vector<int> result;
		while (!minHeap.empty()) {
			result.push_back(minHeap.top().second);
			minHeap.pop();
		}

		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
