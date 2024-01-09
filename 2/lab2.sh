#!/bin/bash

# Compiler settings
CC="gcc"
CFLAGS="-o lab2"

# Name of the source code file
SRC="lab2.c"

# Compile the source code
echo "Compiling $SRC..."
$CC $CFLAGS -o example $SRC

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed."
    exit 1
fi

# Filling in and out the input.txt
ls -a /home/levice/ > input.txt
cat input.txt

# Launching the program
./lab2

# Output the result to the console
cat output.txt
