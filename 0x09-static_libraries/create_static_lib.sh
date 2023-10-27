#!/bin/bash

c_files=$(ls *.c)
ar rcs liball.a $c_files
ar t liball.a