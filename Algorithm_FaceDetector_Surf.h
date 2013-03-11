#ifndef ALGORITHM_FACEDETECTOR_SURF_H
#define ALGORITHM_FACEDETECTOR_SURF_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/contrib/detection_based_tracker.hpp>
#include <iostream>
#include "FrameProcessor.h"

class FaceDetector_Surf : public FrameProcessor {
private:
    cv::CascadeClassifier _classifier;
public:
    FaceDetector_Surf();

    void process(const cv::Mat &in, cv::Mat &out);
};

#endif // ALGORITHM_FACEDETECTOR_SURF_H
