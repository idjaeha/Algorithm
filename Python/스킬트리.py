def solution(skill, skill_trees):
    # skill 안에 현재 배울 스킬이 존재할 때,
    # 첫번째 skill이 현재 배울 스킬과 일치하면 넘어간다.
    # 일치하지 않으면 다음 스킬트리로 넘어간다.
    # 스킬 트리가 모두 탐색되면 종료한다.
    answer = 0
    
    # 선행 순서와 스킬트리 중 하나를 뽑아 비교한다.
    # 무사히 탈출했다면 배울 수 있는 스킬트리라고한다. -> 스킬트리의 스킬을 가리키는 idx가 벗어났을 경우
    # 선행순서에 맞지 않는다면 배울 수 없는 스킬트리이다. -> 현재 배우려는 스킬이 선행 스킬 조건에 있고, 현재 배우려는 스킬의 값과 배워야하는 스킬의 값이 다를때
    
    idx = 0 # 스킬트리의 현재 배우려는 스킬
    skill_idx = 0 # 스킬 선행 순서의 현재 배워야하는 스킬
    skill_tree_idx = 0 # 현재 스킬트리
    length = len(skill_trees)
    while skill_tree_idx < length:
        if idx == len(skill_trees[skill_tree_idx]):
            idx = 0 # 스킬트리의 현재 배우려는 스킬
            skill_idx = 0 # 스킬 선행 순서의 현재 배워야하는 스킬
            skill_tree_idx += 1 # 현재 스킬트리
            answer += 1
            continue
        
        if skill_trees[skill_tree_idx][idx] in skill: # 현재 배우려는 스킬이 선행 스킬 배열에 있을 경우
            if skill[skill_idx] == skill_trees[skill_tree_idx][idx]: # 일치하는 경우
                idx += 1
                skill_idx += 1
            else: # 일치하지 않는 경우
                idx = 0 # 스킬트리의 현재 배우려는 스킬
                skill_idx = 0 # 스킬 선행 순서의 현재 배워야하는 스킬
                skill_tree_idx += 1 # 현재 스킬트리
        else: # 스킬 배열에 존재하지 않을 때
            idx += 1
        
    return answer