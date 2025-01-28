'''
Anwar Hossain Zahid
PhD Student
Department of Computer Science
Iowa State University
'''

# Initialize my_list to test built-in list functions
my_list = [1, "hello", 3.14, True, "world"]

# append() method
my_list.append("new item")
print("After append:", my_list)

# clear() method
my_list.clear()
print("After clear:", my_list)

# copy() method
my_list = [1, "hello", 3.14, True, "world"]
copied_list = my_list.copy()
print("Copied list:", copied_list)

# count() method
count_of_hello = my_list.count("hello")
print("Count of 'hello':", count_of_hello)

# extend() method
my_list.extend([False, 42])
print("After extend:", my_list)

# index() method
index_of_3_14 = my_list.index(3.14)
print("Index of 3.14:", index_of_3_14)

# insert() method
my_list.insert(2, 'inserted item')
print("After insert:", my_list)

# pop() method
popped_element = my_list.pop()
print("Popped element:", popped_element)
print("After pop:", my_list)

# remove() method
my_list.remove('inserted item')
print("After remove:", my_list)

# reverse() method
my_list.reverse()
print("After reverse:", my_list)

# sort() method
# Sorting a list with mixed data types will raise an error
# So, I sorted a list with only strings
string_list = ["banana", "apple", "cherry"]
string_list.sort()
print("After sort:", string_list)
