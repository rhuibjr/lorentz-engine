#!/bin/bash

if ! command -v pmccabe &> /dev/null
then
    echo "pmccabe could not be found"
    exit
fi

FILE_LIST="$(find "./src" | grep -E ".*(\.cpp|\.hpp)$")"

pmccabe -v $FILE_LIST
