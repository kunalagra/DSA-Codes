import numpy as np

def calc():
	# Read User Input Strings
	a1 = str(input("Enter 1st String: "))
	a2 = str(input("Enter 2nd String: "))
	i,j = len(a2),len(a1)
	arr = np.zeros( (i+1,j+1))

	# Compute the Table
	for a in range(i):
		for b in range(j):
			if a2[a] == a1[b]:
				arr[a+1][b+1]=arr[a][b]+1
			else:
				arr[a+1][b+1]=max(arr[a+1][b],arr[a][b+1])
	
	# Find the Longest Substring
	res = ""
	while i>0 and j>0:
		if a1[j-1]==a2[i-1]:
			res += a1[j-1]
			i -= 1
			j -= 1
		else:
			if arr[i][j]==arr[i][j-1]:
				j -= 1
			else:
				i -= 1
	# Print The String
	print("Longest Common Substring: ",res[::-1])
	print("Length of Common Substring: ",len(res),"\n")			

	# Print the Table
	print("Table: ")
	print("      ", end="")
	for x in a1:
		print(x,end="  ")
	print("\n ",arr[0])
	for x in range(1,len(arr)):
		print(a2[x-1], arr[x])
	
calc()