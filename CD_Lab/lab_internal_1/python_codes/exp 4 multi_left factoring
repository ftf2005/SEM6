def remove_left_factoring():
    n = int(input("Enter the number of productions: "))
    productions = [input(f"Enter production {i+1}: ").strip() for i in range(n)]
    
    for prod in productions:
        # Validate the production format
        if '->' not in prod or '/' not in prod:
            print(f"The production '{prod}' is not in the correct format.")
            continue
        
        # Split the production into LHS and RHS
        non_terminal, rhs = prod.split("->")
        options = rhs.split("/")
        
        # Find the common prefix
        common_prefix = ""
        for i in range(min(len(options[0]), len(options[1]))):
            if options[0][i] == options[1][i]:
                common_prefix += options[0][i]
            else:
                break
        
        # Extract beta1 and beta2
        beta1 = options[0][len(common_prefix):] or "$"
        beta2 = options[1][len(common_prefix):] or "$"
        
        # Print the refactored productions
        print(f"\n{non_terminal}->{common_prefix}{non_terminal}'")
        print(f"{non_terminal}'->{beta1}/{beta2}")

# Example usage
remove_left_factoring()
