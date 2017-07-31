#!/bin/bash

echo "Enter number of elements"
read n
echo "Enter elements of first array"
i=0
while [ $i -lt $n ]
do
read arr[$i]
i=`expr $i + 1`
done
echo "Elements of first array are:-" 
echo ${arr[*]}

i=0
while [ $i -lt $n ]
do
a[$i]=${arr[$i]}
i=`expr $i + 1`
done
echo "Elements of second array after copying from first are:-"
echo ${a[*]}

