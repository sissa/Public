#! /bin/bash

list_of_paths=$(echo "$PATH" | sed -e 's/:/\n/g')

n_ex_files=0

for path in ${list_of_paths}; do
   echo ${path}
   for file in ${path}/*;do
      if [ -e "$file" ];then
        n_ex_files=$((n_ex_files+1))
      fi
   done
done

echo "The number of executable files in the \$PATH is: $n_ex_files"
