#!/bin/bash
read file



[ -r $file ] && b="yes" || b="no"
echo readable : $b
[ -w $file ] && b="yes" || b="no"
echo writable : $b
[ -x $file ] && b="yes" || b="no"
echo executable : $b
