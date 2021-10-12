#!/bin/bash

var1=$(find $1 -name "*" -type d | wc -l)
var2=$(find $1 -name "*" -type f | wc -l)
echo "There were $var1 directories."
echo "There were $var2 regular files."