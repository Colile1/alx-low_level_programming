#!/bin/bash

# Compile all .c files into object files
gcc -c *.c

# Create the static library
ar -rc liball.a *.o

# Clean up the object files
rm *.o

echo "Static library liball.a created."
