def isStackSequence(nums):
    myList = [i for i in range(len(1, nums+1))]
    myCheckList = []
    preNum = nums[0] + 1
    idx = 0
    for i in range(len(nums)):
        if nums[i] == preNum - 1:
            myCheckList.append(nums[i])
            preNum = nums[i]
        elif nums[i] < preNum - 1:
            return False
        elif nums[i] > preNum:
            while(len(myCheckList) != 0):
                if myList[idx] != myCheckList.pop()
                    return False
                idx += 1
    return True

def main():
    print(isStackSequence([2, 1, 4, 3])) # True가 리턴되어야 합니다
    print(isStackSequence([3, 1, 2, 4])) # False가 리턴되어야 합니다

    
if __name__ == "__main__":
    main()
