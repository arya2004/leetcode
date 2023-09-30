#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

filename="$1"

# Check if the file already exists
if [ -e "$filename" ]; then
    echo "File $filename already exists. Please choose a different name."
    exit 1
fi

# Create the C++ file with a main function
echo "#include <iostream>" >> "$filename"
echo "using namespace std;" >> "$filename"
echo "" >> "$filename"
echo "int main() {" >> "$filename"
echo "    // Your code here" >> "$filename"
echo "    return 0;" >> "$filename"
echo "}" >> "$filename"

echo "Created $filename with a main function."
