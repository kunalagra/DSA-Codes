import math

def minimax(l,d):
    while d>1:
        i ,a,n = 0,[],len(l)
        if d%2==0:
            while i<n:
                a.append(min(l[i],l[i+1]))
                i += 2
        else:
            while i<n:
                a.append(max(l[i],l[i+1]))
                i += 2
        l = a
        d-=1
    return max(l)

scores = list(map(int, input("Enter List Elements (Eg. 1 0 -1 2 4): ").strip().split()))
d = int(math.log2(len(scores)))

print(minimax(scores,d))