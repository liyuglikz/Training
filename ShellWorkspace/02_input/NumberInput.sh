#/bin/bash

# String input

# define a varible
var=0

# input
read var

# while loop until var is equal to "1"
while test ${var} != "stop"; do
	# output the var
	echo ${var}
	read var
done

printf "Stoped\n"
