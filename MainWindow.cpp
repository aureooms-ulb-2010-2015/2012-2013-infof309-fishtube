#include "MainWindow.h"
#include <QApplication>
#include <QKeyEvent>
#include "Algorithm_NoProcessing.h"
#include "Algorithm_Tagging.h"
#include "Algorithm_OomsAlgorithmTest.h"
#include "Algorithm_FeaturesTracker.h"
#include "Algorithm_TagAnTrack.h"
#include "Algorithm_Sub_BinaryMask.h"
#include "Algorithm_BinaryMaskWithOriginalFrame.h"
#include "Algorithm_Watershed.h"
#include "Algorithm_MeanShift.h"
#include "Algorithm_FaceDetector.h"
#include "Algorithm_EyeFaceDetector.h"
#include "Algorithm_OomsChallenge.h"
#include "Algorithm_Condensation.h"
#include "Algorithm_CustomCondensationV1.h"
#include "Algorithm_FaceDetector_Surf.h"
#include "Algorithm_FeatureProjection.h"
#include "Algorithm_TaggingB.h"
#include "Algorithm_CustomCondensationTemplateV2.h"
#include "Matcher_GreyLevelDistanceMatcher.h"

//===================================================
// Le seul code auquel il faut toucher pour rajouter des algos à pouvoir exécuter, attention à respecter l'ordre!!

FrameProcessor* MainWindow::generateProcessor(){
	switch(this->_frameProcessorId){
    case 0:
		return new NoProcessing();
	case 1:
		return new BinaryMaskWithOriginalFrame(cv::Size(1,1));
	case 2:
		return new Tagging(0,0.01,cv::Size(1,1));
	case 3:
		return new Watershed(0, cv::Size(1,1));
	case 4:
		return new FeatureTracker();
	case 5:
		return new TagNTrack(cv::Size(1,1));
	case 6:
		return new OomsChallenge();
	case 7:
		return new CustomCondensationV1();
	case 8:
		return new CustomCondensationTemplateV2<GreyLevelDistanceMatcher<6> >();
	case 9:
		return new Tagging();
	case 10:
		return new OomsAlgorithmTest();
	case 11:
		return new OomsAlgorithmTest(0.05,5);
	case 12:
		return new EyeFaceDetector();
	case 13:
		return new TagNTrack();
	case 14:
		return new Sub_BinaryMask();
	case 15:
		return new Watershed();
	case 16:
		return new MeanShift();
	case 17:
		return new Condensation();
	case 18:
		return new FaceDetector_Surf();
	case 19:
		return new BinaryMaskWithOriginalFrame();
	case 20:
		return new FeatureProjection();
	case 21:
		return new TaggingB();
        //...

    }

    return NULL;
}


void MainWindow::initProcessingChoices(){
    this->_processingChoice->addItem("Pas de traitement");
	this->_processingChoice->addItem("Binary Mask (No blur)");
	this->_processingChoice->addItem("Tagging (No blur)");
	this->_processingChoice->addItem("Watershed (No blur)");
	this->_processingChoice->addItem("FeatureTracker");
	this->_processingChoice->addItem("TagNTrack (No blur)");
	this->_processingChoice->addItem("Ooms Challenge");
	this->_processingChoice->addItem("CustomCondensationV1");
	this->_processingChoice->addItem("CustomCondensationTemplateV2 (GreyLevelDistanceMatcher)");
    this->_processingChoice->addItem("Tagging");
    this->_processingChoice->addItem("OomsAlgorithmTest (default)");
    this->_processingChoice->addItem("OomsAlgorithmTest (0.05,5)");
	this->_processingChoice->addItem("Face and eye detector");
    this->_processingChoice->addItem("TagNTrack");
    this->_processingChoice->addItem("Binary Mask");
	this->_processingChoice->addItem("Watershed");
	this->_processingChoice->addItem("MeanShift");
	this->_processingChoice->addItem("Condensation");
	this->_processingChoice->addItem("Face detection with surf");
	this->_processingChoice->addItem("Binary Mask (original frame included)");
	this->_processingChoice->addItem("FeatureProjection");
    this->_processingChoice->addItem("Tagging B merger");
    //...
}

//===================================================
//Ne pas toucher plus bas si c'est pour rajouter un algo.




MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
    this->setWindowTitle("FishTube");

	this->initProcessingChoices();

	QHBoxLayout* upperBarLayout = new QHBoxLayout(this->_upperBar);
	upperBarLayout->addWidget(this->_inputChoice);
	upperBarLayout->addWidget(this->_processingChoice);
	upperBarLayout->setContentsMargins(0,0,0,0);

	QObject::connect(this->_processingChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFrameProcessorSLOT(int)));
}

MainWindow::~MainWindow(){}

void MainWindow::keyPressEvent(QKeyEvent* event){
	for(int i = 0; i < this->_processingChoice->count(); ++i){
		if( (QApplication::keyboardModifiers() & ~Qt::ShiftModifier ) == Qt::ControlModifier && event->key() == (Qt::Key_0 + i)){
			return this->_processingChoice->setCurrentIndex(i);
		}
	}
	return BasicWindow::keyPressEvent(event);
}




void MainWindow::changeFrameProcessorSLOT(int index){
    this->_frameProcessorId = index;
    bool wasPlaying = this->_videoControls->isPlaying();
    if(wasPlaying){
        this->_displayer->pause();
    }
	this->_streamProcessor->stop();
	delete this->_frameProcessor;
	this->_frameProcessor = this->generateProcessor();
    this->_streamProcessor->reset(this->_streamReader, this->_frameProcessor);
    if(wasPlaying){
        this->_displayer->play();
        this->_videoControls->setPlaying();
    }
}


