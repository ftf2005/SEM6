import re

def classify_input(s):
    s = s.strip()
    
    if re.match(r'^[a-zA-Z][a-zA-Z0-9]*$', s):
        return "Input is a variable."
    elif re.match(r'^\d+$', s):
        return "Input is an integer constant."
    elif re.match(r'^\d+\.\d+$', s):
        return "Input is a real constant."
    elif re.match(r'^[a-zA-Z][a-zA-Z0-9]*\($', s):
        return "Input is a function."
    elif re.match(r'^[a-zA-Z][a-zA-Z0-9]*\[$', s):
        return "Input is an array."
    else:
        return "There is an error in the given expression."

# Get input from the user
input_str = input("Enter the string: ")
print(classify_input(input_str))
