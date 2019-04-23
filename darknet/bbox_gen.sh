#!/usr/bin/expect -f

set timeout 100
# set KITTI_DIR ./kitti_test/
set TUM_DIR /media/eralien/ReservoirLakeBed1/Data/TUM/rgbd_dataset_freiburg1_room/rgb/
# set KITTI_LIST ./kitti_list.txt
set TUM_LIST ./TUM_list.txt
set FID [open ${TUM_LIST} r]

# exec sh -c {./kitti_dir_gen.sh}

puts "Bounding Box Info Generating..."
sleep 1

spawn ./darknet detect cfg/yolov3.cfg yolov3.weights

while { [gets $FID line] >= 0} {
    set name [lindex $line 0]

    expect "Enter Image Path: " 
    send $TUM_DIR$name\r
    # puts "what is happening"
}

close $FID

expect eof