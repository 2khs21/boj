def solution(polynomial):
    answer = ''
    
    terms = polynomial.split()
    x_sum = 0
    n_sum = 0
    
    for term in terms:
        if 'x' in term:
            if term == 'x':
                x_sum += 1
            else:
                x_sum += int(term[:-1])
        elif term != '+':
            n_sum += int(term)
    
    if x_sum != 0:
        if x_sum == 1:
            answer = 'x'
        else:
            answer = str(x_sum) + 'x'
        if n_sum != 0:
            answer += " + "
    if n_sum > 0:
        answer += str(n_sum)
    return answer