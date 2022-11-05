#!/bin/bash

if ! command -v clang-format &> /dev/null
then
    echo "clang-format could not be found"
    exit
fi

FILE_LIST="$(find "./src" | grep -E ".*(\.cpp|\.hpp)$")"

clang-format --verbose -i --style=file $FILE_LIST
