#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

filename="$1"

# Check if the file already exists
if [ -e "$filename.cpp" ]; then
    echo "File $filename.cpp already exists. Please choose a different name."
    exit 1
fi

# Create the C++ file with a main function
echo "#include <iostream>" >> "$filename.cpp"
echo "using namespace std;" >> "$filename.cpp"
echo "" >> "$filename.cpp"
echo "int main() {" >> "$filename.cpp"
echo "    // Your code here" >> "$filename.cpp"
echo "    return 0;" >> "$filename.cpp"
echo "}" >> "$filename.cpp"

echo "Created $filename.cpp with a main function."
