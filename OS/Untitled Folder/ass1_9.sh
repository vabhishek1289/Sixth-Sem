#!/bin/bash
echo "Enter your percentage :"
read per 

case $per in 
100) echo "You passed in 1st division" ;;
[8-9][0-9]) echo "You passed in 1st division" ;;
[6-7][0-9]) echo "You passed in 2nd division" ;;
[3][6-9]|[4-5][0-9]) echo "You passed in 3rd division" ;;
[1-2][0-9]|[3][0-5]) echo "You failed!!!" ;;
*) echo "Invalid !!....Please enter another number" 
esac
