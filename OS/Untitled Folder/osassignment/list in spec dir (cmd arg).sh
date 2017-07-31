#!/bin/sh
echo "Enter directory"
read str
Hello () {
   cd
   cd $1
   ls -l
}

Hello $1
