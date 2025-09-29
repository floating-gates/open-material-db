#!/bin/sh

# Check if program exists
if [ ! -x "./open-mat-db" ]; then
    echo "Error:  open-mat-db not found, trying to compile..."
    make
fi

# Check if program exists
if [ ! -x "./open-mat-db" ]; then
    echo "Error: Not able to compile."
    exit 1
fi

# Iterate over all .json files in ./material-records
for file in ./material-records/*.json; do
    # Check if file exists (in case no .json files found)
    if [ -f "$file" ]; then
        echo "Processing $file..."
        ./open-mat-db "$file"
    fi
done
