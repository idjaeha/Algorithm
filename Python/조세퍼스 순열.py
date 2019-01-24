def josephus(num, target):
    myList = [i for i in range(1, num+1)]
    checkList = [0 for i in range(num)]
    curIdx = 0
    result = []
    check = 0
    
    while num != len(result):
        if checkList[curIdx] == 0:    
            check += 1
        
        if check == target:
            result.append(myList[curIdx])
            checkList[curIdx] = 1
            check = 0
            
        curIdx = (curIdx + 1) % num
    
    return result

def main():
    print(josephus(7, 3)) #[3, 6, 2, 7, 5, 1, 4]이 반환되어야 합니다

if __name__ == "__main__":
    main()
