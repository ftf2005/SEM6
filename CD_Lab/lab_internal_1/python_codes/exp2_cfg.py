#Write a program to read CFG productions and store into corresponding data structures.

def main():
    n = int(input("Enter the number of productions: "))
    productions = []
    
    for _ in range(n):
        non_terminal = input("Enter the non-terminal: ")
        rule = input("Enter the RHS production: ")
        productions.append((non_terminal, rule))

    print("\nEntered productions are:")
    for non_terminal, rule in productions:
        print(f"{non_terminal} -> {rule}")
        print(f"The starting symbol of the production is: {non_terminal}")
    
    # Non-terminals
    print("\nThe non-terminals are:")
    for non_terminal, _ in productions:
        print(non_terminal)
    
    # Terminals
    print("\nThe terminals are:")
    for _, rule in productions:
        print(rule)

if __name__ == "__main__":
    main()

# Enter the number of productions: 3
# Enter the non-terminal: A
# Enter the RHS production: bd
# Enter the non-terminal: B
# Enter the RHS production: bf
# Enter the non-terminal: C
# Enter the RHS production: jfg

# Entered productions are:
# A -> bd
# The starting symbol of the production is: A
# B -> bf
# The starting symbol of the production is: B
# C -> jfg
# The starting symbol of the production is: C

# The non-terminals are:
# A
# B
# C

# The terminals are:
# g	d	f	b	j
