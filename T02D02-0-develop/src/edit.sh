#!/bin/bash

file=$1
str1=$2
str2=$3

if  [ ! -f $file ]; then
    exit
fi

if [ $str1 = $str2 ]; then
    exit
fi

if [ $str1 = '' ]; then
    exit
fi

$(grep -q "$str1" $file)
if [ $? -eq 0 ]; then
    sed -i '' "s/$str1/$str2/g" $file
    echo "src/history_of_vim.txt - $(stat -f%z $file) - $(date "+%Y-%m-%d") $(date "+%H:%M") - $(shasum -a 256 $file  | awk '{print $1}') - sha256" >> files.log
fi
