def solution(answers):
    scores = [0, 0, 0]
    patterns = [  
        [1, 2, 3, 4, 5],
        [2, 1, 2, 3, 2, 4, 2, 5],
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]  
    
    for i, ans in enumerate(answers):
        for j in range(3):
            if ans == patterns[j][i % len(patterns[j])]:
                scores[j] += 1
    

    max_score = max(scores)
    return [i+1 for i, score in enumerate(scores) if score == max_score]


#from itertools import cycle


# def solution(answers):
#     # 각 수포자의 찍기 패턴
#     patterns = [
#         [1, 2, 3, 4, 5],
#         [2, 1, 2, 3, 2, 4, 2, 5],
#         [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
#     ]
#
#     # cycle을 사용하여 각 패턴을 무한 반복하는 이터레이터 생성
#     p1 = cycle(patterns[0])
#     p2 = cycle(patterns[1])
#     p3 = cycle(patterns[2])
#
#     scores = [0, 0, 0]
#
#     # 정답지를 순회하며 각 수포자의 예상 답과 비교
#     for ans in answers:
#         if ans == next(p1):
#             scores[0] += 1
#         if ans == next(p2):
#             scores[1] += 1
#         if ans == next(p3):
#             scores[2] += 1
#
#     # 최고 점수 찾기
#     max_score = max(scores)
#
#     # 최고 점수를 받은 모든 사람의 번호를 리스트로 반환
#     return [i + 1 for i, score in enumerate(scores) if score == max_score]
