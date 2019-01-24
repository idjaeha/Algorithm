def isParenthesisValid(st):
    myStack = []
    
    for i in st:
        if i in ["(", "{", "[", "<"]:
            myStack.append(i)
        elif i in [")", "}", "]", ">"]:
            if len(myStack) == 0:
                return False
                
            temp = myStack.pop()
            if temp == "(":
                if i != ")":
                    return False
            elif temp == "{":
                if i != "}":
                    return False
            elif temp == "[":
                if i != "]":
                    return False
            elif temp == "<":
                if i != ">":
                    return False
    return len(myStack) == 0

def main():
    examples = ["({()})", "[]<>{}", ")(" "<]", "<(>)"]
    for example in examples:
        print(example, isParenthesisValid(example))

    
if __name__ == "__main__":
    main()
