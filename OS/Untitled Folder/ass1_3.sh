#!/bin/bash/
FileSize(){
        echo "Enter file name"
        read fl
        f=`cat $fl`
        i=${#f}
        echo "Size of file is $i"
     }
     
FileSize
