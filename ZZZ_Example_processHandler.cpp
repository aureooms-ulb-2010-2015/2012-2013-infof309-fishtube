#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/video/background_segm.hpp>

#include "VideoStreamProcessor.h"
#include "Algorithm_Tagging.h"

//int main()
//{
//    VideoStreamProcessor processor;

//    Tagging tag;
//    tag.setThreshold(20);
//    tag.setLearningRate(0.01);

//    processor.setFrameProcessor(&tag);

//    // Open video file
//    processor.setInput("../fishs.avi");

//    // window to display the video
//    processor.displayOutput("Extracted Foreground");

//    // Play the video at the original frame rate
//    processor.setDelay(1000./processor.getFrameRate());

//    processor.run();

//}

