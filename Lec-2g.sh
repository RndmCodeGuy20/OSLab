#!/bin/bash

cd /
cd proc

printf "Total number of context switches : \n"

vmstat -f

#- total number of context switches : 1353051