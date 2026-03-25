*This project has been created as part of the 42 curriculum by adede.*

# libft

## Description
This **libft** project is the first part of the 42 cursus and recreates a set of standard C library functions, as well as some additional utility functions. The goal is to understand C programming, memory management, string manipulation and simple linked list structuring.

This library serves as a collection of useful functions that can hopefully be reused in future projects.

## Library Overview
This library includes:
- **Character checks and conversions:** `ft_isalpha`, `ft_isdigit`, `ft_toupper`, `ft_tolower`, etc.
- **Memory functions:** `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_calloc`, etc.
- **String functions:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`, `ft_split`, etc.
- **Linked list functions:** `ft_lstnew`, `ft_lstadd_back`, `ft_lstlast`, `ft_lstclear`, `ft_lstmap`, etc.

This library is written in C and compiled as a static library `libft.a` that can be included in other projects.

## Instructions

### Compilation
To compile the library, run:
```bash
make
```
This will generate the `libft.a` static library.

### Usage
To use libft in your projects, include the header:
```c
#include "libft.h"
```
and link the library during compilation:
```bash
gcc main.c -L. -lft
```

### Cleaning
To clean object files:
```bash
make clean
```
To clean everything, including the library:
```bash
make fclean
```
To recompile:
```bash
make re
```

## Full Feature List
This **libft** library includes some standard C functions and additional utilities, categorized below:

### Type Conversions
- `ft_atoi` — converts a string to an integer
- `ft_itoa` — converts an integer to a string

### Memory Management
- `ft_memset` — fills memory with a constant byte
- `ft_memcpy` — copies memory area
- `ft_memmove` — copies memory area safely with overlap
- `ft_memchr` — locates a byte in memory
- `ft_memcmp` — compares two memory areas
- `ft_bzero` — sets memory to zero
- `ft_calloc` — allocates memory and initializes it to zero

### Character Checks & Conversions
- `ft_isalpha` — checks if character is alphabetic
- `ft_isdigit` — checks if character is a digit
- `ft_isalnum` — checks if character is alphanumeric
- `ft_isascii` — checks if character is an ASCII character
- `ft_isprint` — checks if character is printable
- `ft_toupper` — converts character to uppercase
- `ft_tolower` — converts character to lowercase

### String Manipulation
- `ft_strlen` — calculates string length
- `ft_strlcpy` — copies a string safely
- `ft_strlcat` — concatenates strings safely
- `ft_strchr` — locates first occurrence of a character in string
- `ft_strrchr` — locates last occurrence of a character in string
- `ft_strncmp` — compares two strings up to n characters
- `ft_strnstr` — locates a substring in a string
- `ft_strdup` — duplicates a string
- `ft_substr` — extracts a substring from a string
- `ft_strjoin` — joins two strings
- `ft_strtrim` — trims characters from the beginning and end of a string
- `ft_split` — splits a string into an array of strings
- `ft_strmapi` — applies a function to each character of a string to create a new string
- `ft_striteri` — applies a function to each character of a string in-place

### File Descriptors Output
- `ft_putchar_fd` — outputs a character to a file descriptor
- `ft_putstr_fd` — outputs a string to a file descriptor
- `ft_putendl_fd` — outputs a string followed by a newline to a file descriptor
- `ft_putnbr_fd` — outputs an integer to a file descriptor

### Linked List Functions
- `ft_lstnew` — creates a new list element
- `ft_lstsize` — counts the number of elements in a list
- `ft_lstlast` — returns the last element of the list
- `ft_lstadd_front` — adds an element at the beginning of the list
- `ft_lstadd_back` — adds an element at the end of the list
- `ft_lstdelone` — deletes one element of the list
- `ft_lstclear` — deletes and frees the entire list
- `ft_lstiter` — applies a function to each element of the list
- `ft_lstmap` — creates a new list by applying a function to each element of the original list

## Resources
- [Creating static library with `ar`](https://dev.to/iamkhalil42/all-you-need-to-know-about-c-static-libraries-1o0b)
- [ASCII reference](https://en.cppreference.com/w/c/language/ascii.html)
- [`size_t` and `SIZE_MAX`](https://en.cppreference.com/w/c/types/size_t.html)
- [File descriptors](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Makefile](https://makefiletutorial.com)
- [Markdown cheat sheet](https://www.markdownguide.org/cheat-sheet/)

### AI Usage
AI tools were used to:
- Create unit tests and inform about edge cases.
- Provide explanations for complex C concepts.
- Educate about real world uses of the functions that this library implements.

No AI was used to generate the library code **directly**; all functions were personally implemented but assistively tested.
