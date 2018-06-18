#!/bin/bash

make
chmod a+x spim.s
cd t2Tests
ln -s ../exceptions.s exceptions.s

for i in `ls | grep "in$"`;do
     j=${i%.*}
     printf "%-43s" "Running $j..."
    ../hw5 < $i > $j.s
    timeout 10 ../spim.s read $j.s > $j.res
    if (( $?==124 ));then
        printf "\e[1;31m[ TIMEOUT ]\n\e[0m"
        continue
    fi
    err=`diff $j.res $j.out>/dev/null;echo $?`
    if (( err==0 ));then
    
     printf "\e[1;32m[ PASS ]\n\e[0m"
     else
     printf "\e[1;31m[ FAIL ]\n\e[0m"
     echo "Diff output:"
        diff $j.res $j.out
        exit 1
    fi
 done
 rm *.res
 rm *.s
echo "Testing done!"
