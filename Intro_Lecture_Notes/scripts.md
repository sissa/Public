references:

[bash manual](https://www.gnu.org/software/bash/manual/bash.html)

[Pro Bash Programming](https://link.springer.com/book/10.1007/978-1-4842-0121-3)

[cheatsheet](https://devhints.io/bash)

## Bash scripting

### Hello World!

```
#! /bin/bash
echo "Hello World!"
```

The first line here tells the system which shell to use.

Let's do the same with a variable:

```
#! /bin/bash
VARIABLE="Hello World!"
echo "$VARIABLE"
```
Note the lack of spaces around "="! It's important! If you write VARIABLE = "Hello World!", bash will view this as a command named "VARIABLE" with arguments.

### Environmental variables

run `env` in your terminal.

What you see are the system defined variables that are used by the system and different programs. You have access to them inside the script too.

```
#! /bin/bash
echo "$PATH"
```

### Interactive

run `read`

Whatever you answered is stored in `$REPLY` unless you specify another variable:

```
#! /bin/bash

echo "What is your name?"
read name
echo "Nice to meet you, ${name}!"
```

You can let the user select from multiple statements:

```
select var_name in opt1 opt2 opt3
do
  # use either ${var_name} or ${REPLY}
  # break when you want to exit
  sleep 1
done

PS3="prompt for select"
```



### Control Flow (Conditional Statements)

```
if [[ cond1 ]]
then
    ...
elif [[ cond2 ]]
then
    ...
else
    ...
fi
```

You can test files:

```
[ -e /path/to/file ] : file exists
-x : user has execute permissions
-d : is a directory
```

Integer comparisons:

```
[ $a -eq $b ]  equality
-ne : inequality
-lt : less than
-le : less or equal
-gt : greater than
-ge : greater or equal
```
AND and OR:

```
[[ condition1 && condition2 ]]
[[ condition1 || condition2 ]]

```

#### Case:

```
case ${var} in
  val1) … ;;
  val2|val3) … ;;
  *) … ;;
esac
```




### Passing arguments:

```
./script.sh arg1 arg2 arg3 
```

`${0}` is the name of the script

first argument is assigned to `${1}`, second argument to `${2}`, and so on


Useful variables:

```
${*} a string with all the arguments
${@} one argument at a time
${#} the number of arguments
```

### Example:

```
! /bin/bash
if [[ $# -eq 0 ]] ; then
    echo 'USAGE: ./fileinfo.sh FILENAME'
    echo 'you have not provided a filename'
    exit 0
fi
FILE="$1"
if [ -e "$FILE" ]
  then
     echo "$FILE exist"
  else 
     echo "$FILE does not exist"
fi
if [ -x "$FILE" ]
  then
    echo "You have permission to execute $FILE"
  else
    echo "You do Not have permissions to execute $FILE"
fi
```

### When echo is not enough

```
printf "format string" "${var1}" "${var2}"
%s : generic string
%f : floating point number
%e : exponential notation
%d : integer
```
example: `printf "There are %s outside\n" "cats"`

### Functions

```
funct arg1 arg2

funct()
{
 # somthing with $1, $2
}

```
variables are "global" by default, that is, they continue "living" outside the function

```
funct(){
  var="new value"
}

funct
printf "%s\n" "${var}"
```

If you want a variable to "die" after the function is done, add the word `local`

```
funct() {
  local var="local value"
}
var="value"
funct
printf "%s\n" "${var}"
```

### Loops

```
for var in LIST
do
  # use ${var}
done
```

for example:

```
#! /bin/bash
for var in $(seq 10)
do
  echo ${var}
done
```

other options for loop condition are: `for var in {0..9}`, `for ((var=0; var<10; ++var))`


#### while loop

```
n=1
while [ $n -lt 10 ]
do
  …
  ((++n))
done

```


### Arrays

```
#! /bin/bash
var=('a' 'b' '8' 'c')
echo "${var[*]}"
echo "${var[@]}"
echo "Number of elements ${#var[@]}"
printf "%s\n" "${var[@]}"
for i in "${var[@]}"
do
  echo ${i}
done
```

### Text processing

#### `sort`

```
sort inputfile.txt > filename.txt
sort -o filename.txt inputfile.txt
```

Options:

 - -r sort in reverse order
 - -n sort numerically
 - -k sort by a certain column
 - -u (uniq) to sort and remove duplicates

#### sed

`sed` is stream editor for filtering and transforming text

A nice tutorial can be found [here](https://www.grymoire.com/Unix/Sed.html)

Quick examples:

Substituting a word:

```
echo word1 > file1.txt
sed 's/word1/word2/' file1.txt > file2.txt
cat .txt
echo day | sed 's/day/night/'
```

Deleting a line number N:

```
sed 'Nd' FILENAME
```

### awk (for people who are comfortable with everything else)

`awk` is a very powerful tool for text processing

another tutorial is [here](https://www.grymoire.com/Unix/Awk.html)


awk work as follows:
```
awk 'CONDITION { INSTRUCTION } ' MY_FILE
```
MY_FILE can be a file or a pipe

#### script
You can write your command in script and interpret it with command 
```
awk -f script.awk  data.txt
``` 

#### VARIABLE ENVIRONMENT

A document is composed by the line and the line by the field seprated by a space
- $0 : the complet line
- NR : the number of actual line in global
- FNR : if more than one file give the number of actual line of the actual file 
- NF : number of field in the line
- $1-$NF : value of each field of the line
- FS : Field Separator. " " by default. 
- OFS : Output Field Seprator. " " by default.
- RS : Record separator. \n by default
- FILENAME : name of file (No disponible at BEGIN)
- ARGC : number of argument 
- ARGV : verctor contain argument value
- CONVFMT : Conversion format of number in string
- ENNVIRON : contains the value environment variable 

#### CONDITION

- No condition = .true. : Do instruction for each line
- BEGIN : Do before open file
- END : Do after close file
- logical operator : `<`,`>`,`<=`,`>=`,`==`,`!=`,`~`
- /pattern/ : Do if find the pattern in the line
- Pattern Operator:
  - `*` : repetition 0 time or more
  - `+` : repetition 1 time or more
  - `?` : repetition 0 or 1 time
  - `[]` : regroup the element
  - `^` : begin of field
  - `$` : end of field
  - `³` : possible choice
  - `.` : any character
  - `\` : not execute the operator. `/\\/` search pattern \ in the line and `/\./` search a ".". (Like in bash)

- Some example:
  - `^B` : a field begin by chracter B
  - `G$` : a field ending by character G
  - `^.$` : all field with only one character
  - `[AEIOU]` : field with only one charcater A, E, I, O or U. Other character may be different
  - `^[ABC]` : field begin by A, B or C
  - `^[^a-z]$` : one charcater field which is not minuscule letter 
  - `^[0-9]+$` : field with only charcater numbers
  - `^(\+³-)?[0-9]+\.?[0-9]*$` : ...

#### INSTRUCTION

The instruction field {} can have many instruction separated by `;`

- print ... or printf() like in C : print something
- getline : get the record
- next : pass to the next record
- exit : go to END statement
- LOOP strcture:
  - `for (i=0;i<NF;i++) { print $i }` : loop from 0 to NF, print field $i
  - while (condition) { instruction } : while condition is true do instruction
  - do 
- if (condition) { instruction } : if condition is true do instruction
- operator : =, ++, +=

#### Interaction With the BASH script
You can put some awk command line in you bash script. To do that you have to include the command line in $( awk '' ). The output of the awk command must to read by `read` command
```
#!/bin/bash
ARG1=10
ARG2="Hello"
read var <<< $( awk ' $1==10 { print $2 } ' <<< "$ARG1 $ARG2" ) 
```
After this line `var` has the value "Hello"...

### Exercise 1:

How many arguments are passed and which ones? Write a script to check your guesses.
```
$ ./script.sh one two three "four five"
$ ./script.sh *
$ ./script.sh {a,b,c}.txt
$ ./script.sh $(ls)
$ ./script.sh 3+4 5 + 6 $(( 9 + 11 ))
$ ./script.sh PATH ${PATH}
```

### Exercise 2:

Write a calculator that takes 3 arguments: number1, operation (-,+,x,/), number2 (for example ./my_calc.sh  2 + 2). Write a separate function for each operation.

### Exercise 3:

Write a game that tries to guess a number you thought of between 1 and 20 (each time you tell it if the guess is lower or higher). Hint: use $RANDOM

### Exercise 4:

Write a script that finds all the `.sh` files in the current folder and changes their permissions to "executable" if they are not and the other way around.

### Exercise 5:

Count a number of executable files in your $PATH

### Exercise 6:

Generate a file with 2 columns of 100 random numbers. Sort them by the second column. Remove every 3rd line.


### Hard Exercise: task manager

Write your own simple "task manager" for your plans. You should be able to add, view (current and completed) and remove tasks (like "wash the dishes", "learn chinese", "do homework"). If you fail after an hour of trying to write something, the file with hints will be uploaded.  
