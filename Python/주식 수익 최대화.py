
def maximizeProfit(nums):
    result = 0
    min_idx = 0
    max_idx = 0
    # 올라가는 구간에서의 최대 차이를 구한다
    for i in range(1, len(nums)):
        # 작아질때 min_idx가 바뀐다.
        if nums[min_idx] > nums[i]:
            min_idx = i
        # result값보다 max_idx - min_idx의 값이 커지면 변경한다
        if result < nums[i] - nums[min_idx]:
            result = nums[i] - nums[min_idx]
    return result


def main():
    print(maximizeProfit([1, 2, 3, 4, 5, 6, 7]))  # 6
    print(maximizeProfit([7, 6, 5, 4, 3, 2, 1]))  # 0
    print(maximizeProfit([1, 2, 3, 4, 3, 2, 1]))  # 3
    print(maximizeProfit([2, 8, 19, 37, 4, 5]))  # 35


if __name__ == "__main__":
    main()
