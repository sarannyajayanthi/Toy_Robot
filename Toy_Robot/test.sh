#!/bin/bash

g++ toyRobot.cpp -o toyRobot

rm -rf test_results
mkdir test_results
rm -rf console.log
touch console.log 

for file in `ls test_data/input`
do       	
   echo "Testing input file $file">> console.log  
   outputFile="output_$file"
   ./toyRobot test_data/input/$file > test_results/$outputFile
   diff test_data/expected/$outputFile test_results/$outputFile >> console.log 
   if [ $? -eq 1 ]
   then
      echo "${file} : FAIL" 
   else
      echo "${file} : PASS"
   fi
done
