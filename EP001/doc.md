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

## Benchmark 1: ./benchWithShift.out
  Time (mean ± σ):     578.5 ms ±   2.6 ms    [User: 575.7 ms, System: 1.2 ms]
  Range (min … max):   575.5 ms … 582.3 ms    10 runs
 
## Benchmark 2: ./benchWithDiv.out
  Time (mean ± σ):     590.7 ms ±   1.6 ms    [User: 585.7 ms, System: 3.3 ms]
  Range (min … max):   587.6 ms … 593.4 ms    10 runs
 
## Benchmark 3: ./sol2.out
  Time (mean ± σ):       2.9 ms ±   0.3 ms    [User: 1.1 ms, System: 0.4 ms]
  Range (min … max):     2.4 ms …   6.2 ms    624 runs
 
## Benchmark 4: ./twoOptm.out
  Time (mean ± σ):     283.7 ms ±  25.1 ms    [User: 280.3 ms, System: 1.9 ms]
  Range (min … max):   251.0 ms … 315.9 ms    10 runs

# How it works
#### int solution()
This solution iterates through {1, 2, ..., 509} and calls _int instancesolution(int  a, int  b, void (*transf)(int , int ))_ which does the procedure described in the statement of the problem in each iteration. This solution just throws away all the numbers that _*transf_ produces when this number isn't equal to the values of a and b in the current iteration in solution().

#### void solution2()


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
