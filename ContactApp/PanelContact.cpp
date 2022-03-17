/*!
 *  \file   PanelContact.cpp
 *  \brief
 */


#include "PanelContact.hpp"
#include "UI_PanelContact.hpp"

PanelContact::PanelContact(QWidget *parent) : QWidget(parent), ui(new UI_PanelContact)
{
    ui->setupUi(this);

    QObject::connect(ui->concatButton, &QPushButton::clicked, this, &PanelContact::onConcatButtonClicked);
    QObject::connect(ui->cancelButton, &QPushButton::clicked, this, &PanelContact::onCancelButtonClicked);
}

PanelContact::~PanelContact()
{
    delete ui;
}

void PanelContact::onConcatButtonClicked()
{
    QString category = ui->categoryLineEdit->text();
    QString website = ui->websiteLineEdit->text();

    ui->displayLabel->setText(category + website);

    emit DataAvailable(ui->displayLabel->text());
}

void PanelContact::onCancelButtonClicked()
{
    ui->displayLabel->setText("");
    ui->categoryLineEdit->setText("");
    ui->websiteLineEdit->setText("");

    emit DataCleared();
}
