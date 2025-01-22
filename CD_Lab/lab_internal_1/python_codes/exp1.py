def identify_token(input_str):
    if input_str[0].isalpha():
        if input_str.endswith('()'):
            print("Input is a function.")
        elif input_str.endswith(']'):
            print("Input is an array.")
        else:
            print("Input is a variable.")
    elif input_str[0].isdigit():
        if '.' in input_str:
            print("Input is a real constant.")
        else:
            print("Input is an integer constant.")
    else:
        print("Invalid input.")

# Example usage
input_str = input("Enter the string: ")
identify_token(input_str)
