/********************************************************************************
** Form generated from reading UI file 'labmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABMANAGER_H
#define UI_LABMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabManager
{
public:
    QAction *actionA_adir_muestra;
    QAction *actionBorrar_datos;
    QAction *actionGuardar_datos;
    QAction *actionAcerca_de;
    QAction *actionBorrar_filas;
    QWidget *centralwidget;
    QTableView *tablaPrincipal;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *anadirMuetraPButton;
    QPushButton *guardarPButton;
    QPushButton *borrarFilasPButton;
    QPushButton *eliminarTablaPButton;
    QLabel *label;
    QComboBox *filtroBox;
    QLineEdit *filtroLine;
    QPushButton *pushButton;
    QPushButton *borrarFiltroPButton;
    QMenuBar *menubar;
    QMenu *menuPaciente;
    QMenu *menuTabla;
    QMenu *menuAyuda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LabManager)
    {
        if (LabManager->objectName().isEmpty())
            LabManager->setObjectName("LabManager");
        LabManager->resize(1203, 672);
        actionA_adir_muestra = new QAction(LabManager);
        actionA_adir_muestra->setObjectName("actionA_adir_muestra");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/Images/Icons/fileIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionA_adir_muestra->setIcon(icon);
        actionBorrar_datos = new QAction(LabManager);
        actionBorrar_datos->setObjectName("actionBorrar_datos");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/Images/Icons/deleteIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBorrar_datos->setIcon(icon1);
        actionGuardar_datos = new QAction(LabManager);
        actionGuardar_datos->setObjectName("actionGuardar_datos");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/Images/Icons/saveIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionGuardar_datos->setIcon(icon2);
        actionAcerca_de = new QAction(LabManager);
        actionAcerca_de->setObjectName("actionAcerca_de");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/Images/Icons/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAcerca_de->setIcon(icon3);
        actionBorrar_filas = new QAction(LabManager);
        actionBorrar_filas->setObjectName("actionBorrar_filas");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/Images/Icons/deleteRowIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBorrar_filas->setIcon(icon4);
        centralwidget = new QWidget(LabManager);
        centralwidget->setObjectName("centralwidget");
        tablaPrincipal = new QTableView(centralwidget);
        tablaPrincipal->setObjectName("tablaPrincipal");
        tablaPrincipal->setGeometry(QRect(10, 50, 1181, 571));
        tablaPrincipal->setFrameShape(QFrame::Shape::StyledPanel);
        tablaPrincipal->setFrameShadow(QFrame::Shadow::Sunken);
        tablaPrincipal->setGridStyle(Qt::PenStyle::SolidLine);
        tablaPrincipal->setSortingEnabled(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 0, 351, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        anadirMuetraPButton = new QPushButton(layoutWidget);
        anadirMuetraPButton->setObjectName("anadirMuetraPButton");
        anadirMuetraPButton->setIcon(icon);
        anadirMuetraPButton->setIconSize(QSize(32, 32));
        anadirMuetraPButton->setFlat(true);

        horizontalLayout->addWidget(anadirMuetraPButton);

        guardarPButton = new QPushButton(layoutWidget);
        guardarPButton->setObjectName("guardarPButton");
        guardarPButton->setIcon(icon2);
        guardarPButton->setIconSize(QSize(32, 32));
        guardarPButton->setFlat(true);

        horizontalLayout->addWidget(guardarPButton);

        borrarFilasPButton = new QPushButton(layoutWidget);
        borrarFilasPButton->setObjectName("borrarFilasPButton");
        borrarFilasPButton->setIcon(icon4);
        borrarFilasPButton->setIconSize(QSize(32, 32));
        borrarFilasPButton->setFlat(true);

        horizontalLayout->addWidget(borrarFilasPButton);

        eliminarTablaPButton = new QPushButton(layoutWidget);
        eliminarTablaPButton->setObjectName("eliminarTablaPButton");
        eliminarTablaPButton->setIcon(icon1);
        eliminarTablaPButton->setIconSize(QSize(32, 32));
        eliminarTablaPButton->setFlat(true);

        horizontalLayout->addWidget(eliminarTablaPButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 10, 81, 21));
        filtroBox = new QComboBox(centralwidget);
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->addItem(QString());
        filtroBox->setObjectName("filtroBox");
        filtroBox->setGeometry(QRect(540, 10, 191, 22));
        filtroLine = new QLineEdit(centralwidget);
        filtroLine->setObjectName("filtroLine");
        filtroLine->setGeometry(QRect(740, 10, 113, 22));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(860, 10, 75, 24));
        borrarFiltroPButton = new QPushButton(centralwidget);
        borrarFiltroPButton->setObjectName("borrarFiltroPButton");
        borrarFiltroPButton->setGeometry(QRect(940, 10, 75, 24));
        LabManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LabManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1203, 22));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(148, 253, 255, 100));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(84, 252, 255, 100));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(10, 125, 127, 100));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(14, 167, 170, 100));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(21, 251, 255, 100));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush8(QColor(138, 253, 255, 177));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(0, 0, 0, 127));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush11(QColor(10, 125, 127, 50));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        QBrush brush12(QColor(97, 252, 255, 100));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush12);
        menubar->setPalette(palette);
        menubar->setAutoFillBackground(true);
        menubar->setNativeMenuBar(true);
        menuPaciente = new QMenu(menubar);
        menuPaciente->setObjectName("menuPaciente");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::CallStop));
        menuPaciente->setIcon(icon5);
        menuTabla = new QMenu(menubar);
        menuTabla->setObjectName("menuTabla");
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName("menuAyuda");
        LabManager->setMenuBar(menubar);
        statusbar = new QStatusBar(LabManager);
        statusbar->setObjectName("statusbar");
        LabManager->setStatusBar(statusbar);

        menubar->addAction(menuPaciente->menuAction());
        menubar->addAction(menuTabla->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuPaciente->addAction(actionA_adir_muestra);
        menuTabla->addAction(actionGuardar_datos);
        menuTabla->addSeparator();
        menuTabla->addAction(actionBorrar_filas);
        menuTabla->addAction(actionBorrar_datos);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(LabManager);

        QMetaObject::connectSlotsByName(LabManager);
    } // setupUi

    void retranslateUi(QMainWindow *LabManager)
    {
        LabManager->setWindowTitle(QCoreApplication::translate("LabManager", "LabManager", nullptr));
        actionA_adir_muestra->setText(QCoreApplication::translate("LabManager", "A\303\261adir muestra", nullptr));
        actionBorrar_datos->setText(QCoreApplication::translate("LabManager", "Borrar datos", nullptr));
        actionGuardar_datos->setText(QCoreApplication::translate("LabManager", "Guardar datos", nullptr));
        actionAcerca_de->setText(QCoreApplication::translate("LabManager", "Acerca de...", nullptr));
        actionBorrar_filas->setText(QCoreApplication::translate("LabManager", "Borrar filas", nullptr));
        anadirMuetraPButton->setText(QCoreApplication::translate("LabManager", "A\303\261adir \n"
"muestra", nullptr));
        guardarPButton->setText(QCoreApplication::translate("LabManager", "Guardar", nullptr));
        borrarFilasPButton->setText(QCoreApplication::translate("LabManager", "Borrar\n"
"filas", nullptr));
        eliminarTablaPButton->setText(QCoreApplication::translate("LabManager", "Borrar\n"
"tabla", nullptr));
        label->setText(QCoreApplication::translate("LabManager", "Filtrar por", nullptr));
        filtroBox->setItemText(0, QCoreApplication::translate("LabManager", "ID", nullptr));
        filtroBox->setItemText(1, QCoreApplication::translate("LabManager", "Analista", nullptr));
        filtroBox->setItemText(2, QCoreApplication::translate("LabManager", "Fecha", nullptr));
        filtroBox->setItemText(3, QCoreApplication::translate("LabManager", "Muestra", nullptr));
        filtroBox->setItemText(4, QCoreApplication::translate("LabManager", "An\303\241lisis Enterobacterias", nullptr));
        filtroBox->setItemText(5, QCoreApplication::translate("LabManager", "Recuento Enterobacterias", nullptr));
        filtroBox->setItemText(6, QCoreApplication::translate("LabManager", "An\303\241lisis Aerobios mes\303\263filos", nullptr));
        filtroBox->setItemText(7, QCoreApplication::translate("LabManager", "Recuento Aerobios mes\303\263filos", nullptr));
        filtroBox->setItemText(8, QCoreApplication::translate("LabManager", "Comentario", nullptr));

        pushButton->setText(QCoreApplication::translate("LabManager", "Filtrar", nullptr));
        borrarFiltroPButton->setText(QCoreApplication::translate("LabManager", "Borrar filtro", nullptr));
        menuPaciente->setTitle(QCoreApplication::translate("LabManager", "Muestra", nullptr));
        menuTabla->setTitle(QCoreApplication::translate("LabManager", "Tabla", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("LabManager", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LabManager: public Ui_LabManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABMANAGER_H
