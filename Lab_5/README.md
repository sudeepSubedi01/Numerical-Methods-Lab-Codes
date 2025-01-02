# Gauss-Jordan Method <br>
<b>Generating System of Linear Equation of any number of unknowns <b><br>
1. Open Excel
2. Select a cell and type formula: `=RANDBETWEEN(1,5)`.
3. Copy the formula to other cells creating a `n x n` matrix. This is matrix `A`.
4. For matrix `X`, create a matrix `n x 1`.
5. For matrix `B`, <br>
     1. Select `n x 1` cells between matrices `A` and `X`.
     2. Type the formula `=MMULT(matA,matX)` and hit `Ctrl + Shift + Enter`.
6. Use the matrices `A`  and `B` to input in the program.
7. The output is the matrix `X`. 