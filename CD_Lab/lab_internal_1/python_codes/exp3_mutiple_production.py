def main():
    n = int(input("Enter the number of productions: "))
    productions = [input(f"Enter production {i+1}: ").strip() for i in range(n)]
    
    for idx, prod in enumerate(productions):
        if prod[0] == prod[3]:  # Check for left recursion
            print(f"\nProduction {idx+1} is left recursive:")
            
            # Split alpha and beta
            alpha, beta = prod[4:].split('/', 1)
            
            # Print modified production
            print(f"{prod[0]}->{beta}{prod[0]}'")
            print(f"{prod[0]}'->{alpha}{prod[0]}'/$")
        else:
            print(f"\nProduction {idx+1} is not left recursive.")

if __name__ == "__main__":
    main()
