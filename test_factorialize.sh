#!/bin/bash

RESULT=
EXPECTED=
EXPECTEDARRAY=( $(cat factorials_up_to_100.txt | cut -f2) )

for i in {1..21}
do
    RESULT=$(./factorialize $i)
    EXPECTED="${EXPECTEDARRAY[i-1]}"
    if [[ $RESULT == $EXPECTED ]] ; then
        echo "CORRECT: for $i: $RESULT"
    else
        echo "INCORRECT: for $i: $RESULT"
    fi
done
