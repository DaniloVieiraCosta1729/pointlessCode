ZERO=$(./solutions/zeroOptm.out)
TWO=$(./solutions/twoOptm.out)
DIV=$(./solutions/benchWithDiv.out)
SHIFT=$(./solutions/benchWithShift.out)
SOL2=$(./solutions/sol2.out)

cat <<EOF > benchmarkResults.md
# Results
## Bad Solution with gcc optimizations off
**$ZERO seconds**
## Bad Solution with gcc optimizations -O2
**$TWO seconds**
## Bad Solution using the operation boxA / 2
**$DIV seconds**
## Bad Solution using the operation boxA >> 1
**$SHIFT seconds**
## Solution 2 without flags
**$SOL2 seconds**

EOF