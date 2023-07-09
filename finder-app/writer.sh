#!/bin/bash

# Check if the required arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Please provide the writefile and writestr arguments."
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p $(dirname "$writefile")
#sudo chmod -R 777 /tmp/aesd/assignment1/.
# Create the file with the given content
#mkdir /tmp/aeld-data

echo "$writestr" > "$writefile"

# Check if the file was created successfully
if [ $? -ne 0 ]; then
    echo "Error: Failed to create the file."
    exit 1
fi

echo "File created successfully: $writefile"

