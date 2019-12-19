def soon(arr, idx):
    result = []
    # idx에 해당하는 숫자를 하나 뽑는다.
    # 뽑은 숫자를 제외한다.
    if len(arr) == 1:
        return [arr[0]]

    picknum = arr[idx]
    next_arr = arr[:idx] + arr[idx+1:]
            
    result.append(picknum)
    result += soon(next_arr, 0)

    return result

arr = list(range(3))
print(soon(arr, 0))

'''
input 0 1 2 
tmp [ ] -> tmp [ soon(0, 1, 2) ]    -> tmp [ 0, soon(1, 2)] -> tmp [ 0, 1, soon(2)] -> tmp [ 0, 1, 2]
                                    -> tmp [ 1, soon(0, 2)] -> tmp [ 1, 0, soon(2)]
                                    -> tmp [ 2, soon(0, 1)] -> tmp [ 2, 0, soon(1)] -> tmp []
'''