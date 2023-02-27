# 최초 풀이
def solution1(id_list, report, k):
    answer = []
    user_of_reported = {}
    user_of_reporter = {}
    
    for user in id_list:
        user_of_reported[user] = set()
        user_of_reporter[user] = set()
    
    for r in report:
        reporter, reported = r.split()
        user_of_reported[reported].add(reporter)
        user_of_reporter[reporter].add(reported)
        
    for user in id_list:
        res = 0
        for reported in user_of_reporter[user]:
            if len(user_of_reported[reported]) >= k: res += 1
            
        answer.append(res)
                
    return answer

# 수정풀이
def solution2(id_list, report, k):
    answer = []
    user_of_reported = {}
    
    for user in id_list:
        user_of_reported[user] = set()
    
    for r in report:
        reporter, reported = r.split()
        user_of_reported[reported].add(reporter)
        
    for user in id_list:
        res = 0
        my_reports = dict(filter(lambda x: user in x[1], user_of_reported.items()))
        
        for reported in my_reports:
            if len(user_of_reported[reported]) >= k: res += 1
        answer.append(res)
                
    return answer

# 다른 사람의 풀이
def solution(id_list, report, k):
    answer = [0] * len(id_list)    
    reports = {x : 0 for x in id_list}

    for r in set(report):
        reports[r.split()[1]] += 1

    for r in set(report):
        if reports[r.split()[1]] >= k:
            answer[id_list.index(r.split()[0])] += 1

    return answer
    