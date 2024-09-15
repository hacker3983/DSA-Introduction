#!/bin/bash
echo -e "\033[32mAlgorithms Implemented\033[0m:"
algorithms=("Bubble" "Selection" "Insertion" "Quick" "Counting" "Radix")
i=0
for algorithm in ${algorithms[@]}
do
	echo -e "$((i+1)).\033[32m$algorithm Sort\033[0m"
	i=$((i+1));
done
printf "You have implemented \033[32m"; ls -al | grep -E "*\.(c)$" | wc -l | tr -d '\n'; echo -e "\033[0m sorting algorithms"
