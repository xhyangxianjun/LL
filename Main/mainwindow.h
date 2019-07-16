#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Controls/framelesswidget.h"

class MainWindow : public FrameLessWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createWg();

};

#endif // MAINWINDOW_H
