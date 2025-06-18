#!/bin/bash

echo "compiling..."
make all
echo "done"


echo "building test"
INPUT_FOLDER="./demo_data/"
LISTFILE="input_test_TMP.txt"
mkdir "temp_data"
OUTPUT_FOLDER="./temp_data/"
cd demo_data
../TRQC_nasa_to_bin input_test_TMP.txt ../temp_data/TMP.bin
cd ../
./TRQC_nasa_build_from_bin temp_data/TMP.bin 3 temp_data/TMP.trqc 
echo "done"

echo "end"

exit 0
