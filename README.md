# Push_swap

## Description

**Push_swap** is a project focused on sorting a stack of integers using a limited set of operations, with the goal of achieving the fewest moves possible. This project was part of the École 42 curriculum, aimed at developing a deep understanding of sorting algorithms and data manipulation in C. The project includes two stacks, `a` and `b`, and a set of allowed operations to sort the integers in ascending order in stack `a`.

---

## Features

### Mandatory Part

The **Push_swap** program must sort a stack of integers using the smallest possible number of moves. It takes in a list of integers as input, representing stack `a`, with stack `b` starting empty. The goal is to sort stack `a` in ascending order using only specific operations.

- **Allowed Operations**:
  - `sa` - Swap the first two elements of stack `a`.
  - `sb` - Swap the first two elements of stack `b`.
  - `ss` - Perform `sa` and `sb` at the same time.
  - `pa` - Push the top element of stack `b` to stack `a`.
  - `pb` - Push the top element of stack `a` to stack `b`.
  - `ra` - Rotate stack `a` upwards (first element becomes last).
  - `rb` - Rotate stack `b` upwards.
  - `rr` - Rotate both stacks `a` and `b` upwards at the same time.
  - `rra` - Reverse rotate stack `a` (last element becomes first).
  - `rrb` - Reverse rotate stack `b`.
  - `rrr` - Reverse rotate both stacks at the same time.

---

## Algorithm Explanation

### Overall Strategy

1. **Small Stack Sorting (3 or fewer elements)**:
   - For small inputs (2 or 3 elements), the program uses a basic sorting strategy with `sa`, `ra`, and `rra` to quickly arrange the elements in ascending order with minimal moves.

2. **Larger Stack Sorting**:
   - For larger inputs, the program sorts stack `a` in chunks by pushing elements to stack `b` and selectively rotating the stacks. This approach allows for more efficient sorting with fewer moves.

3. **Big Algorithm (`big_alg` function)**:
   - The core function, `big_alg`, continuously sorts the stacks until stack `a` is fully ordered. It identifies the largest elements and moves them to stack `b` for better management of the sorted order.
   - Within this function, elements are pushed to stack `b` using `func_pb`, and the algorithm selectively rotates elements back to `a` to maintain the ascending order.

4. **Finding Optimal Rotations (`rotate_till` function)**:
   - This function calculates the optimal number of rotations to bring the largest element to the top of stack `a`, using either `func_ra` (rotate up) or `func_rra` (reverse rotate down) based on the element's position. This minimizes the number of moves.

5. **Shortest Path Calculation (`shortest_option` function)**:
   - The `shortest_option` function calculates the minimum number of moves required to sort each element by evaluating all possible paths to position elements in the correct order.
   - It uses helper functions to find the closest higher number in stack `a` and returns the element from `b` that can be moved with the fewest operations, optimizing the process.

---

## Compilation and Usage

Compile the program using the provided Makefile:

    make

Run the program with the specified arguments to sort the integers in `a`:

    ./push_swap 3 2 5 8 1

---

## Project Structure

- **src/**: Contains the source files (`.c` files).
- **include/**: Contains the header files (`*.h`).
- **Makefile**: Used for compiling the main program and managing dependencies.

---

## How to Use

1. **Basic Command**:
   - Run the program with a list of integers to get the sorted order using the minimum number of moves:
     
         ./push_swap 3 2 5 8 1

2. **Checker Program (Bonus)**:
   - Use the checker program to verify the correctness of the `push_swap` output by comparing sorted results.

---

## Author

Project developed by [Malik](https://github.com/ma1iik) as part of the École 42 curriculum.
