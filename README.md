
# Ant-Colony-Optimization-solving-Google-HashCode-2020

Ant Colony Optimization algorithm solving Google HashCode 2020 online elimination problem  

## Problem Statement

The problem statement can be found [here](
https://storage.googleapis.com/coding-competitions.appspot.com/HC/2020/hashcode_2020_online_qualification_round.pdf)

## Solution

The solution is based on Ant Colony Optimization algorithm.

## How to run

1. Clone the repository

2. Compile the program using cmake, to do so please execute the following commands in the main directory of the project:

```
cmake -B build
cd build
make
```
3. Run the program using the following command:

```
./main 
```
Program accepts data through the standard input and outputs the solution to the standard output. Alternatively, you can specify the input and output files using the following command:

```
./main <input_file >output_file
```
For example, to run the program on the input file `a_example.txt` and output the solution to the file `a_example.out` you can use the following command:

```
./main <../test/a_example.txt >../output/a_example.out
```