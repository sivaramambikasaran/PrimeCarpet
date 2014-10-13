#!/bin/bash
g++ -Ofast primeCarpet.cpp
echo "Enter the number of grid points along X axis"
read i
echo "Enter the number of grid points along Y axis"
read j
./a.out $i $j
pdflatex primeCarpet.tex
rm a.out
rm *.aux
rm *.log