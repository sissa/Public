#!/bin/bash

# Initialize the lower and upper bounds
lower_bound=1
upper_bound=20
attempts=0

echo "Think of a number between 1 and 20 and I'll try to guess it!"
echo "Once you've chosen a number, press enter to continue."
read

while true; do
    # Let the computer guess a number within the range
    let "guess = $RANDOM % ($upper_bound + 1 - $lower_bound) + $lower_bound"
    ((attempts++))
    echo "Is it $guess?"

    # Read the user's hint
    echo "Enter 'higher', 'lower', or 'yes':"
    read hint

    case $hint in
        "lower")
            upper_bound=$((guess-1))
            ;;
        "higher")
            lower_bound=$((guess+1))
            ;;
        "yes")
            echo "Yay! I guessed your number in $attempts attempts!"
            break
            ;;
        *)
            echo "Invalid input. Please enter 'higher', 'lower', or 'yes'."
            ;;
    esac
done

