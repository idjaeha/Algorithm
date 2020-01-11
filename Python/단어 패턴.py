def wordPattern(pattern, strList):
    str_save = ["" for _ in range(26)]
    for i in range(len(pattern)):
        if(str_save[ord(pattern[i]) - ord("a")] == ""):
            str_save[ord(pattern[i]) - ord("a")] = strList[i]
        else:
            if(str_save[ord(pattern[i]) - ord("a")] != strList[i]):
                return False
    return True


def main():
    # should return True
    print(wordPattern("aabb", ["elice", "elice", "alice", "alice"]))
    # should return False
    print(wordPattern("abab", ["elice", "elice", "alice", "alice"]))


if __name__ == "__main__":
    main()
