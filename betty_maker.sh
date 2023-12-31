#!/bin/bash

# important !

# this script does not work in fish shell
# recommended zsh shell for run this script

# to run script:
# put it in the directory you want to fix it files (will fix any .c and .h files)
# make it executable by this command => "chmod +700 <name_of_this_file>"
# execute it => "./<name_of_this_file>"

######################################################
### this script can fix some betty linter errors like :
# ERROR trailing spaces
# WARNING please, no spaces at the start of a line
# WARNING suspect code indent for conditional statements
# ERROR space required before the open parenthesis '('
# WARNING space prohibited before semicolon
# ERROR space prohibited before that ',' (ctx:WxW)
######################################################

for filename in ./*.c ./*.h; do
	vim -ec "normal gg=G" \
		+"%s/\<return\> *(/return (/e" \
		+"%s/\<while\> *(/while (/e" \
		+"%s/\<if\> *(/if (/e" \
		+"%s/\<else if\> *(/else if (/e" \
		+"%s/\<for\> *(/for (/e" \
		+"%s/ *; */; /eg" \
		+"%s/ *, */, /eg" \
		+":%s/\s\+$//e" \
		+"wq" $filename
done

for filename in ./*.c ./*.h; do
	echo $filename fixed
done