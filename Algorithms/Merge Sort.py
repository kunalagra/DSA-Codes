def merge(left, right):
    #left_index - li, right_index - ri
    li, ri = 0, 0
    result = []
    while li < len(left) and ri < len(right):
        if left[li] < right[ri]:
            result.append(left[li])
            li += 1
        else:
            result.append(right[ri])
            ri += 1
    result += left[li:]
    result += right[ri:]

    return result

def merge_sort(array):
    if len(array) <= 1:
        return array
    half = len(array) // 2
    left = merge_sort(array[:half])
    right = merge_sort(array[half:])
    return merge(left, right)
    

if __name__=="__main__":
	print("Welcome To Merge & Sort Algorithm")
	numlist = list(map(int,input("Enter elements (Eg. 1 2 3): ").strip().split()))
	a= merge_sort(numlist)
	print(f'The Sorted array is: {a}')
