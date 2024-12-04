#!/bin/bash

start_time=$(date +%s)

cd $1

for i in $(seq 1 $2)
do
    ./a.out
done

end_time=$(date +%s)

total_time=$((end_time-start_time))

echo "Total time: $total_time"