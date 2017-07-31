#!/bin/bash
echo "Enter any string"
read str
i=${#str}
if [ $i -lt 10 ]
then 
echo "String length is less than 10"
else
echo "Accepted"
fi
