while True:
    nums = list(map(int, input().split()))
    nums.sort()

    if not any(nums):
        break

    if nums[2] >= nums[1] + nums[0]:
        print("wrong")
        continue

    if nums[2] ** 2 == (nums[1] ** 2) + (nums[0] ** 2):
        print("right")
    else:
        print("wrong")
