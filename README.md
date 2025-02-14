# Simplex-Algorithm
Simplex Algorithm implementation in c++

This repository contains an implementation of the **Simplex Algorithm** in C++ for solving **Linear Programming (LP) problems**. The program finds the optimal solution for a given LP problem in standard form.

## Features

- Handles maximization problems with **≤ (less than or equal to)** constraints.
- Supports **slack variables** for converting inequalities into equalities.
- Dynamically constructs and updates the **Simplex tableau**.
- Detects **unbounded solutions**.
- Provides a clear step-by-step transformation of the tableau.

## How It Works

1. **Input the number of variables and constraints**.
2. **Enter the constraint coefficients** (including the right-hand side values).
3. **Enter the objective function coefficients**.
4. The program applies the **Simplex Method** iteratively until it reaches an optimal solution.
5. Outputs the optimal values of variables and the maximum objective function value.

## Compilation & Execution

### Requirements

- A C++ compiler (e.g., g++, Clang, MSVC)

### Compile the Code

```sh
 g++ simplex.cpp -o simplex
```

### Run the Program

```sh
 ./simplex
```

## Example Usage

### Input

```
Enter the number of variables: 2
Enter the number of constraints: 2
Enter the coefficients of the constraints (including RHS):
1 1 4
2 1 5
Enter the coefficients of the objective function (maximize):
3 2
```

### Output

```
Initial simplex table:
    (Displays initial tableau)

Table after pivoting (Row: X, Column: Y):
    (Updated tableau after each step)

Optimal solution found:
x1 = 2, x2 = 2
Maximum value: 10
```

## Notes

- This implementation assumes all constraints are in the **≤** form.
- Ensure that input values are correctly formatted.
- Floating-point precision errors might slightly affect the results.

## License

This project is open-source under the **MIT License**.

## Contributions

Feel free to submit issues, suggest improvements, or fork the repository to enhance the algorithm!

## Group 7 members
U22CS1062 https://github.com/Maryam876 
U22CS1064 https://github.com/ahmad-ig
https://github.com/thebuhariii
https://github.com/Big-Major/U22CS1069
https://github.com/U22cs1068/
U22CS1070

