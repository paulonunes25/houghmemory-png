#!/bin/sh

for i in $(seq -f "%02g" 1 10)
do 
  ratio="0.0$i"
  echo $ratio
  for j in `seq 26 41`
  do
     seed="$RANDOM"
     echo $RANDOM
     echo "$ratio $j $seed"
#    zzuf -r $ratio -s $RANDOM cat "randdump_$j.dat > zzuf$ratio_dump_rnd$j.dat"
  done
done
