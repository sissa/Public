#!/bin/bash

# Get the name of the currently executing script
script_name=$(basename $0)

# Loop through all .sh files in the current directory
for file in *.sh; do
    # Exclude the current script from the operation
    if [ "$file" != "$script_name" ]; then
        # Check if the file is executable
        if [ -x "$file" ]; then
            # If it's executable, remove execute permissions
            chmod -x "$file"
        else
            # If it's not executable, add execute permissions
            chmod +x "$file"
        fi
    fi
done

