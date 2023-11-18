#!/bin/bash

# Compile all .c files into object files
gcc -c *.c

# Create the static library
ar -rc liball.a *.o
