#!/bin/bash

cd /
cd proc

printf "Number of processors : "
nproc

printf "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n"
printf "Number of cores, frequency of processor : \n"
cat cpuinfo

#- Number of cores : 4
#- Frequency of processor : 2419.198 MHz (per processor)