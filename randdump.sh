#!/bin/sh

max=41
j=15
for i in `seq 26 $max`
do
    step=`expr $j \* \( $i - 20 \)`
    ./randdump "$step"
    mv dump.tmp "randdump_$i.dat"
done
