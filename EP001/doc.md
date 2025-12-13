# EP001 
The main goal is to prove this statement through computing all the steps instead of using a mathematical approach like applying the 'invariants' concept.

Besides the main goal, I also want to practice benchmarking, bash scripting, pipes, and testing, and in order to do so, I'm going to create a few versions of the solutions, starting with a naive brute-force one with compiler optimizations off and then making faster ones later.

# Running the code
In the EP001 folder:
```
gcc -c ../src/tools.c -o ../obj/tools.o
```
```
gcc testSolution.c ../obj/tools.o -o solution.out
```
```
./solution.out
```
I know a makefile would be a lot better, but I'm still not used to making these makefiles yet, but I'll definitely add one later.

# Results
The problem was solved, and it returns a number of 132260596 iterations to complete the task. This number is how many times a person would have to divide the stones in the even-numbered box in half and put half in the odd-numbered box until confirming that, for all numbers between 1 and 1018, all of them appear as a quantity of stones in one of the boxes at some point.

# Directory tree of EP001

```
.
├── asm
│   └── random.asm
├── benchmark
│   ├── solutions
│   └── understandTools
├── doc.md
├── generate_tree.sh
├── header
│   └── tools.h
├── obj
│   ├── random.o
│   ├── tools.o
│   └── udst.o
├── src
│   ├── Stones-belarusTST2019.c
│   └── tools.c
├── static
│   └── test.png
├── test
│   ├── buildTest
│   ├── macro.out
│   ├── macros.c
│   ├── solution.out
│   ├── testSolution.c
│   └── understanding.c
└── tree_output.md

```
