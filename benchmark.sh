#!/bin/bash

start_time=$(date +%s)

for i in {1..10000}
do
    ./a.out
done

end_time=$(date +%s)

total_time=$((end_time-start_time))

echo "Total time: $total_time"