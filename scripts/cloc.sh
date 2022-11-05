#!/bin/bash

if ! command -v cloc &> /dev/null
then
    echo "cloc could not be found"
    exit
fi

cloc ./src/ 
