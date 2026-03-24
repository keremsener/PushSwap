*This project has been created as part of the 42 curriculum by ksener (algorithms and stack operations) and adede (parsing, disorder computation, Makefile, and header configuration).*

---

## Description

**Push Swap** is a sorting algorithm challenge that requires arranging integers from smallest to largest using two stacks (Stack A and Stack B) with a limited set of operations. The goal is to find the most efficient sorting solution with the minimum number of moves possible.

The project focuses on understanding algorithmic complexity in a practical way. You are given two stacks and eleven operations to manipulate them. The challenge is not just to sort the numbers, but to choose and implement the right algorithms that scale well as the input grows larger.

This project demonstrates the crucial difference between algorithmic approaches: sorting a fully random list requires a completely different strategy than sorting an almost-sorted list. Through this work, you'll implement and compare four distinct sorting strategies—Simple (O(n²)), Medium (O(n√n)), Complex (O(n log n)), and Adaptive—each optimized for different data characteristics.

---

## Instructions

### Compilation

The project includes a Makefile that handles compilation with proper flags (-Wall, -Wextra, -Werror). Use the following commands:

```bash
make              # Compile the main push_swap program
make bonus        # Compile the bonus checker program
make clean        # Remove object files
make fclean       # Remove all compiled files
make re           # Clean and recompile
```

### Execution

**Basic Usage - Default (Adaptive Strategy):**
```bash
./push_swap 2 1 3 6 5 8
```

This will display the sequence of operations needed to sort the stack.

**Force a Specific Strategy:**
```bash
./push_swap --simple 5 4 3 2 1       # Use O(n²) algorithm
./push_swap --medium 5 4 3 2 1       # Use O(n√n) algorithm
./push_swap --complex 5 4 3 2 1      # Use O(n log n) algorithm
./push_swap --adaptive 5 4 3 2 1     # Use adaptive algorithm (default)
```

**Benchmark Mode - View Performance Metrics:**
```bash
./push_swap --bench 5 4 3 2 1
```

This displays to stderr:
- Computed disorder percentage (with two decimals)
- Strategy name and theoretical complexity class
- Total number of operations
- Count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)

**Verify Results with Checker (Bonus):**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Available Operations

The program uses exactly 11 operations to manipulate the two stacks:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of Stack A |
| `sb` | Swap the first two elements of Stack B |
| `ss` | Swap the first two elements of both stacks |
| `pa` | Move the top element from Stack B to Stack A |
| `pb` | Move the top element from Stack A to Stack B |
| `ra` | Rotate Stack A upward (top element goes to bottom) |
| `rb` | Rotate Stack B upward |
| `rr` | Rotate both stacks upward |
| `rra` | Rotate Stack A downward (bottom element goes to top) |
| `rrb` | Rotate Stack B downward |
| `rrr` | Rotate both stacks downward |

---

## Algorithm Explanation and Justification

### Understanding Disorder

**Disorder** is a metric (0 to 1) that measures how far the stack is from being fully sorted. A disorder of 0 means the data is already sorted, while 1 means it's in the worst possible order.

**Calculation Method:**
```
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
    for j from i+1 to size(a)-1:
        if a[i] > a[j]:
            mistakes += 1
        total_pairs += 1
disorder = mistakes / total_pairs
```

This disorder value is computed before any operations are performed and determines which algorithm to use in adaptive mode.

### Required Strategies

#### 1. **Simple Algorithm (O(n²))**

**Examples of Suitable Implementations:**
- Insertion sort adaptation
- Selection sort adaptation
- Bubble sort adaptation

**Why This Complexity Class:**
- Simple and predictable for small datasets
- Minimal code complexity
- Easy to debug and understand

**When Used:**
- Forced with `--simple` flag
- In adaptive mode when disorder < 0.2 (dataset is mostly sorted)

**Characteristics:**
- Adequate for inputs up to ~100 items
- More efficient than naive algorithms on nearly-sorted data

#### 2. **Medium Algorithm (O(n√n))**

**Examples of Suitable Implementations:**
- Chunk-based sorting (divide into √n chunks)
- Block-based partitioning
- Bucket sort adaptations

**Why This Complexity Class:**
- Sweet spot for moderate data sizes
- Better than quadratic algorithms on random data
- Still manageable implementation complexity

**When Used:**
- Forced with `--medium` flag
- In adaptive mode when 0.2 ≤ disorder < 0.5

**Characteristics:**
- Optimal for inputs between 100-500 items
- Typically produces 5-6x the input size in operations

#### 3. **Complex Algorithm (O(n log n))**

**Examples of Suitable Implementations:**
- Radix sort adaptation (LSD or MSD)
- Merge sort adaptation using two stacks
- Quick sort adaptation with stack partitioning
- Heap sort adaptation

**Why This Complexity Class:**
- Optimal for large datasets
- Handles worst-case scenarios efficiently
- Scales well beyond 500 items

**When Used:**
- Forced with `--complex` flag
- In adaptive mode when disorder ≥ 0.5 (heavily unsorted data)

**Characteristics:**
- Best performance on random data
- Typically produces 3-4x the input size in operations for large sets

#### 4. **Adaptive Strategy (Default)**

**How It Works:**
1. Compute the disorder of the input stack
2. Select the most appropriate algorithm based on disorder percentage:
   - **Disorder < 0.2** → Use Simple Algorithm (O(n²))
   - **Disorder 0.2 to 0.5** → Use Medium Algorithm (O(n√n))
   - **Disorder ≥ 0.5** → Use Complex Algorithm (O(n log n))

**Why This Approach:**
- Maximizes efficiency across all input types
- Avoids wasting computational resources on overly complex algorithms for simple cases
- Adapts to real-world data patterns
- Demonstrates comprehensive algorithmic knowledge

**Threshold Justification:**
- **0.2 threshold**: Below this, sorting is almost trivial; simple algorithms excel
- **0.5 threshold**: Above this, the data is sufficiently random to benefit from advanced algorithms

### Performance Targets

To pass evaluation, the program must meet the following benchmarks:

**For 100 random numbers:**
- Pass: Less than 2000 operations
- Good: Less than 1500 operations
- Excellent: Less than 700 operations

**For 500 random numbers:**
- Pass: Less than 12000 operations
- Good: Less than 8000 operations
- Excellent: Less than 5500 operations

---

## Project Structure

```
push_swap/
├── src/
│   ├── main.c                      # Main entry point
│   ├── main_bonus.c                # Bonus program entry point
│   ├── commands/                   # Stack manipulation operations
│   │   ├── push.c
│   │   ├── swap.c
│   │   ├── rotate.c
│   │   └── rotate_reverse.c
│   ├── sorts/
│   │   ├── simple/
│   │   │   ├── bubble_sort.c
│   │   │   ├── insertion_sort.c
│   │   │   └── selection_sort.c
│   │   ├── medium/
│   │   │   └── turk_sort.c
│   │   └── complex/
│   │       └── upgraded_turk_sort.c
│   ├── utils/
│   │   ├── parse.c                 # Input parsing and validation
│   │   ├── error.c                 # Error handling
│   │   ├── get.c                   # Helper functions for data access
│   │   ├── sort_helpers.c          # Common sorting utilities
│   │   ├── compute_disorder.c      # Disorder measurement
│   │   ├── print_stack.c           # Stack visualization
│   │   └── print_bench.c           # Performance metrics
│   └── bonus/
│       ├── checker_bonus.c         # Sorting validation
│       └── get_next_line_bonus.c   # Line reading for checker
├── libft/                          # Custom C library
│   ├── memory/                     # Memory manipulation functions
│   ├── string/                     # String operations
│   ├── character/                  # Character classification
│   ├── lists/                      # Linked list operations
│   ├── ft_printf/                  # Printf implementation
│   └── libft.h                     # Library header
├── includes/
│   ├── push_swap.h                 # Main header file
│   └── get_next_line_bonus.h       # Bonus header
├── samples/                        # Test data files
├── Makefile                        # Build configuration
└── README.md                       # This file
```

---

## Resources

### Algorithm References
- [Insertion Sort Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)
- [Selection Sort Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
- [Bubble Sort Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/)

### C Programming
- [Parsing Command Line Arguments in C - Stack Overflow](https://stackoverflow.com/questions/9642732/parsing-command-line-arguments-in-c)

### Push Swap Specific
- [Push Swap - The Least Amount of Moves with Two Stacks - Medium](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [How to Over-Optimize an Algorithm: Push Swap 42 School Project - Medium](https://medium.com/@kilfenbaridon/how-to-over-optimize-an-algorithm-push-swap-42-school-project-d01a50e5fd78)
- [Push Swap Turk Algorithm Explained in 6 Steps - Medium](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

### AI Usage

**AI Assistance in This Project:**
AI tools were used strategically to enhance productivity:
- **Disorder Calculation Logic**: AI helped clarify the mathematical approach for disorder computation
- **Documentation and README**: AI assisted in structuring and refining this README file

**Human Work:**
- Core algorithm implementations (Chunk-based sorting, Radix sort approaches)
- Stack operation implementations
- Performance optimization and tuning
- Project structure and build configuration
- All debugging and validation

---

## Testing

To test the program with different input sizes:

```bash
# Small test
./push_swap 3 2 1

# Medium test with random numbers
./push_swap $(shuf -i 1-100 -n 100)

# Large test with benchmark
./push_swap $(shuf -i 1-500 -n 500) --bench

# Test with explicit flags
./push_swap --simple 5 4 3 2 1
./push_swap --complex $(shuf -i 1-500 -n 500)

# Verify with checker
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | ./checker $ARG
```

### Error Handling Tests

```bash
# Invalid arguments (non-integers)
./push_swap 3 2 hello

# Duplicate values
./push_swap 3 2 3 1

# Out of range
./push_swap 2147483648 1 2
```

---

## Contributors

**Kerem Şener** (ksener@student.42kocaeli.com.tr)
- Algorithm implementations (simple, medium, complex sorting strategies)
- Stack operation commands
- Adaptive algorithm logic

**Ahmet Yasin Dede** (adede@student.42kocaeli.com.tr)
- Input parsing and validation
- Disorder computation
- Makefile and build configuration
- Header file organization and structure

---

42 School Kocaeli