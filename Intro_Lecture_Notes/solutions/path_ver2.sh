#! /bin/bash

IFS=: # Set internal field separator to colon for the purpose of this loop
n_ex_files=0

#actually, there is a special in-built way to do it
for dir in $PATH; do
   echo ${dir}
   for file in ${dir}/*;do
      if [ -e "$file" ];then
        n_ex_files=$((n_ex_files+1))
      fi
   done
done

echo "The number of executable files in the \$PATH is: $n_ex_files"
