#!/bin/bash
echo "Enter any number"
read n
f=1
while [ $n -ge 1 ]
do
f=`expr $f \* $n`
n=`expr $n - 1`
done

echo $f
