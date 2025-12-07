# PointlessCode

PointlessCode is a project where I'll be trying to solve some random problem with code. I don't have a clear idea of how it will be yet, so I can't give a detailed description of it, but in order to provide a better picture of what I have in mind, I will explain the first problem.

## First Problem:

The first problem is from a math olympiad. The problem is: 
***(Belarus/TST- 2019)*** 1019 stones are placed into two non-empty boxes. Each second Alex chooses a box with an even amount of stones and shifts half of these stones into another box. Prove that for each k, 1 ≤ k ≤ 1018, at some moment there will be a box with exactly k stones.

What I'm going to do is prove using a brute force and, maybe, a solution that implements some algorithm/data structure instead of giving an elegant solution as it is expected in a mathematical olympiad.

## Build:
I'll use standard C, and the major part, if not everything, will be made for Ubuntu. So, if you use some Linux distro, you should be fine with only an up-to-date GCC compiler. I think the simpler solutions will be able to get compiled for Windows as well, but I can’t guarantee compatibility for all problems.

## Repo-tree
```
.
├── EP001
│   ├── asm
│   ├── generate_tree.sh
│   ├── header
│   ├── obj
│   ├── src
│   ├── static
│   ├── test
│   └── tree_output.md
├── README.md
├── generate_tree.sh
└── tree_output.md
```