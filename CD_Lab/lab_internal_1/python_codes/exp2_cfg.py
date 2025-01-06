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
    terminals = set()
    for _, rule in productions:
        for char in rule:
            if not char.isupper() and char != '/':
                terminals.add(char)
    
    print("\t".join(terminals))

if __name__ == "__main__":
    main()
