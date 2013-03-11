#include "Algorithm_FaceDetector_Surf.h"
#include "RobustMatcher.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <string>
#include <ostream>

FaceDetector_Surf::FaceDetector_Surf() {
    this->_classifier.load("haarcascade_frontalface_default.xml");
}


void recognize(const cv::Mat& , cv::Rect);

void FaceDetector_Surf::process(const cv::Mat &in, cv::Mat &out) {

    // Create a new image based on the input image
    out = in.clone();
    std::vector<cv::Rect> faces;


    // There can be more than one face in an image.
    // So create a growable sequence of faces.
    // Detect the objects and store them in the sequence
    this->_classifier.detectMultiScale(out, faces, 1.2, 3, CV_HAAR_DO_CANNY_PRUNING, cv::Size(25, 25));


    // Loop the number of faces found.
    for( size_t i = 0; i < faces.size(); ++i )  {
        // Draw the rectangle in the input image
        cv::rectangle( out, faces.at(i), cv::Scalar(255,0,0), 3, 8, 0);
    }
    cv::Point point;
    point.x=20;
    point.y=20;


    std::ostringstream faces_;
    faces_ << "Number of Faces : " << faces.size();

	//cv::Mat test;
    cv::putText(out, faces_.str(), point, cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(255,0,0), 1, CV_AA);

    try{
        if (faces.size()>0){
            recognize(in, faces.at(0));
        }
	}catch(std::exception e){
	}
    return;

}




void recognize(const cv::Mat &in, cv::Rect roi) {

    cv::Mat image1= cv::imread("simo2.png",0);



    // Prepare the matcher
    RobustMatcher rmatcher;
    rmatcher.setConfidenceLevel(0.98);
    rmatcher.setMinDistanceToEpipolar(1.0);
    rmatcher.setRatio(0.65f);
    cv::Ptr<cv::FeatureDetector> pfd = new cv::SurfFeatureDetector(10);
    rmatcher.setFeatureDetector(pfd);

    cv::Mat out = in.clone();
    cv::Mat face = in(roi);

    // Match the two images
    std::vector<cv::DMatch> matches;
    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    cv::Mat fundemental = rmatcher.match(image1, face ,matches, keypoints1, keypoints2);


    // draw the matches
    cv::Mat imageMatches;
    cv::drawMatches(image1,keypoints1,  // 1st image and its keypoints
                    face,keypoints2,  // 2nd image and its keypoints
                    matches,			// the matches
                    imageMatches,		// the image produced
                    cv::Scalar(255,255,255)); // color of the lines
    cv::namedWindow("Matches");
    cv::imshow("Matches",imageMatches);



    // Convert keypoints into Point2f
    std::vector<cv::Point2f> points1, points2;

    for (std::vector<cv::DMatch>::const_iterator it= matches.begin();
             it!= matches.end(); ++it) {

             // Get the position of left keypoints
             float x= keypoints1[it->queryIdx].pt.x;
             float y= keypoints1[it->queryIdx].pt.y;
             points1.push_back(cv::Point2f(x,y));
             cv::circle(image1,cv::Point(x,y),3,cv::Scalar(255,255,255),3);
             // Get the position of right keypoints
             x= keypoints2[it->trainIdx].pt.x;
             y= keypoints2[it->trainIdx].pt.y;
             cv::circle(out,cv::Point(x,y),3,cv::Scalar(255,255,255),3);
             points2.push_back(cv::Point2f(x,y));
    }

/*
    // Draw the epipolar lines
    std::vector<cv::Vec3f> lines1;
    cv::computeCorrespondEpilines(cv::Mat(points1),1,fundemental,lines1);

    for (std::vector<cv::Vec3f>::const_iterator it= lines1.begin();
             it!=lines1.end(); ++it) {

             cv::line(out,cv::Point(0,-(*it)[2]/(*it)[1]),
                             cv::Point(out.cols,-((*it)[2]+(*it)[0]*out.cols)/(*it)[1]),
                             cv::Scalar(255,255,255));
    }

    std::vector<cv::Vec3f> lines2;
    cv::computeCorrespondEpilines(cv::Mat(points2),2,fundemental,lines2);

    for (std::vector<cv::Vec3f>::const_iterator it= lines2.begin();
             it!=lines2.end(); ++it) {

             cv::line(image1,cv::Point(0,-(*it)[2]/(*it)[1]),
                             cv::Point(image1.cols,-((*it)[2]+(*it)[0]*image1.cols)/(*it)[1]),
                             cv::Scalar(255,255,255));
    }
*/
    /*
    // Display the images with epipolar lines
    cv::namedWindow("Right Image Epilines (RANSAC)");
    cv::imshow("Right Image Epilines (RANSAC)",image1);
    cv::namedWindow("Left Image Epilines (RANSAC)");
    cv::imshow("Left Image Epilines (RANSAC)",image2);
    */

    cv::waitKey();
    //return 0;

}


