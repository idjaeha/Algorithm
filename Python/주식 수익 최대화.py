
def maximizeProfit(nums):
    result = 0
    min_idx = 0
    max_idx = 0
    #�ö󰡴� ���������� �ִ� ���̸� ���Ѵ�
    for i in range(1,len(nums)):
        #�۾����� min_idx�� �ٲ��.
        if nums[max_idx] > nums[i]:
            min_idx = i
        max_idx = i
        #result������ max_idx - min_idx�� ���� Ŀ���� �����Ѵ�
        if result < nums[max_idx] - nums[min_idx]:
            result = nums[max_idx] - nums[min_idx]
    return result

def main():
    print(maximizeProfit([1,2,3,4,5,6,7])) # 6
    print(maximizeProfit([7,6,5,4,3,2,1])) # 0
    print(maximizeProfit([1,2,3,4,3,2,1])) # 3
    print(maximizeProfit([2,8,19,37,4,5])) # 35

if __name__ == "__main__":
    main()