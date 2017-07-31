#!/bin/bash
echo "Enter file name"
read filename
echo "Last three lines of the file is:-"
tail -3 $filename
