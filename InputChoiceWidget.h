#ifndef INPUTCHOICEWIDGET_H
#define INPUTCHOICEWIDGET_H

#include <QComboBox>

class InputChoiceWidget : public QComboBox{
	Q_OBJECT
private:
	QString _lastVisitedFolder;

public:
	InputChoiceWidget();
	QString getVideoFilePath();
	virtual void showPopup();
	virtual void refreshDevices();

public slots:
	void currentIndexChangedSLOT(int);

signals:
	void currentSourceChanged(int);
	void currentSourceChanged(QString);

};

#endif // INPUTCHOICEWIDGET_H
