#!/bin/sh
file = $1
objfile = `echo $f | sed 's/\.[^\.]*$//'`

g++ -g -o $objfile $file
./$objfile