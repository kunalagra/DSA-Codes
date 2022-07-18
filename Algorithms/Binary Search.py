def binarySearch(arr, find, low, high):
	if high >= low:
		mid = low + (high - low)//2
		if arr[mid] == find:
			return mid
		elif arr[mid] < find:
			return binarySearch(arr, find, mid + 1, high)
		else:
			return binarySearch(arr, find, low, mid-1)
	else:
		return -1

if __name__=="__main__":
	arr = list(map(int,input("Enter elements (Eg. 1 2 3): ").strip().split()))
	f=int(input("Enter the Number to find: "))
	result = binarySearch(arr, f, 0, len(arr)-1)
	if result != -1:
		print(f"Element is found. It is at position {result+1}")
	else:
		print("Not found")