#!/bin/bash

#Assigning variables var1 and var2 to the number of files & directories respectively
#Using find at $1 and filtering by type to get the type we're counting with wc -l
var1=$(find "$1" -name "*" -type d | wc -l)
var2=$(find "$1" -name "*" -type f | wc -l)
#Printing out the resulting counts of files and directories.
echo "There were $var1 directories."
echo "There were $var2 regular files."