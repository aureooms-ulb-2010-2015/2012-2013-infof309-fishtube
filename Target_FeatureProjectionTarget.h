#ifndef TARGET_FEATUREPROJECTIONTARGET_H
#define TARGET_FEATUREPROJECTIONTARGET_H

#include <string>
#include <opencv2/core/core.hpp>

class FeatureProjectionTarget{
private:
	std::string _id;
	static uint32_t NEXT_ID;

public:
	int x;
	int y;
	double speed;
	double acceleration;
	cv::Scalar color;
	cv::Mat model;
	cv::Rect rect;
	int age;

	FeatureProjectionTarget(cv::Rect);
	FeatureProjectionTarget(int, int, cv::Scalar, cv::Mat);

	std::string getId() const{ return this->_id; }
};

#endif // TARGET_FEATUREPROJECTIONTARGET_H
