input_str = input()  # Get input string from the user
result_str = ''      # Initialize an empty string to store the result

# Convert case
for char in input_str:
    if char.isupper():
        result_str += char.lower()  # Convert uppercase to lowercase
    elif char.islower():
        result_str += char.upper()  # Convert lowercase to uppercase

print(result_str)  # Print the final result

# str = input()  # Get input string from the user
# str2 = ''      # Initialize an empty string to store the result
#
# # Iterate over each character in the input string
# for i in str:
#     if i.isupper() == True:  # If the character is uppercase
#         str2 += i.lower()     # Convert to lowercase and add to str2
#     elif i.islower() == True: # If the character is lowercase
#         str2 += i.upper()     # Convert to uppercase and add to str2
#
# print(str2)  # Print the final result


#print(input().swapcase())

