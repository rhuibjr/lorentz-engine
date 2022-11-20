#!/bin/bash

if ! command -v clang-format-13 &> /dev/null
then
    echo "clang-format could not be found"
    exit
fi

FILE_LIST="$(find "./src" | grep -E ".*(\.cpp|\.hpp)$")"

clang-format-13 --verbose -i --style=file $FILE_LIST
