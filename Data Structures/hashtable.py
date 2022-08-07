hash_table = {}

flag = True
def one():
	key = input("Enter the Key: ")
	value = input("Enter Value: ")
	hash_table[key] = value
def two():
	key = input("Enter the Key to delete: ")
	del hash_table[key]
def three():
	key = input("Enter the Key to search: ")
	print(hash_table[key])	
def four():
	print(hash_table)
def five():
	global flag
	flag = False
def default():
	return "Incorrect"

switch = {1: one, 2:two,3:three,4:four,5:five}
def switcher(choice):	
	return switch.get(choice,default)()


print("HashTable in Python")
print("Please Enter Operartion to perform")
while flag:
	choice = int(input("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter Choice: "))
	switcher(choice)
