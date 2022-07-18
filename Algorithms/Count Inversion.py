def merge_lists(left_sublist,right_sublist):
    count_inv = 0
    i,j=0,0
    merged_list = []
    
    while(i<len(left_sublist) and j<len(right_sublist)):
        if left_sublist[i]<right_sublist[j]:
            merged_list.append(left_sublist[i])
            i+=1
        else:
            if len(left_sublist[i:])==1:
                lt1=left_sublist[i]
            else:
                lt1 = left_sublist[i:]
            print(f"Inversion Pairs: ({right_sublist[j]},{lt1})")
            merged_list.append(right_sublist[j])
            j+=1
            count_inv += (len(left_sublist)-i)
    merged_list += left_sublist[i:]
    merged_list += right_sublist[j:]
    
    return merged_list,count_inv

def merge_sort(main_list):
    if len(main_list)<=1:
        return main_list,0
    else:
        midpoint = len(main_list)//2
        (left_sublist,a) = merge_sort(main_list[:midpoint])
        (right_sublist,b) = merge_sort(main_list[midpoint:])
        (sorted_list,c) = merge_lists(left_sublist,right_sublist)
        return (sorted_list,a+b+c)

print("Welcome To Inversion Count with Merge Sort Algorithm")
input_list = list(map(int,input("Enter elements separated by comma (Eg. 1,2,3): ").strip().split(',')))
sorted_list, inversion_count = merge_sort(input_list)
print('\nSorted list ->',sorted_list)
print('\nTotal Inversion count ->',inversion_count,"\n")