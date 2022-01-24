# get_next_line
```get_next_line(int fd);```

This is the second project I did in 42 School.

- This function will read and return a line from a given file descriptor. If called in a loop, it will return one line at a time, until the end of the file.

- On compile, the user has to specify a buffer size, as the following example:
```gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c```
