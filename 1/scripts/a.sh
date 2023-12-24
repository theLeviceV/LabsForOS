#!/bin/bash

# Check if exactly two parameters are passed
if [ "$#" -ne 2 ]; then
    echo "You need to provide exactly two parameters."
    exit 1
fi

# Print the name of the script, the value of both parameters, as well as a message about the equality or inequality of the transmitted strings
echo "Script Name: $0"
echo "Parameter 1: $1"
echo "Parameter 2: $2"

if [ "$1" == "$2" ]; then
    echo "The transmitted strings are equal."
else
    echo "The transmitted strings are not equal."
fi

# Repeat the script with the output of information to the file outa.
# If the file already exists, it will be overwritten.
# If it doesn't exist, it will be created.
echo "Script Name: $0" > outa
echo "Parameter 1: $1" >> outa
echo "Parameter 2: $2" >> outa

if [ "$1" == "$2" ]; then
    echo "The transmitted strings are equal." >> outa
else
    echo "The transmitted strings are not equal." >> outa
fi
