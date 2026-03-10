*Este proyecto ha sido creado como
parte del currículo de 42 por romarti2.*

## Description
Get_Next_Line (GNL) is a fundamental project in the 42 curriculum. The objective is to program a function that returns a line read from a file descriptor (fd).

The primary challenge lies in managing data reading efficiently by using a static variable to "remember" leftover content from previous reads. This project introduces key concepts such as buffer management, the use of static variables in C, and precise manipulation of dynamic memory (heap) to prevent memory leaks.

## Instructions

### Compilation
The function is designed to be integrated into other projects. It can be compiled alongside the necessary .c files by defining the buffer size:

### Bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

### Usage
To use the function in your code, include the header:

#include "get_next_line.h"

### Basic Implementation Example:

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);


## Algorithm and Rationale
The selected algorithm is based on the use of a static variable that acts as a persistent buffer between function calls.

### Algorithmic Flow:
<u>Cumulative Reading:</u> Data is read from the file in chunks of BUFFER_SIZE. These chunks are concatenated into the static variable until a newline character (\n) is detected or the end of the file (EOF) is reached.

<u>Extraction:</u> Once a full line is present in the static variable, the content is "cut" from the beginning up to the first \n.

<u>State Update:</u> The portion of the string following the \n is stored back into the static variable to be processed during the next call to get_next_line.

### Rationale:
This approach was chosen because it allows for optimal memory management by ensuring no data is lost between calls. Using BUFFER_SIZE as a compilation parameter allows the program's efficiency to be adapted to the environment, balancing the number of system calls (read) against RAM consumption.

## Resources

### References and Documentation

read man page: To understand the behavior of file descriptors and return values.

Static Variables in C: Documentation on the lifetime and scope of static variables.

Valgrind Memcheck:An essential tool to ensure every malloc has a corresponding free and that no leaks exist.

CS50_Harvard: https://cs50.harvard.edu/x/weeks/5/

Peer to Peer.

### Use of AI
In this project, AI (such as ChatGPT/Gemini) was used in the conceptual explanation of the behavior of static variables and heap memory and structuring the README.