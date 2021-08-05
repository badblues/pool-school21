#!/bin/bash

file=$1

if  [ ! -f $file ]; then
    exit
fi

#counting number of files
line=$(grep -o "^.*/\S*" $file )
IFS=$'\n'
arr=()
index=-1
for word in $line
    do
        flag=1
        for id in ${!arr[*]}
        do
            if [ $word = ${arr[$id]} ];
                then
                flag=0
            fi
        done
        if [ $flag = 1 ]; then
            let index=index+1
            arr[$index]=$word
        fi
    done
#counting number of hash_sums
hline=$(grep -o '\w* - sha256' $file )
IFS=$''
IFS=$'\n'
array=()
ind=-1
for line in $hline
    do
    flag=1
        for idd in ${!array[*]}
        do
            if [ $line = ${array[$idd]} ];
                then
                flag=0
            fi
        done
        if [ $flag = 1 ];
        then
            let ind=ind+1
            array[$ind]=$line
        fi
    done
echo "$(wc -l < $file) ${#arr[*]} ${#array[*]}"
