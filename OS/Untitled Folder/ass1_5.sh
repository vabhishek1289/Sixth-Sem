#(v) Write a shell program to find the frequency of occurrence of a specified word, in a specified file (file and word specified as command line argument ex. $f.sh a.txt main).

#!/bin/bash
echo "Enter filename"
read filename
echo "Enter word to be search"
read word
count=`grep -o $word $filename | wc -l`
echo "Occurance of the $word is $count"

