#!/bin/bash

# get filename as command line argument
filename="$1"

# remove leading spaces and empty lines
sed -i 's/^[[:space:]]*//' "$filename"
sed -i '/^$/d' "$filename"

echo "File '$filename' has been modified."
