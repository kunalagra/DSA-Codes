# Upto 8 Queens Only
# Also prints subset of all possible solutions
import numpy as np
def Place(k,i):
	for x in range(n):
		if a[x][i]==1 or a[k][i]==2:
			return False
		if i-x>=0:
			if a[k-x][i-x]==1:
				return False
		if i+x<n:
			if a[k-x][i+x]==1:	
				return False
	return True

def Nqueen(r):
	for c in range(n):
		if Place(r,c):
			a[r][c] =1
			return True
	else:
		return False
possible=[]

def tryS():
	row=1
	while row!=n:
		if Nqueen(row):
			row+=1
		else:
			if row-1==0:
				return 0
			else:
				for x in range(n):
					if a[row-1][x]==1:
						a[row-1][x]=2
					else:
						a[row-1][x]==0
				row=row-1
	a[a>1]=0
	possible.append(a)

n = int(input("No. Of Queens: "))
if n<4:
	print("No Possible Outcomes")
else:
	for num in range(n):
		a=np.zeros([n,n])
		a[0][num]=1
		tryS()	
	q=1
	for x in possible:
		print(f"\nPossible Solution #{q}")
		print(x)
		q+=1