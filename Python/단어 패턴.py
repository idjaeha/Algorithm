def wordPattern(pattern, strList):
    str_save = ["" for _ in range(26)]
    for i in range(len(pattern)):
        #배열에 없으면 추가
        if(str_save[ord(pattern[i]) - ord("a")] == ""):
            str_save[ord(pattern[i]) - ord("a")] = strList[i]
        #배열에 있으면 비교
        else:
            if(str_save[ord(pattern[i]) - ord("a")] != strList[i]):
                return False
    return True

def main():
    print(wordPattern("aabb", ["elice", "elice", "alice", "alice"])) # should return True
    print(wordPattern("abab", ["elice", "elice", "alice", "alice"])) # should return False
    

if __name__ == "__main__":
    main()
