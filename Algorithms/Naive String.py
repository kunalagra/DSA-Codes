# Naive String Mathcing Algorithm
a = str(input("Input String: "))
b = str(input("Pattern String: "))

c = len(b)
l = []

for x in range(len(a)):
	if a[x:x+c]==b:
		l.append(x+1)

if l!=[]:
	print("\nThe pattern was found at index: ",l)
	print("Total times pattern found: ",len(l))
else:
	print("\nPattern was not Found")