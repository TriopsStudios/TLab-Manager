#include "labmanager.h"
#include "./ui_labmanager.h"
#include "addsamplewindow.h"
LabManager::LabManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LabManager)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db/lab.db");


    if(!db.open()){


        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(tr("Error: No se pudo conectar a la base de datos. Labmanager linea: 18"));
        msgBox.setInformativeText(db.lastError().text());
        msgBox.setWindowTitle("Error de conexión con base de datos");
        msgBox.exec();


    }
    else{
    tM = new QSqlTableModel(this, db);
    tM->setTable("main");
    tM->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!tM->select()){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error: Model Select Error. Labmanager linea: 32");
        msgBox.setInformativeText(tM->lastError().text());
        msgBox.setWindowTitle("Error al mostrar tabla de datos");
        msgBox.exec();


    }

    tM->setHeaderData(4, Qt::Horizontal, "Analisis Enterobacterias");

    tM->setHeaderData(5, Qt::Horizontal, "Recuento Enterobacterias");

    tM->setHeaderData(6, Qt::Horizontal, "Analisis Aerobios mesófilos");

    tM->setHeaderData(7, Qt::Horizontal, "Recuento Aerobios mesófilos");

    ui->tablaPrincipal->setModel(tM);
    }



}

LabManager::~LabManager()
{
    delete ui;


    db.close();

}



void LabManager::on_actionA_adir_muestra_triggered()
{
    AddSampleWindow* ventanaMuestras = new AddSampleWindow(nullptr, this);
    ventanaMuestras->show();

}


void LabManager::on_anadirMuetraPButton_clicked()
{
    AddSampleWindow* ventanaMuestras = new AddSampleWindow(nullptr, this);
    ventanaMuestras->show();
}

void LabManager::AnadirMuestra(){

    QSqlQuery query(db);
    if(query.prepare("INSERT INTO main (Muestra, Fecha, Analista, Enterobacterias, AerobiosM, Comentario) VALUES (:muestra, :fecha, :analista, :enterobacterias, :aerobiosM, :comentario)")){
    query.bindValue(":muestra", nombreMuestra);
    query.bindValue(":fecha", fecha);
    query.bindValue(":analista", nombreAnalista);
    if(analisisEnterobacterias==true){
    query.bindValue(":enterobacterias", "Sí");
    }
    else query.bindValue(":enterobacterias", "No");

    if(analisisAerobiosM==true){
    query.bindValue(":aerobiosM", "Sí");
    }
    else query.bindValue(":aerobiosM", "No");
    query.bindValue(":comentario", comentario);
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error en prepare. Labmanager linea: 101");
        msgBox.setInformativeText(query.lastError().text());
        msgBox.setWindowTitle("Error SQLite");
        msgBox.exec();
    }

    // Ejecuta la consulta
    if (!query.exec()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error al insertar datos. Labmanager linea: 111");
        msgBox.setInformativeText(query.lastError().text());
        msgBox.setWindowTitle("Error SQLite");
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Exito al insertar datos");

        msgBox.setWindowTitle("Exito");
        msgBox.exec();
    }

    tM->select();

}

void LabManager::analisisAerobiosMSet(const bool set){
    analisisAerobiosM = set;
}

void LabManager::analisisEnterobacteriasSet(const bool set){
    analisisEnterobacterias = set;
}


void LabManager::nombreMuestraSet(const QString text){
    nombreMuestra = text;
}

void LabManager::nombreAnalistaSet(const QString text){
    nombreAnalista = text;
}

QString LabManager::nombreAnalistaGet(){
    return nombreAnalista;
}

void LabManager::fechaSet(QString text){
    fecha = text;
}

void LabManager::comentarioSet(const QString text){
    comentario = text;
}



void LabManager::on_actionBorrar_datos_triggered()
{
    if(QMessageBox::question(this, "Borrar", "Confirmar borrado de tabla",
                              QMessageBox::Yes| QMessageBox::No)==QMessageBox::Yes){
     QSqlQuery query(db);
    if(query.prepare("DELETE FROM main")){
         if(query.exec()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Exito al borrar datos de tabla");

            msgBox.setWindowTitle("Exito");
            msgBox.exec();
         }
         else{
             QMessageBox msgBox;
             msgBox.setIcon(QMessageBox::Critical);
             msgBox.setText("Error en query.exec al borrar datos. Labmanager linea: 176");
             msgBox.setInformativeText(query.lastError().text());
             msgBox.setWindowTitle("Error SQLite");
             msgBox.exec();
         }

    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error en query.prepare al borrar datos. Labmanager linea: 186");
        msgBox.setInformativeText(query.lastError().text());
        msgBox.setWindowTitle("Error SQLite");
        msgBox.exec();
    }
    tM->select();
    }
}


void LabManager::on_eliminarTablaPButton_clicked()
{
    on_actionBorrar_datos_triggered();
}

bool LabManager::analisisAerobiosMGet(){
    return analisisAerobiosM;
}

bool LabManager::analisisEnterobacteriasGet(){
    return analisisEnterobacterias;
}




void LabManager::on_actionGuardar_datos_triggered()
{
    if(QMessageBox::question(this, "Guardar", "Confirmar guardado de datos",
                              QMessageBox::Yes| QMessageBox::No)==QMessageBox::Yes){

        QModelIndexList selection = ui->tablaPrincipal->selectionModel()->selectedRows(); //Ver que filas estan seleccionadas
        if(selection.isEmpty()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("No se han seleccionado filas para guardar");

            msgBox.setWindowTitle("Sin selección");
            msgBox.exec();
        }
        else{
            QSqlQuery query(db);
            QVariant idData;

            int row = 0;
            for(int i=0; i<selection.size();i++){
                row = selection.at(i).row();
                idData = tM->data(tM->index(row, 0));



                if(query.prepare("UPDATE main SET Muestra = :muestra, Fecha = :fecha, Analista = :analista, Enterobacterias = :enterobacterias, AerobiosM = :aerobiosM, Comentario = :comentario, RecuentoEnterobacterias = :rEnterobacterias, RecuentoAerobiosM = :rAerobiosM WHERE ID = :id")){
                    query.bindValue(":id", idData.toInt());
                    query.bindValue(":muestra", tM->data(tM->index(row, 1)).toString());
                    query.bindValue(":fecha", tM->data(tM->index(row, 2)).toString());
                    query.bindValue(":analista", tM->data(tM->index(row, 3)).toString());
                    idData = tM->data(tM->index(row, 4));
                    if(idData.toString()=="Sí"){
                        query.bindValue(":enterobacterias", "Sí");
                        query.bindValue(":rEnterobacterias", tM->data(tM->index(row, 5)).toInt());
                    }
                    else query.bindValue(":enterobacterias", "No");
                    idData = tM->data(tM->index(row, 6));
                    if(idData.toString()=="Sí"){
                        query.bindValue(":aerobiosM", "Sí");
                        query.bindValue(":rAerobiosM", tM->data(tM->index(row, 7)).toInt());
                    }
                    else query.bindValue(":aerobiosM", "No");
                    query.bindValue(":comentario", tM->data(tM->index(row, 8)).toString());
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error en prepare. Labmanager linea: 259");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }

                // Ejecuta la consulta
                if (!query.exec()) {
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error al insertar datos. Labmanager linea: 269");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }


            }
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Exito al insertar datos");

            msgBox.setWindowTitle("Exito");
            msgBox.exec();

        }
    }
}


void LabManager::on_actionAcerca_de_triggered()
{
    QMessageBox acercaDe;
    acercaDe.setIcon(QMessageBox::Information);
    acercaDe.setText("TLabManager \nPor Triops Studios 2025 \nProgramado por Alejandro martinez (alemartinezman@gmail.com) \nIconos de www.icons8.com");

    acercaDe.setWindowTitle("Acerca de...");
    acercaDe.exec();
}


void LabManager::on_guardarPButton_clicked()
{
    if(QMessageBox::question(this, "Guardar", "Confirmar guardado de datos",
                              QMessageBox::Yes| QMessageBox::No)==QMessageBox::Yes){

        QModelIndexList selection = ui->tablaPrincipal->selectionModel()->selectedRows(); //Ver que filas estan seleccionadas
        if(selection.isEmpty()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("No se han seleccionado filas para guardar");

            msgBox.setWindowTitle("Sin selección");
            msgBox.exec();
        }
        else{
            QSqlQuery query(db);
            QVariant idData;

            int row = 0;
            for(int i=0; i<selection.size();i++){
                row = selection.at(i).row();
                idData = tM->data(tM->index(row, 0));



                if(query.prepare("UPDATE main SET Muestra = :muestra, Fecha = :fecha, Analista = :analista, Enterobacterias = :enterobacterias, AerobiosM = :aerobiosM, Comentario = :comentario, RecuentoEnterobacterias = :rEnterobacterias, RecuentoAerobiosM = :rAerobiosM WHERE ID = :id")){
                    query.bindValue(":id", idData.toInt());
                    query.bindValue(":muestra", tM->data(tM->index(row, 1)).toString());
                    query.bindValue(":fecha", tM->data(tM->index(row, 2)).toString());
                    query.bindValue(":analista", tM->data(tM->index(row, 3)).toString());
                    idData = tM->data(tM->index(row, 4));
                    if(idData.toString()=="Sí"){
                        query.bindValue(":enterobacterias", "Sí");
                        query.bindValue(":rEnterobacterias", tM->data(tM->index(row, 5)).toInt());
                    }
                    else query.bindValue(":enterobacterias", "No");
                    idData = tM->data(tM->index(row, 6));
                    if(idData.toString()=="Sí"){
                        query.bindValue(":aerobiosM", "Sí");
                        query.bindValue(":rAerobiosM", tM->data(tM->index(row, 7)).toInt());
                    }
                    else query.bindValue(":aerobiosM", "No");
                    query.bindValue(":comentario", tM->data(tM->index(row, 8)).toString());
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error en prepare");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }

                // Ejecuta la consulta
                if (!query.exec()) {
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error al insertar datos");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }


            }
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Exito al insertar datos");

            msgBox.setWindowTitle("Exito");
            msgBox.exec();

        }
    }
    tM->select();
}


void LabManager::on_actionBorrar_filas_triggered()
{
    if(QMessageBox::question(this, "Borrar", "Confirmar borrado de datos",
                              QMessageBox::Yes| QMessageBox::No)==QMessageBox::Yes){

        QModelIndexList selection = ui->tablaPrincipal->selectionModel()->selectedRows(); //Ver que filas estan seleccionadas
        if(selection.isEmpty()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("No se han seleccionado filas para guardar");

            msgBox.setWindowTitle("Sin selección");
            msgBox.exec();
        }
        else{
            QSqlQuery query(db);
            QVariant idData;

            int row = 0;
            for(int i=0; i<selection.size();i++){
                row = selection.at(i).row();
                idData = tM->data(tM->index(row, 0));



                if(query.prepare("DELETE FROM main WHERE ID = :id")){
                    query.bindValue(":id", idData.toInt());
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error en prepare");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }

                // Ejecuta la consulta
                if (!query.exec()) {
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error al borrar datos");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }


            }
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Exito al borrar datos datos");

            msgBox.setWindowTitle("Exito");
            msgBox.exec();
            tM->select();

        }
    }
}


void LabManager::on_pushButton_clicked()
{
    QSqlQuery query;
    QString opcionBusqueda = ui->filtroBox->currentText();
    if(opcionBusqueda == "Recuento Enterobacterias" &&  ui->filtroLine->text() != "" ){

        int valor = ui->filtroLine->text().toInt();

        query.prepare("SELECT * FROM main WHERE RecuentoEnterobacterias = :valor");
        query.bindValue(":valor", valor);
        if (!query.exec()) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Error al filtrar datos");
            msgBox.setInformativeText(query.lastError().text());
            msgBox.setWindowTitle("Error SQLite");
            msgBox.exec();
        }
        else{
            tM->setQuery(std::move(query));

        }

    }
    else if(opcionBusqueda == "Recuento Aerobios mesófilos" &&  ui->filtroLine->text() != "" ){

        int valor = ui->filtroLine->text().toInt();

        query.prepare("SELECT * FROM main WHERE RecuentoAerobiosM = :valor");
        query.bindValue(":valor", valor);
        if (!query.exec()) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Error al filtrar datos");
            msgBox.setInformativeText(query.lastError().text());
            msgBox.setWindowTitle("Error SQLite");
            msgBox.exec();
        }
        else{
            tM->setQuery(std::move(query));

        }

    }
    else{
        QString valor = ui->filtroLine->text();
        QString consulta = QString("SELECT * FROM main WHERE %1 = :valor").arg(opcionBusqueda);
        query.prepare(consulta);
        query.bindValue(":opcionBusqueda", opcionBusqueda);
        query.bindValue(":valor", valor);
        if (!query.exec()) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Error al filtrar datos");
            msgBox.setInformativeText(query.lastError().text());
            msgBox.setWindowTitle("Error SQLite");
            msgBox.exec();
        }
        else{
            tM->setQuery(std::move(query));

        }

    }
}



void LabManager::on_borrarFiltroPButton_clicked()
{
    QSqlQuery query;


    query.prepare("SELECT * FROM main");

    if (!query.exec()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error al desfiltrar");
        msgBox.setInformativeText(query.lastError().text());
        msgBox.setWindowTitle("Error SQLite");
        msgBox.exec();
    }
    else{
        tM->setQuery(std::move(query));

    }
}



void LabManager::on_borrarFilasPButton_clicked()
{
    if(QMessageBox::question(this, "Borrar", "Confirmar borrado de datos",
                              QMessageBox::Yes| QMessageBox::No)==QMessageBox::Yes){

        QModelIndexList selection = ui->tablaPrincipal->selectionModel()->selectedRows(); //Ver que filas estan seleccionadas
        if(selection.isEmpty()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("No se han seleccionado filas para guardar");

            msgBox.setWindowTitle("Sin selección");
            msgBox.exec();
        }
        else{
            QSqlQuery query(db);
            QVariant idData;

            int row = 0;
            for(int i=0; i<selection.size();i++){
                row = selection.at(i).row();
                idData = tM->data(tM->index(row, 0));



                if(query.prepare("DELETE FROM main WHERE ID = :id")){
                    query.bindValue(":id", idData.toInt());
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error en prepare");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }

                // Ejecuta la consulta
                if (!query.exec()) {
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Error al borrar datos");
                    msgBox.setInformativeText(query.lastError().text());
                    msgBox.setWindowTitle("Error SQLite");
                    msgBox.exec();
                }


            }
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Exito al borrar datos datos");

            msgBox.setWindowTitle("Exito");
            msgBox.exec();
            tM->select();

        }
    }
}

