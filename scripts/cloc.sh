#!/bin/bash

if ! command -v cloc &> /dev/null
then
    echo "cloc could not be found"
    exit
fi

cloc ./src/ 

grep -vwE "(-DBEAR=1)" ./src/compile_commands.json > ./src/compile_commands.json 
