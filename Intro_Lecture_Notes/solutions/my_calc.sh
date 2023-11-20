#!/bin/bash

# Function for addition
addition() {
    echo $(($1 + $2))
}

# Function for subtraction
subtraction() {
    echo $(($1 - $2))
}

# Function for multiplication
multiplication() {
    echo $(($1 * $2))
}

# Function for division
division() {
    # Check if the second number is zero to avoid division by zero error
    if [ $2 -eq 0 ]; then
        echo "Error: Division by zero!"
        exit 1
    fi
    echo $(($1 / $2))
}

# Check if the number of arguments provided is 3
if [ $# -ne 3 ]; then
    echo "Usage: $0 number1 operation(-,+,x,/) number2"
    exit 1
fi

# Use a case statement to determine which operation to perform
case $2 in
    +)
        addition $1 $3
        ;;
    -)
        subtraction $1 $3
        ;;
    x)
        multiplication $1 $3
        ;;
    /)
        division $1 $3
        ;;
    *)
        # If the provided operation is not one of the expected ones
        echo "Invalid operation. Allowed operations are -, +, x, /"
        exit 1
        ;;
esac

