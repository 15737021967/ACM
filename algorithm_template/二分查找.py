class Solution:

    def binary_search(self, nums, target):
        """
            二分查找，查找区间[0:len(nums)),即左闭右开
        :param nums:
        :param target:
        :return:
        """
        left = 0
        right = len(nums)
        while left < right:
            mid = (right + left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
        return -1

    def binary_search_first(self, nums, target):
        """
            查找最左边界
        :param nums:
        :param target:
        :return:
        """
        left = 0
        right = len(nums)
        if right == 0:
            return -1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            elif nums[mid] < target:
                left = mid + 1
        return left if nums[left] == target else -1

    def binary_search_last(self, nums, target):
        """
            查找最右边界
        :param nums:
        :param target:
        :return:
        """
        left = 0
        right = len(nums)
        if right == 0:
            return -1
        while left < right:
            mid = (right + left) // 2
            if nums[mid] <= target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
        return right - 1 if nums[right-1] == target else -1


if __name__ == '__main__':
    print(Solution().binary_search([1, 2, 3, 3, 4, 5], 5))
    print(Solution().binary_search_first([1, 2, 3, 3, 4, 5], 5))
    print(Solution().binary_search_last([1, 2, 3, 3, 3, 4, 5], 3))
