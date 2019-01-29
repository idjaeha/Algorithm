def wordPattern(pattern, strList):
    str_save = ["" for _ in range(26)]
    for i in range(len(pattern)):
        #�迭�� ������ �߰�
        if(str_save[ord(pattern[i]) - ord("a")] == ""):
            str_save[ord(pattern[i]) - ord("a")] = strList[i]
        #�迭�� ������ ��
        else:
            if(str_save[ord(pattern[i]) - ord("a")] != strList[i]):
                return False
    return True

def main():
    print(wordPattern("aabb", ["elice", "elice", "alice", "alice"])) # should return True
    print(wordPattern("abab", ["elice", "elice", "alice", "alice"])) # should return False
    

if __name__ == "__main__":
    main()
