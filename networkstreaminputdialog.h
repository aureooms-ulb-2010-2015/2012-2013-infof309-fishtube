#ifndef NETWORKSTREAMINPUTDIALOG_H
#define NETWORKSTREAMINPUTDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include "CustomTextInput.h"

class NetworkStreamInputDialog : public QDialog
{
    Q_OBJECT
private:
    QGridLayout* _layout;
    CustomTextInput _url;


public:
    explicit NetworkStreamInputDialog(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // NETWORKSTREAMINPUTDIALOG_H
