/*!
 *  \file   UI_PanelContact.hpp
 *  \brief
 *
 */

#pragma once

#include <QtWidgets/QWidget>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

class UI_PanelContact
{
private:
    QLabel *categoryLabel;
    QLabel *websiteLabel;
public:
    QLineEdit *categoryLineEdit;
    QLineEdit *websiteLineEdit;
    QPushButton *concatButton;
    QPushButton *cancelButton;
    QLabel *displayLabel;
public:
    void setupUi(QWidget* contactForm);
    void retranslateUi(QWidget* contactForm);
};
