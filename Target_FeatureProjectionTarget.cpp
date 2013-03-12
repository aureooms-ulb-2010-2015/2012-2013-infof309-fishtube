#include "Target_FeatureProjectionTarget.h"
#include <sstream>



FeatureProjectionTarget::FeatureProjectionTarget(cv::Rect rect):rect(rect),age(0){}

FeatureProjectionTarget::FeatureProjectionTarget(int x, int y, cv::Scalar color, cv::Mat model):
	x(x),y(y),speed(0),acceleration(0),color(color),model(model),age(0){}
