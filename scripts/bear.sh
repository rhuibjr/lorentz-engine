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

rm -rf compile_commands.json

bear -- make BEAR=1

if [[ "$OSTYPE" == "darwin"* ]]; then
    sed -i '' '/\"-DBEAR=1\",/d' compile_commands.json
    exit
fi

sed -i'' '/\"-DBEAR=1\",/d' compile_commands.json
