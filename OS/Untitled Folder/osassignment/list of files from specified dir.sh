#!/bin/sh
echo "Enter directory"
read str
# Define your function here
Hello () {
   cd
   cd $str
   ls -l
}

Hello
