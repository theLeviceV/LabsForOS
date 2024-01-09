#!/bin/bash

# Check if exactly four parameters are passed
if [ "$#" -ne 4 ]; then
    echo "You need to provide exactly four parameters."
    exit 1
fi

# Check if the parameters are integers
if ! [[ "$1" =~ ^[0-9]+$ ]] || ! [[ "$2" =~ ^[0-9]+$ ]] || ! [[ "$3" =~ ^[0-9]+$ ]] || ! [[ "$4" =~ ^[0-9]+$ ]]; then
    echo "All parameters need to be integers."
    exit 1
fi

# Print the name of the script, the value of all parameters, and the maximum of them
echo "Script Name: $0"
echo "Parameter 1: $1"
echo "Parameter 2: $2"
echo "Parameter 3: $3"
echo "Parameter 4: $4"

max=$1
if [ "$2" -gt "$max" ]; then
    max=$2
fi
if [ "$3" -gt "$max" ]; then
    max=$3
fi
if [ "$4" -gt "$max" ]; then
    max=$4
fi
echo "The maximum of the transmitted integers is $max."
