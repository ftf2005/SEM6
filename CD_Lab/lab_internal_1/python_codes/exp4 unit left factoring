def remove_left_factoring():
    prod = input("Enter the production (e.g., A->aB/aC): ").strip()
    
    # Check if the input is in the correct format
    if '->' not in prod or '/' not in prod:
        print("The production is not in the correct format.")
        return
    
    # Split the production into left-hand side (LHS) and right-hand side (RHS)
    non_terminal, rhs = prod.split("->")
    options = rhs.split("/")
    
    # Find the common prefix
    common_prefix = ""
    for i in range(min(len(options[0]), len(options[1]))):
        if options[0][i] == options[1][i]:
            common_prefix += options[0][i]
        else:
            break
    
    # Extract the unique parts (beta1 and beta2)
    beta1 = options[0][len(common_prefix):] or "$"
    beta2 = options[1][len(common_prefix):] or "$"
    
    # Print the refactored productions
    print(f"\n{non_terminal}->{common_prefix}{non_terminal}'")
    print(f"{non_terminal}'->{beta1}/{beta2}")

# Example usage
remove_left_factoring()
