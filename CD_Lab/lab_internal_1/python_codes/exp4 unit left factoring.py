#Write a program for applying left factoring to a given grammar.
#removing left factoring from production 

prod = input("Enter the production (e.g., A->abC/abD): ")
lhs, rhs = prod.split("->")
options = rhs.split("/")

# Find the common prefix
prefix = options[0]
for option in options[1:]:
    while not option.startswith(prefix):
        prefix = prefix[:-1]

alpha = prefix
betas = [option[len(alpha):] or "$" for option in options]

print(f"{lhs} -> {alpha}{lhs}'")
print(f"{lhs}' -> {'/'.join(betas)}")

# Enter the production (e.g., A->abC/abD): A->abC/abD
# A -> abA'
# A' -> C/D
