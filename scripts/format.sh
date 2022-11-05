#!/bin/bash

FILE_LIST="$(find "./src/" | grep -E ".*(\.cpp|\.hpp)$")"

echo -e "Files found to format = \n\"\"\"\n$FILE_LIST\n\"\"\""

clang-format --verbose -i --style=file $FILE_LIST
