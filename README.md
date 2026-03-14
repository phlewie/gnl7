*This project has been created as part of the 42 curriculum by susim.*

# get_next_line

## Description
'get_next_line' is a function that reads from a file descriptor and returns one line at a time. The goal of the project is to understand how to read data progressively with 'read()', keep the remaining part of the input between function calls, and manage memory correctly while returning each line separately. In this implementation, the function keeps a static buffer, reads from the file descriptor until a newline is found or the end of file is reached, extracts, the next line, and then updates the buffer with the remaining contents.

---

## Instructions
### Compilation

Compile with your test file and the project files:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c main.c

Run the compiled program: 

./a.out

The main.c file should open a file and call get_next_line(fd) repeatedly until it returns NULL.

```
---
## Algorithm
The algorithm of this project is based on a simple idea:
keep reading until one complete line is available, return that line, then save what is left for the next call.

This implementation is divided into three main steps.

1. Read and append data until a line is complete
The function `read_to_buffer` reads from the file descriptor and appends the new data to the existing buffer.

It keeps reading while there is no `\n` in the current buffer.

This choice was made because `get_next_line` must return exactly one line at a time. So the function only needs to read until it has enough data to build one complete line. 

2. Extract the next line
Once the buffer contains a newline, or no more data can be read, `extract_line` creates a new string containing only the next line.
If a newline exists, the line includes it.
If there is no newline, the function returns the remaining content as the last line.

3. Keep only the unread remainder
After returning one line, `update_buffer` removes that line from the buffer and keeps only the remaining part.

This is necessary because the next call to get_next_line must continue exactly where the previous one stopped. 

---
## Design choices
### Why use a static buffer
A static buffer is used so the function can keep its state between calls.
Without a static variable, the remaining content would be lost each time the function returns. 
Since `get_next_line` only returns one line per call, storing the rest of the data is necessary. 

### Why the loop condition is based on `ft_strchr(buffer, '\n')`
The reading loop continues while no newline is found in the current buffer.
This makes the function stop reading as soon as it has enough information to return one line. 
It avoids unnecessary reads and keeps the logic simple

### Why the buffer is not manually initialized with `ft_strdup("")`
In this implementation, the buffer is not explicitly initialized to an empty string before the first read.

Instead, this behavior is handled by the utility functions:
- `ft_strchr` safely returns NULL when the buffer is NULL
- `ft_strjoin` handles a NULL first string by duplicating the second one.
Because of this design, the first read can work without a separate initialization step like:

```bash
buffer = ft_strdup("");
```
This choice keeps the main logic shorter and moves the `NULL` handling into the utility layer.

### Why split the work into small helpfer functions
The project was separated into:
- reading and appending
- extracting one line
- updating the remaining buffer
This makes the code easier to read, test, and debug.
Each function has one clear role in the full process.

### File structure
- `get_next_line.c`
  Main logic of the project
- `get_next_line_utils.c`
  Utility functions used for string handling
- `get_next_line.h`
  Header file with prototypes and `BUFFER_SIZE`

---

## Resources
Classic references used for this project:
- 42 subject and project guidelines
- manaual pages for `read`, `malloc`, and `free`
- C string handling practice and personal notes from previous 42 projects

Additional references:
- file discriptor & system call: https://cs61.seas.harvard.edu/site/2025/file-descriptors/
- static variable : https://cs61.seas.harvard.edu/site/2025/file-descriptors/
## AI usage
AI used as a review and explanation tool during the project.
More specifically, it was used for : 
- checking the correctness of the overall logic
- reviewing edge cases
- discussing design decisions