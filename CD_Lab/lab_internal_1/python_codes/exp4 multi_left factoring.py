#Write a program for applying left factoring to a given grammar.
#removing left factoring from grammer

n = int(input("Enter the number of productions: "))
productions = [input(f"Enter production {i+1} (e.g., A->abC/abD): ") for i in range(n)]

for prod in productions:
    lhs, rhs = prod.split("->")
    options = rhs.split("/")

    # Find the common prefix
    prefix = options[0]
    for option in options[1:]:
        while not option.startswith(prefix):
            prefix = prefix[:-1]

    if prefix:
        alpha = prefix
        betas = [option[len(alpha):] or "$" for option in options]
        print(f"{lhs} -> {alpha}{lhs}'")
        print(f"{lhs}' -> {'/'.join(betas)}")
    else:
        print(f"No left factoring needed for {prod}.")

# Enter the number of productions: 2
# Enter production 1 (e.g., A->abC/abD): A->abC/abD
# Enter production 2 (e.g., A->abC/abD): B->xyz/xya
# A -> abA'
# A' -> C/D
# B -> xyB'
# B' -> z/a
