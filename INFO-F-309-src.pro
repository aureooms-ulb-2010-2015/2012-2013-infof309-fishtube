#-------------------------------------------------
#
# Project created by QtCreator 2012-12-13T11:16:05
#
#-------------------------------------------------

QT       += core gui opengl
ICON = img/play_icon.png

#for c++ 11 support
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = INFO-F-309-src
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += opencv
LIBS += -lv4l2 -lX11
#LIBS += -lwavelet2d -Lwavelet2s

INCLUDEPATH += /usr/local/lib/

SOURCES += \
    Mat2QImage.cpp \
    ImageDisplayerWidgetImpl.cpp \
    TimeDisplayerWidget.cpp \
    SwaperWidget.cpp \
    PlayPauseButtonWidget.cpp \
    InputChoiceWidget.cpp \
    TimeControlWidget.cpp \
    VideoPlayControlsWidget.cpp \
    ImageDisplayerWidgetImpl2.cpp \
    OpenCV_GLWidget.cpp \
    GLWidgetRenderingThread.cpp \
    ImageDisplayerWidgetImpl3.cpp \
    OpenCV_SynchronizedGLWidget.cpp \
    VideoStreamProcessor.cpp \
    ProcessingChoiceWidget.cpp \
    ZZZ_Example_processHandler.cpp \
    Algorithm_OomsAlgorithmTest.cpp \
    Main.cpp \
    MainWindow.cpp \
    Algorithm_NoProcessing.cpp \
    Algorithm_ColorDetection.cpp \
    Target.cpp \
    Algorithm_FaceDetector.cpp \
    Algorithm_EyeFaceDetector.cpp \
    Algorithm_OomsChallenge.cpp \
    RobustMatcher.cpp \
    Algorithm_Condensation.cpp \
    Algorithm_FaceDetector_Surf.cpp \
    Algorithm_BinaryMaskWithOriginalFrame.cpp \
    Matcher_TargetMatcherV1.cpp \
    Algorithm_CustomCondensationV1.cpp \
    Algorithm_FeatureProjection.cpp \
    networkstreaminputdialog.cpp \
    CustomTextInput.cpp \
    CustomComboBox.cpp


HEADERS += \
    Stream.h\
    StreamDisplayer.h \
    Mat2QImage.h \
    Clock.h \
    ImageDisplayerWidget.h \
    ImageDisplayerWidgetImpl.h \
    TimeDisplayerWidget.h \
    SwaperWidget.h \
    PlayPauseButtonWidget.h \
    InputChoiceWidget.h \
    VideoCaptureDeviceDetector.h \
    VideoCaptureDeviceDetectorForLinux.h \
    TimeControlWidget.h \
    VideoPlayControlsWidget.h \
    FrameProcessor.h \
    ImageDisplayerWidgetImpl2.h \
    OpenCV_GLWidget.h \
    GLWidgetRenderingThread.h \
    ImageDisplayerWidgetImpl3.h \
    OpenCV_SynchronizedGLWidget.h \
    VideoStreamInfo.h \
    ZZZ_Example_VideoStreamProcessor.h \
    VideoStreamReader.h \
    VideoStreamProcessor.h \
    ProcessingChoiceWidget.h \
    Algorithm_Tagging.h \
    Algorithm_OomsAlgorithmTest.h \
    MainWindow.h \
    Algorithm_Watershed.h \
    Algorithm_Sub_BinaryMask.h \
    Algorithm_MeanShift.h \
    Algorithm_FeaturesTracker.h \
    Algorithm_TagAnTrack.h \
    Algorithm_FeaturesTracker.h \
    Algorithm_Sub_BinaryMask.h \
    Algorithm_MeanShift.h \
    Algorithm_NoProcessing.h \
    Algorithm_ColorDetection.h \
    Target.h \
    Algorithm_FaceDetector.h \
    Algorithm_EyeFaceDetector.h \
    Algorithm_OomsChallenge.h \
    RobustMatcher.h \
    Algorithm_Condensation.h \
    Algorithm_FaceDetector_Surf.h \
    Algorithm_BinaryMaskWithOriginalFrame.h \
    Matcher_TargetMatcherV1.h \
    Matcher_TargetMatcher.h \
    Algorithm_CustomCondensation.h \
    Algorithm_CustomCondensationV1.h \
    DiscreteDistribution.h \
    Target_CondensationTargetV1.h \
    Target_CondensationTarget.h \
    Algorithm_Sub_Tagging.h \
    Algorithm_FeatureProjection.h \
    Target_FeatureProjectionTarget.h \
    networkstreaminputdialog.h \
    CustomTextInput.h \
    CustomComboBox.h

RESOURCES += img.qrc

OTHER_FILES += \
    qss/timeControlSlider.qss\
    qss/QComboBox.qss\
    img/play_icon.png\
    img/pause_icon.png \
    qss/QComboBoxDropDown.qss \
    xml/facedata.xml \
    xml/haarcascade_frontalface_alt.xml \
    xml/haarcascade_frontalface_default.xml \
    xml/lpbcascade_frontalface.xml \
    xml/haarcascade_eye_tree_eyeglasses.xml \
    data/greyfish.png \
    utils/sample.py \
    data/bigfish.png \
    data/yellowfish.png
