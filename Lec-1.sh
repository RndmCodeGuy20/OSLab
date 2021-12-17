#!/bin/bash

Master_Name="Shantanu"

printf "Hello User, $Master_Name here!%s\n"
echo "Who are you?"
read name
echo "Hello, $name!"

printf "%s\nWhich year's calender would you like to see?%s\n"
read year
cal $year

printf "%s\n\nToday's Date : "
date