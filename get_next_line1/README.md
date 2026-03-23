*This project has been created as part of the 42 curriculum by dkucharo.*

# Description

The goal of this project is to create a function that returns a line read from a file descriptor. This implementation introduces the concept of static variables in C to manage data remaining between successive function calls. The function supports reading from files as well as standard input.

# Instructions

**Compilation**
* Compile with: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line.h get_next_line_utils.c`

**Requirements**
* Files to submit: get_next_line.c, get_next_line_utils.c, get_next_line.h.
* Allowed functions: read, malloc, free.
* Forbidden: lseek(), global variables, and the use of libft.

# Resources

* Documentation: Unix Manual Pages for read(2), malloc(3), and free(3).
* https://dev.to/aerrfig/get-next-line-a-42-project-to-learn-how-to-deal-with-file-descriptors-and-io-of-system-3652
* https://www.youtube.com/watch?v=rxQFQXf60r4

* AI Usage: Gemini (AI) was used as a learning collaborator to debug memory management and to optimize the search algorithm to resolve "timeout" issues in the fill_line_buffer function.
