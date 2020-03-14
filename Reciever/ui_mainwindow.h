/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SendpushButton;
    QCheckBox *StatusPacket;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *clearresppushButton;
    QPushButton *clearrequestpushButton;
    QTextEdit *requesttextEdit;
    QTextEdit *responsetextEdit;
    QGroupBox *ControlGroupBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *ReadradioButton;
    QRadioButton *WriteradioButton;
    QRadioButton *NIRradioButton;
    QRadioButton *NIWradioButton;
    QRadioButton *RMWBradioButton;
    QRadioButton *RMWSradioButton;
    QFormLayout *formLayout;
    QLabel *BaseAdresslabel;
    QLineEdit *BaseAdresslineEdit;
    QLabel *Wordslabel;
    QLineEdit *WordslineEdit;
    QLabel *ANDlabel;
    QLineEdit *ANDlineEdit;
    QLabel *ORlabel;
    QLineEdit *ORlineEdit;
    QLabel *ADDENDlabel;
    QLineEdit *ADDENDlineEdit;
    QLabel *label_5;
    QCheckBox *BitOrdercheckBox;
    QCheckBox *OwnIDcheckBox;
    QLineEdit *EnterIDlineEdit;
    QGroupBox *ReSendGroupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditID;
    QLabel *TransactionsCounterlabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddTransactionpushButton;
    QLCDNumber *lcdNumbertrans;
    QPushButton *pushButtonMoreWords;
    QLabel *labelDemo;
    QPushButton *pushButtonMoreWords_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(670, 751);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SendpushButton = new QPushButton(centralwidget);
        SendpushButton->setObjectName(QString::fromUtf8("SendpushButton"));
        SendpushButton->setGeometry(QRect(490, 678, 171, 27));
        StatusPacket = new QCheckBox(centralwidget);
        StatusPacket->setObjectName(QString::fromUtf8("StatusPacket"));
        StatusPacket->setGeometry(QRect(511, 0, 131, 24));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 230, 411, 481));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 20));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(100, 20));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_2);

        clearresppushButton = new QPushButton(layoutWidget);
        clearresppushButton->setObjectName(QString::fromUtf8("clearresppushButton"));
        clearresppushButton->setMinimumSize(QSize(200, 0));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, clearresppushButton);

        clearrequestpushButton = new QPushButton(layoutWidget);
        clearrequestpushButton->setObjectName(QString::fromUtf8("clearrequestpushButton"));
        clearrequestpushButton->setMinimumSize(QSize(200, 0));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, clearrequestpushButton);

        requesttextEdit = new QTextEdit(layoutWidget);
        requesttextEdit->setObjectName(QString::fromUtf8("requesttextEdit"));
        requesttextEdit->setMinimumSize(QSize(200, 400));
        requesttextEdit->setMaximumSize(QSize(200, 400));
        requesttextEdit->setFrameShape(QFrame::Box);
        requesttextEdit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, requesttextEdit);

        responsetextEdit = new QTextEdit(layoutWidget);
        responsetextEdit->setObjectName(QString::fromUtf8("responsetextEdit"));
        responsetextEdit->setMaximumSize(QSize(200, 400));
        responsetextEdit->setFrameShape(QFrame::Box);
        responsetextEdit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, responsetextEdit);

        ControlGroupBox = new QGroupBox(centralwidget);
        ControlGroupBox->setObjectName(QString::fromUtf8("ControlGroupBox"));
        ControlGroupBox->setGeometry(QRect(10, 0, 471, 231));
        ControlGroupBox->setCheckable(true);
        ControlGroupBox->setChecked(false);
        horizontalLayout = new QHBoxLayout(ControlGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(ControlGroupBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ReadradioButton = new QRadioButton(groupBox);
        ReadradioButton->setObjectName(QString::fromUtf8("ReadradioButton"));

        verticalLayout->addWidget(ReadradioButton);

        WriteradioButton = new QRadioButton(groupBox);
        WriteradioButton->setObjectName(QString::fromUtf8("WriteradioButton"));

        verticalLayout->addWidget(WriteradioButton);

        NIRradioButton = new QRadioButton(groupBox);
        NIRradioButton->setObjectName(QString::fromUtf8("NIRradioButton"));

        verticalLayout->addWidget(NIRradioButton);

        NIWradioButton = new QRadioButton(groupBox);
        NIWradioButton->setObjectName(QString::fromUtf8("NIWradioButton"));

        verticalLayout->addWidget(NIWradioButton);

        RMWBradioButton = new QRadioButton(groupBox);
        RMWBradioButton->setObjectName(QString::fromUtf8("RMWBradioButton"));

        verticalLayout->addWidget(RMWBradioButton);

        RMWSradioButton = new QRadioButton(groupBox);
        RMWSradioButton->setObjectName(QString::fromUtf8("RMWSradioButton"));

        verticalLayout->addWidget(RMWSradioButton);


        horizontalLayout->addWidget(groupBox);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        BaseAdresslabel = new QLabel(ControlGroupBox);
        BaseAdresslabel->setObjectName(QString::fromUtf8("BaseAdresslabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, BaseAdresslabel);

        BaseAdresslineEdit = new QLineEdit(ControlGroupBox);
        BaseAdresslineEdit->setObjectName(QString::fromUtf8("BaseAdresslineEdit"));
        BaseAdresslineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Source Code Pro\";"));
        BaseAdresslineEdit->setDragEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, BaseAdresslineEdit);

        Wordslabel = new QLabel(ControlGroupBox);
        Wordslabel->setObjectName(QString::fromUtf8("Wordslabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Wordslabel);

        WordslineEdit = new QLineEdit(ControlGroupBox);
        WordslineEdit->setObjectName(QString::fromUtf8("WordslineEdit"));
        WordslineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Source Code Pro\";"));

        formLayout->setWidget(1, QFormLayout::FieldRole, WordslineEdit);

        ANDlabel = new QLabel(ControlGroupBox);
        ANDlabel->setObjectName(QString::fromUtf8("ANDlabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ANDlabel);

        ANDlineEdit = new QLineEdit(ControlGroupBox);
        ANDlineEdit->setObjectName(QString::fromUtf8("ANDlineEdit"));
        ANDlineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Source Code Pro\";"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ANDlineEdit);

        ORlabel = new QLabel(ControlGroupBox);
        ORlabel->setObjectName(QString::fromUtf8("ORlabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ORlabel);

        ORlineEdit = new QLineEdit(ControlGroupBox);
        ORlineEdit->setObjectName(QString::fromUtf8("ORlineEdit"));
        ORlineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Source Code Pro\";"));

        formLayout->setWidget(3, QFormLayout::FieldRole, ORlineEdit);

        ADDENDlabel = new QLabel(ControlGroupBox);
        ADDENDlabel->setObjectName(QString::fromUtf8("ADDENDlabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, ADDENDlabel);

        ADDENDlineEdit = new QLineEdit(ControlGroupBox);
        ADDENDlineEdit->setObjectName(QString::fromUtf8("ADDENDlineEdit"));
        ADDENDlineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Source Code Pro\";"));

        formLayout->setWidget(4, QFormLayout::FieldRole, ADDENDlineEdit);

        label_5 = new QLabel(ControlGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        BitOrdercheckBox = new QCheckBox(ControlGroupBox);
        BitOrdercheckBox->setObjectName(QString::fromUtf8("BitOrdercheckBox"));

        formLayout->setWidget(5, QFormLayout::LabelRole, BitOrdercheckBox);

        OwnIDcheckBox = new QCheckBox(ControlGroupBox);
        OwnIDcheckBox->setObjectName(QString::fromUtf8("OwnIDcheckBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, OwnIDcheckBox);

        EnterIDlineEdit = new QLineEdit(ControlGroupBox);
        EnterIDlineEdit->setObjectName(QString::fromUtf8("EnterIDlineEdit"));
        EnterIDlineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"Source Code Pro\";"));

        formLayout->setWidget(6, QFormLayout::FieldRole, EnterIDlineEdit);


        horizontalLayout->addLayout(formLayout);

        ReSendGroupBox = new QGroupBox(centralwidget);
        ReSendGroupBox->setObjectName(QString::fromUtf8("ReSendGroupBox"));
        ReSendGroupBox->setGeometry(QRect(510, 30, 141, 91));
        ReSendGroupBox->setCheckable(true);
        ReSendGroupBox->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(ReSendGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(ReSendGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        lineEditID = new QLineEdit(ReSendGroupBox);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));

        verticalLayout_2->addWidget(lineEditID);

        TransactionsCounterlabel = new QLabel(centralwidget);
        TransactionsCounterlabel->setObjectName(QString::fromUtf8("TransactionsCounterlabel"));
        TransactionsCounterlabel->setGeometry(QRect(490, 120, 181, 61));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(490, 180, 152, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        AddTransactionpushButton = new QPushButton(layoutWidget1);
        AddTransactionpushButton->setObjectName(QString::fromUtf8("AddTransactionpushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddTransactionpushButton->sizePolicy().hasHeightForWidth());
        AddTransactionpushButton->setSizePolicy(sizePolicy);
        AddTransactionpushButton->setMinimumSize(QSize(30, 30));
        AddTransactionpushButton->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(AddTransactionpushButton);

        lcdNumbertrans = new QLCDNumber(layoutWidget1);
        lcdNumbertrans->setObjectName(QString::fromUtf8("lcdNumbertrans"));

        horizontalLayout_2->addWidget(lcdNumbertrans);

        pushButtonMoreWords = new QPushButton(centralwidget);
        pushButtonMoreWords->setObjectName(QString::fromUtf8("pushButtonMoreWords"));
        pushButtonMoreWords->setGeometry(QRect(470, 270, 131, 61));
        QPalette palette;
        QBrush brush(QColor(204, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButtonMoreWords->setPalette(palette);
        pushButtonMoreWords->setStyleSheet(QString::fromUtf8("font: 8pt \"DejaVu Sans\";"));
        pushButtonMoreWords->setAutoDefault(false);
        pushButtonMoreWords->setFlat(false);
        labelDemo = new QLabel(centralwidget);
        labelDemo->setObjectName(QString::fromUtf8("labelDemo"));
        labelDemo->setGeometry(QRect(440, 240, 171, 18));
        pushButtonMoreWords_2 = new QPushButton(centralwidget);
        pushButtonMoreWords_2->setObjectName(QString::fromUtf8("pushButtonMoreWords_2"));
        pushButtonMoreWords_2->setGeometry(QRect(470, 340, 131, 81));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButtonMoreWords_2->setPalette(palette1);
        pushButtonMoreWords_2->setStyleSheet(QString::fromUtf8("font: 8pt \"DejaVu Sans\";"));
        pushButtonMoreWords_2->setAutoDefault(false);
        pushButtonMoreWords_2->setFlat(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 670, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButtonMoreWords->setDefault(false);
        pushButtonMoreWords_2->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SendpushButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        StatusPacket->setText(QCoreApplication::translate("MainWindow", "Status Packet", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Request:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Response:", nullptr));
        clearresppushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        clearrequestpushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        ControlGroupBox->setTitle(QCoreApplication::translate("MainWindow", "ControlPacket", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Transaction type", nullptr));
        ReadradioButton->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        WriteradioButton->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        NIRradioButton->setText(QCoreApplication::translate("MainWindow", "Non-incrementing read", nullptr));
        NIWradioButton->setText(QCoreApplication::translate("MainWindow", "Non-incrementing write", nullptr));
        RMWBradioButton->setText(QCoreApplication::translate("MainWindow", "RMW bits", nullptr));
        RMWSradioButton->setText(QCoreApplication::translate("MainWindow", "RMW sum", nullptr));
        BaseAdresslabel->setText(QCoreApplication::translate("MainWindow", "Base adress", nullptr));
        BaseAdresslineEdit->setInputMask(QCoreApplication::translate("MainWindow", "HHHHHHHH", nullptr));
        BaseAdresslineEdit->setText(QCoreApplication::translate("MainWindow", "00000000", nullptr));
        Wordslabel->setText(QCoreApplication::translate("MainWindow", "Words", nullptr));
        WordslineEdit->setInputMask(QCoreApplication::translate("MainWindow", "HH", nullptr));
        WordslineEdit->setText(QCoreApplication::translate("MainWindow", "01", nullptr));
        ANDlabel->setText(QCoreApplication::translate("MainWindow", "AND term", nullptr));
        ANDlineEdit->setInputMask(QCoreApplication::translate("MainWindow", "HHHHHHHH", nullptr));
        ANDlineEdit->setText(QCoreApplication::translate("MainWindow", "00000000", nullptr));
        ORlabel->setText(QCoreApplication::translate("MainWindow", "OR term", nullptr));
        ORlineEdit->setInputMask(QCoreApplication::translate("MainWindow", "HHHHHHHH", nullptr));
        ORlineEdit->setText(QCoreApplication::translate("MainWindow", "00000000", nullptr));
        ADDENDlabel->setText(QCoreApplication::translate("MainWindow", "ADDEND", nullptr));
        ADDENDlineEdit->setInputMask(QCoreApplication::translate("MainWindow", "HHHHHHHH", nullptr));
        ADDENDlineEdit->setText(QCoreApplication::translate("MainWindow", "00000000", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter ID", nullptr));
        BitOrdercheckBox->setText(QCoreApplication::translate("MainWindow", "BigEndian", nullptr));
        OwnIDcheckBox->setText(QCoreApplication::translate("MainWindow", "Own ID", nullptr));
        EnterIDlineEdit->setInputMask(QCoreApplication::translate("MainWindow", "HHH", nullptr));
        EnterIDlineEdit->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        ReSendGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Re-send Packet", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Packet ID:", nullptr));
        lineEditID->setInputMask(QCoreApplication::translate("MainWindow", "HHH", nullptr));
        lineEditID->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        TransactionsCounterlabel->setText(QCoreApplication::translate("MainWindow", "Number of transactions\n"
"in packet:", nullptr));
        AddTransactionpushButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonMoreWords->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>This button send a packet with the first incorrect transaction of write and the second correct trans of read. It shows the work of IPbus in exception situation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonMoreWords->setText(QCoreApplication::translate("MainWindow", "More words pointed\n"
" in header\n"
" than exactly\n"
" (write transaction)", nullptr));
        labelDemo->setText(QCoreApplication::translate("MainWindow", "Demo of bad headers:", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonMoreWords_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>This button send a packet with the first incorrect transaction of Non Incrementing write and the second correct trans of  Non Incrementing read. It shows the work of IPbus in exception situation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonMoreWords_2->setText(QCoreApplication::translate("MainWindow", "More words pointed\n"
" in header\n"
" than exactly\n"
"(Non Incrementing\n"
" write transaction)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
