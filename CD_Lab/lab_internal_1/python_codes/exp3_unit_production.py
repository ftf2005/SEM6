def main():
    prod = input("Enter the production: ")
    
    # Check for left recursion
    if prod[0] == prod[3]:
        print("\nEntered production is left recursive")
        
        # Extract alpha and beta
        alpha, beta = prod[4:].split('/', 1)
        
        # Output the modified production
        print(f"{prod[0]}->{beta}{prod[0]}'")
        print(f"{prod[0]}'->{alpha}{prod[0]}'/$")
    else:
        print("\nEntered production is not left recursive")

if __name__ == "__main__":
    main()
