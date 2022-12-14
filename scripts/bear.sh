#!/bin/bash

if ! command -v sed &> /dev/null
then
    echo "sed could not be found"
    exit
fi

if ! command -v bear &> /dev/null
then
    echo "bear could not be found"
    exit
fi

make clean
echo ''

bear -- make BEAR=1

# DARWIN = sed -i [POSTFIX]
# GNU = sed -i[POSTFIX] no space! 
if [[ "$OSTYPE" == "darwin"* ]]; then
    sed -i '' '/\"-DBEAR=1\",/d' compile_commands.json
    exit
fi

sed -i'' '/\"-DBEAR=1\",/d' compile_commands.json
