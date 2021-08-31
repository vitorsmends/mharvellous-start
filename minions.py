def utilize(s):
    p1 = 0
    p2 = 0
    r = len(s)
    for i in range(r):
        if s[i] in "AEIOU":
            p1 += r-i
        else :
            p2 += r-i
    return p1, p2

def minion_game(s):

    p1_name = "Kevin"
    p2_name = "Stuart"
    
    p1, p2 = utilize(s)
    
    if p1 > p2:
        print(p1_name, p1)
    elif p1 < p2:
        print(p2_name, p2)
    else :
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)