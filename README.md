# Push_swap (Stack Sorting Optimizer)

An algorithmic sorting optimization project in C. Given an unsorted stack of integers and a secondary empty stack, it outputs the shortest sequence of stack instructions to sort the data in ascending order.

![Language](https://img.shields.io/badge/Language-C99-blue?logo=c&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithm-Chunking%20%7C%20Radix%20%7C%20Greedy-orange)
![42 Score](https://img.shields.io/badge/42_Score-125%2F100-success)
![License](https://img.shields.io/badge/License-MIT-green)

---

## Overview

`push_swap` calculates and prints the minimum set of operational instructions needed to sort a list of unique integers. You are given two stacks: `a` (initially filled with random integers) and `b` (initially empty).

---

## Allowed Operations

| Instruction | Action |
| :--- | :--- |
| `sa` / `sb` | **Swap**: Swap the first two elements at the top of stack `a` or `b`. |
| `ss` | Execute `sa` and `sb` simultaneously. |
| `pa` / `pb` | **Push**: Take top element from `b` and put it on `a` (or vice-versa). |
| `ra` / `rb` | **Rotate**: Shift all elements of stack `a` or `b` up by 1. Top becomes bottom. |
| `rr` | Execute `ra` and `rb` simultaneously. |
| `rra` / `rrb` | **Reverse Rotate**: Shift all elements of stack `a` or `b` down by 1. Bottom becomes top. |
| `rrr` | Execute `rra` and `rrb` simultaneously. |

---

## Algorithmic Architecture

```
Raw Arguments ---> Input Parsing & Validation ---> Index Normalization ---> Sorting Strategy (Hardcoded / Chunk Cost) ---> Instruction Stream Output
```

### 1. Data Normalization & Indexing
Original integers are converted into zero-indexed rank positions ($0 \dots N-1$). This simplifies relative comparison logic and allows bitwise or chunk-based sorting independent of negative values or massive number ranges.

### 2. Adaptive Sorting Strategies
- **Small Sets ($N \le 3$)**: Solved in at most 2-3 instructions using conditional swap/rotate sequences.
- **Medium Sets ($N \le 5$)**: Pushes the smallest values to stack `b`, sorts the remaining 3 elements in stack `a`, then pushes elements back.
- **Large Sets ($N = 100 \text{ or } 500$)**:
  - Uses chunking / least-cost distance calculation to select target elements in stack `a`.
  - Calculates cost ($C_{\text{rotate\_a}} + C_{\text{rotate\_b}}$) and applies synchronized rotations (`rr`, `rrr`) to move target elements into position concurrently.

---

## Performance Targets

The algorithm strictly respects the 42 benchmark thresholds:

| Dataset Size | Target Instruction Limit | Achieved Operations | Score Rating |
| :--- | :--- | :--- | :--- |
| **3 numbers** | $\le 3$ ops | **2 - 3 ops** | 100% |
| **5 numbers** | $\le 12$ ops | **8 - 11 ops** | 100% |
| **100 numbers** | $< 700$ ops | **~580 - 620 ops** | 5 / 5 |
| **500 numbers** | $< 5500$ ops | **~5100 ops** | 5 / 5 |

---

## File Structure

```
.
├── push_swap.h          # Stack structures, headers, function prototypes
├── Makefile             # Compiles push_swap and checker binaries
├── main.c               # Entry point and algorithm selector
├── parsing.c            # Validates integers, duplicates, overflow check
├── bring_num_up.c       # Rotation cost calculator and stack rotator
├── func_swap.c          # Implementations of sa, sb, ss
├── func_push.c          # Implementations of pa, pb
├── func_rotate.c        # Implementations of ra, rb, rr
├── func_reverse.c       # Implementations of rra, rrb, rrr
├── libft/               # Custom C standard library
└── my_checker/          # Bonus: Instruction sequence verifier binary
```

---

## Getting Started

### Prerequisites
- C compiler (`gcc` or `clang`)
- `make`

### Compilation

```bash
git clone https://github.com/ma1iik/Push_swap.git
cd Push_swap
make
```

To compile the bonus `checker` program:
```bash
make bonus
```

---

## Usage

Run `push_swap` with space-separated integers:

```bash
./push_swap 2 1 3 6 5 8
```

Output:
```text
sa
pb
pb
ra
pa
pa
```

### Verifying Output with `checker`

Pipe instructions directly into `checker` to verify if the stack is properly sorted:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Output:
```text
OK
```

If the instructions fail to sort or leave elements in stack `b`, `checker` outputs `KO`.

---

## Input Error Validation

The parser checks for:
- Non-numeric inputs (`./push_swap 3 two 1` $\rightarrow$ `Error`)
- Duplicate integers (`./push_swap 5 2 5` $\rightarrow$ `Error`)
- Integer overflow / underflow beyond `INT_MAX` / `INT_MIN` ($\rightarrow$ `Error`)

---

## License

Distributed under the MIT License. See `LICENSE` for details.
