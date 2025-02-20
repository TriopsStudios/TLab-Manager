#ifndef ADDSAMPLEWINDOW_H
#define ADDSAMPLEWINDOW_H

#include <QMainWindow>
#include "labmanager.h"

namespace Ui {
class AddSampleWindow;
}

class AddSampleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSampleWindow(QWidget *parent = nullptr, LabManager* labmanager = nullptr);
    ~AddSampleWindow();

private slots:
    void on_aadirButton_clicked();

private:
    Ui::AddSampleWindow *ui;
    LabManager* _labmanager;
};

#endif // ADDSAMPLEWINDOW_H
