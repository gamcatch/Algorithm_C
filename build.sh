#!/bin/bash
file_name=$(echo $1 | cut -d "." -f 1)
c++ -o out/$file_name $1 -fno-stack-protector
./out/$file_name