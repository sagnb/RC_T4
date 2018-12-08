#!/bin/bash

if [ $# -lt 3 ]; then
    echo "Utilize: $0 <hosts> <ASs> <pares>"
    exit 1
fi

for i in $(seq 0 $3) 
do 
    echo "H$((RANDOM%$1)) AS$((RANDOM%$2)) H$((RANDOM%$1)) AS$((RANDOM%$2))"
done