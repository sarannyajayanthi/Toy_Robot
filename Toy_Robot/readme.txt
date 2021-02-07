ToyRobot:
=========
g++ compiler is required to compile the c++ code.

To install g++ on ubuntu
sudo apt install g++ 

The input for ToyRobot is passed via a input file. The input.txt is passed as a command line argument.
runToyRobot.sh is a script to run the application and the output is seen in the console. 
input.txt can be updated for various inputs.

The testing of the ToyRobot application is done via the script test.sh.
The input files should be added in test_data/input. The expected output files are to be added in the test_data/output.
The test results will be loaded in test_results folder. 
The script compares the expected output and test_results folder and updates the test results in console.

Any errors or cause of failure can be seen in console.log
