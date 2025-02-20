#ifndef LABMANAGER_H
#define LABMANAGER_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <string>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class LabManager;
}
QT_END_NAMESPACE

class LabManager : public QMainWindow
{
    Q_OBJECT

public:
    LabManager(QWidget *parent = nullptr);
    ~LabManager();
    void AnadirMuestra();
    void nombreMuestraSet(const QString text);
    void nombreAnalistaSet(const QString text);
    void fechaSet(const QString text);
    void analisisAerobiosMSet(const bool set);
    void analisisEnterobacteriasSet(const bool set);
    void comentarioSet(const QString text);


    QString nombreAnalistaGet();
    bool analisisAerobiosMGet();
    bool analisisEnterobacteriasGet();


private slots:
    void on_actionA_adir_muestra_triggered();



    void on_anadirMuetraPButton_clicked();

    void on_actionBorrar_datos_triggered();

    void on_eliminarTablaPButton_clicked();

    void on_actionGuardar_datos_triggered();

    void on_actionAcerca_de_triggered();

    void on_guardarPButton_clicked();

    void on_actionBorrar_filas_triggered();

    void on_pushButton_clicked();

    void on_borrarFiltroPButton_clicked();

    void on_borrarFilasPButton_clicked();

private:
    Ui::LabManager *ui;

    QSqlDatabase db;
    QSqlTableModel *tM = nullptr;


    QString nombreMuestra;
    QString nombreAnalista;
    QString fecha;
    QString comentario;

    bool analisisEnterobacterias;
    bool analisisAerobiosM;
};
#endif // LABMANAGER_H

