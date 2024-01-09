#!/bin/bash

# Check if exactly two parameters are passed
if [ "$#" -ne 2 ]; then
    echo "You need to provide exactly two parameters."
    exit 1
fi

# Check if the parameters are integers
if ! [[ "$1" =~ ^[0-9]+$ ]] || ! [[ "$2" =~ ^[0-9]+$ ]]; then
    echo "Both parameters need to be integers."
    exit 1
fi

# Print the name of the script, the value of both parameters, and the maximum of them
echo "Script Name: $0"
echo "Parameter 1: $1"
echo "Parameter 2: $2"

if [ "$1" -gt "$2" ]; then
    echo "The maximum of the transmitted integers is $1."
else
    echo "The maximum of the transmitted integers is $2."
fi
