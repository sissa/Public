#!/bin/bash

# 1. Generate a file with 2 columns of 100 random numbers
for i in {1..100}; do
    echo "$RANDOM $RANDOM"
done > random_numbers.txt

# 2. Sort them by the second column
sort -k2 -n random_numbers.txt > sorted_numbers.txt

# 3. Remove every 3rd line using sed
sed -i '0~3d' sorted_numbers.txt

