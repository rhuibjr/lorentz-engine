#!/bin/bash

if ! command -v clang-tidy &> /dev/null
then
    echo "clang-tidy could not be found"
    exit
fi

FILE_LIST="$(find "./src" | grep -E ".*(\.cpp|\.hpp)$")"

clang-tidy $FILE_LIST
