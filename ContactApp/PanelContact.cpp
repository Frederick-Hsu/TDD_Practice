/*!
 *  \file   PanelContact.cpp
 *  \brief
 */


#include "PanelContact.hpp"
#include "UI_PanelContact.hpp"

PanelContact::PanelContact(QWidget *parent) : QWidget(parent), ui(new UI_PanelContact)
{
    ui->setupUi(this);

    QObject::connect(ui->concatButton, &QPushButton::clicked, this, &PanelContact::on_concatButton_Clicked);
    QObject::connect(ui->cancelButton, &QPushButton::clicked, this, &PanelContact::on_cancelButton_Clicked);
}

PanelContact::~PanelContact()
{
    delete ui;
}

void PanelContact::on_concatButton_Clicked()
{
    QString category = ui->categoryLineEdit->text();
    QString website = ui->websiteLineEdit->text();

    ui->displayLabel->setText(category + website);
}

void PanelContact::on_cancelButton_Clicked()
{
    ui->displayLabel->setText("");
    ui->categoryLineEdit->setText("");
    ui->websiteLineEdit->setText("");
}
