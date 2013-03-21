#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ProcessingChoiceWidget.h"
#include "BasicWindow.h"

class MainWindow : public BasicWindow{
    Q_OBJECT

private:

	ProcessingChoiceWidget* _processingChoice;
	int _frameProcessorId = 0;

	void initProcessingChoices();

	virtual FrameProcessor* generateProcessor();

public:
    explicit MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	virtual void keyPressEvent(QKeyEvent *);

public slots:
	void changeFrameProcessorSLOT(int);

};

#endif // MAINWINDOW_H
