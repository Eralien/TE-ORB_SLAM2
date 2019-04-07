# YOLO Task

To utilize **DarkNet** as a function, where shell commands are inputs, and receive outputs.

## Outputs
The output should be the size of the input image. Each pixel contains the information of its class and probability.

### Class definition
* Assign int k>0 for one specific class K, eg vehicles, chairs.
* Assign 0 for pixels not belongs to any class

***Problems***
* How to deal with pixels with multiple classes?
  * Assign the class with highest probability
  * Use a vector to include all of them
* Export the specific __class-index__ pair from YOLO
* How to realize the output
  * The outputs has alreay be printed out, but that's quite dumb
 
## Inputs
The shell command to process a spefic image in darknet

    ./darknet detect cfg/yolov3.cfg yolov3.weights data/dog.jpg

***Problems***
* How to effectively call darknet in ORB-SLAM?
* And 