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
## Algorithm


