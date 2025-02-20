/********************************************************************************
** Form generated from reading UI file 'addsamplewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSAMPLEWINDOW_H
#define UI_ADDSAMPLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSampleWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *analistaLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *fechaLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *comentarioLine;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *sampleLine;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QCheckBox *enterobacteriasCheck;
    QCheckBox *aerobiosMCheck;
    QPushButton *aadirButton;

    void setupUi(QMainWindow *AddSampleWindow)
    {
        if (AddSampleWindow->objectName().isEmpty())
            AddSampleWindow->setObjectName("AddSampleWindow");
        AddSampleWindow->resize(688, 251);
        centralwidget = new QWidget(AddSampleWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        analistaLine = new QLineEdit(centralwidget);
        analistaLine->setObjectName("analistaLine");

        horizontalLayout_3->addWidget(analistaLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        fechaLine = new QLineEdit(centralwidget);
        fechaLine->setObjectName("fechaLine");

        horizontalLayout_2->addWidget(fechaLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        comentarioLine = new QLineEdit(centralwidget);
        comentarioLine->setObjectName("comentarioLine");

        horizontalLayout_4->addWidget(comentarioLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        sampleLine = new QLineEdit(centralwidget);
        sampleLine->setObjectName("sampleLine");

        horizontalLayout->addWidget(sampleLine);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        enterobacteriasCheck = new QCheckBox(centralwidget);
        enterobacteriasCheck->setObjectName("enterobacteriasCheck");

        horizontalLayout_5->addWidget(enterobacteriasCheck);

        aerobiosMCheck = new QCheckBox(centralwidget);
        aerobiosMCheck->setObjectName("aerobiosMCheck");

        horizontalLayout_5->addWidget(aerobiosMCheck);


        verticalLayout_2->addLayout(horizontalLayout_5);

        aadirButton = new QPushButton(centralwidget);
        aadirButton->setObjectName("aadirButton");

        verticalLayout_2->addWidget(aadirButton);

        AddSampleWindow->setCentralWidget(centralwidget);

        retranslateUi(AddSampleWindow);

        QMetaObject::connectSlotsByName(AddSampleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddSampleWindow)
    {
        AddSampleWindow->setWindowTitle(QCoreApplication::translate("AddSampleWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("AddSampleWindow", "Analista", nullptr));
        label_3->setText(QCoreApplication::translate("AddSampleWindow", "Fecha    ", nullptr));
        label_5->setText(QCoreApplication::translate("AddSampleWindow", "Comentario", nullptr));
        label->setText(QCoreApplication::translate("AddSampleWindow", "Nombre de muestra", nullptr));
        label_2->setText(QCoreApplication::translate("AddSampleWindow", "An\303\241lisis realizados", nullptr));
        enterobacteriasCheck->setText(QCoreApplication::translate("AddSampleWindow", "Enterobacterias", nullptr));
        aerobiosMCheck->setText(QCoreApplication::translate("AddSampleWindow", "Aerobios mes\303\263filos", nullptr));
        aadirButton->setText(QCoreApplication::translate("AddSampleWindow", "A\303\261adir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSampleWindow: public Ui_AddSampleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSAMPLEWINDOW_H
