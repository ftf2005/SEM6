#Write a program for eliminating Left-Recursion from the given grammar. 
#left recursion from grammar 

def main():
    n = int(input("Enter the number of productions: "))
    productions = [input(f"Enter production {i + 1}: ") for i in range(n)]
    
    print("\nProcessing productions...\n")
    
    for prod in productions:
        if prod[0] == prod[3]:
            print(f"Production '{prod}' is left recursive")
            
            alpha, beta = prod[4:].split('/', 1)
            
            print(f"{prod[0]} -> {beta}{prod[0]}'")
            print(f"{prod[0]}' -> {alpha}{prod[0]}' | $\n")
        else:
            print(f"Production is not left recursive")

if __name__ == "__main__":
    main()


# Enter the number of productions: 3
# Enter production 1: E->E+T/T
# Enter production 2: T->T*F/F
# Enter production 3: F->(e)/id

# Production 1 is left recursive:
# E->TE'
# E'->+TE'/$

# Production 2 is left recursive:
# T->FT'
# T'->*FT'/$

# Production 3 is not left recursive.
