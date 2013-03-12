#ifndef ALGORITHM_FEATUREPROJECTION_H
#define ALGORITHM_FEATUREPROJECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "FrameProcessor.h"
#include "Target.h"
#include "Algorithm_Sub_Tagging.h"


class FeatureProjection : public FrameProcessor {
private:
	std::vector<Target> _previousTargets;
	Sub_Tagging tagging;

	const int AGE_TRUST = 64;
	const int AGE_MID = 24;
	const int AGE_DIE = 12;
	const int AGE_PENALTY = 1;
	const int AGE_BONUS = 2;
	const int MAXSIZE = 40;
	const int MINSIZE = 5;

	const int MAXDIST = 40;
	const int MAXTRANSFORM = 40;


public:

	FeatureProjection();
	virtual void process(const cv::Mat &in, cv::Mat &out);

	virtual std::multimap<int, std::pair<size_t,size_t> > generateMatchingScores(const std::vector<Target>&) const;
	virtual std::vector<std::pair<size_t,size_t> > generateMatches(const std::multimap<int, std::pair<size_t,size_t> >&, size_t) const;
	virtual void writeFishCount(cv::Mat&, int);
};

#endif // ALGORITHM_FEATUREPROJECTION_H
