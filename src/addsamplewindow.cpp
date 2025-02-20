#include "addsamplewindow.h"
#include "ui_addsamplewindow.h"


AddSampleWindow::AddSampleWindow(QWidget *parent, LabManager* labmanager)
    : QMainWindow(parent)
    , ui(new Ui::AddSampleWindow)
    , _labmanager(labmanager)

{
    ui->setupUi(this);
    this->setWindowTitle("Add sample");

}

AddSampleWindow::~AddSampleWindow()
{
    delete ui;
}

void AddSampleWindow::on_aadirButton_clicked()
{
    _labmanager->nombreAnalistaSet(ui->analistaLine->text());
    _labmanager->fechaSet(ui->fechaLine->text());
    _labmanager->nombreMuestraSet(ui->sampleLine->text());
    _labmanager->analisisAerobiosMSet(ui->aerobiosMCheck->isChecked());
    _labmanager->analisisEnterobacteriasSet(ui->enterobacteriasCheck->isChecked());
    _labmanager->comentarioSet(ui->comentarioLine->text());
    _labmanager->AnadirMuestra();

    this->close();
}

