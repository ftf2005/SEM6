import re

def identify_int_float():
    text = input("Enter a number: ")
    
    # Check if the input is an integer
    if re.match(r"^\d+$", text):
        print("It is an Integer.")
    # Check if the input is a float
    elif re.match(r"^\d+\.\d+$", text):
        print("It is a Float.")
    else:
        print("Invalid input.")

if __name__ == "__main__":
    identify_int_float()
