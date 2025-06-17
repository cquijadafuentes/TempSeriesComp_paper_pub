#!/bin/bash

INPUT_FOLDER="./demo_data/"
LISTFILE="input_test_TMP.txt"

mkdir "temp_data"
OUTPUT_FOLDER="./temp_data/"


pwd >> ${OUTPUTFILE}
echo "ACCESS QUERY" >> ${OUTPUTFILE}
echo "" >> ${OUTPUTFILE}

for filename in APCP CAPE CONVfrac DLWRF DSWRF PEVAP PRES SPFH TMP UGRD VGRD
do
	${EXEC} ${DATAFOLDER}${filename}.qc04 ${QUERYFILE} ${REPETICIONES} >> ${OUTPUTFILE}
done

echo "Fecha FIN ejecución: $(date +'%Y/%m/%d %H:%M:%S')" >> ${OUTPUTFILE}
exit 0
