def LCS(s1, s2):
    len_s1 = len(s1)
    len_s2 = len(s2)
    c = [[0]*(len_s2 + 1) for i in range(len_s1 + 1)]

    for i in range(1,len_s1 + 1):  
        for j in range(1,len_s2 + 1):  
            if s1[i-1] == s2[j-1]:  
                c[i][j] = c[i-1][j-1]+1  
            else:  
                c[i][j] = max(c[i-1][j], c[i][j-1]) 
    print("The Lengh of LCS is ", c[-1][-1])
    
    res = []
    i = len_s1
    j = len_s2
    while(i != 0 and j != 0):
        if s1[i - 1] == s2[j - 1]:
            res.insert(0, s1[i - 1])
            i -= 1
            j -= 1
        else:
            if c[i-1][j] > c[i][j-1]:
                i -= 1
            elif c[i-1][j] < c[i][j-1]:
                j -= 1
            else:
                j -= 1 
    print(res)
    
if __name__ == '__main__':
    s1 = [1,3,4,5,6,7,7,8]  
    s2 = [3,5,7,4,8,6,7,8,2]  
    LCS(s1, s2)