#!/bin/bash


make clean

make

#just another test comment
# Check if the required arguments are provided
if [ $# -ne 2 ]; then
    #echo "Error: Please provide the filesdir and searchstr arguments."
    exit 1
fi

filesdir=$1
searchstr=$2

# Check if filesdir exists and is a directory
if [ ! -d "$filesdir" ]; then
    #echo "Error: The specified filesdir is not a directory."
    exit 1
fi

# Find the number of files in the directory and its subdirectories
file_count=$(find "$filesdir" -type f | wc -l)

# Find the number of matching lines
matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $file_count and the number of matching lines are $matching_lines"


