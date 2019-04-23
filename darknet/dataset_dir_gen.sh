#!/bin/bash
# get all filename in specified path

image_path=../Sample/rgbd_dataset_freiburg1_xyz/rgb/
log_path=./prediction_info.txt
list_file=./TUM_list.txt

rm -f $log_path
echo "" > $log_path

if test -s $list_file; then
    echo "Dataset list file exist"
else
    echo "Generaing dataset list..."
    files=$(ls $image_path)
    for filename in $files
    do
        echo $filename >> $list_file
    done
    echo "Done"
    
    echo "prediction_info txt regenerated"
fi


