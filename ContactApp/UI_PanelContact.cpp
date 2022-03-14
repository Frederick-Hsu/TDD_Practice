/*!
 *  \file   UI_PanelContact.cpp
 *  \brief
 *
 */

#include "UI_PanelContact.hpp"

#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>

void UI_PanelContact::setupUi(QWidget *contactForm)
{
    if (contactForm->objectName().isEmpty())
        contactForm->setObjectName(QString::fromUtf8("contactForm"));

    /* Category */
    categoryLabel = new QLabel(contactForm);
    categoryLabel->setObjectName(QString::fromUtf8("categoryLabel"));
    categoryLineEdit = new QLineEdit(contactForm);
    categoryLineEdit->setObjectName(QString::fromUtf8("categoryLineEdit"));
    categoryLabel->setBuddy(categoryLineEdit);
    /* Website */
    websiteLabel = new QLabel(contactForm);
    websiteLabel->setObjectName(QString::fromUtf8("websiteLabel"));
    websiteLineEdit = new QLineEdit(contactForm);
    websiteLineEdit->setObjectName(QString::fromUtf8("websiteLineEdit"));
    websiteLabel->setBuddy(websiteLineEdit);

    QHBoxLayout *topHLayout = new QHBoxLayout();
    topHLayout->setObjectName(QString::fromUtf8("topHLayout"));
    topHLayout->addWidget(categoryLabel);
    topHLayout->addWidget(categoryLineEdit);
    topHLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    topHLayout->addWidget(websiteLabel);
    topHLayout->addWidget(websiteLineEdit);

    /* Concatenate button */
    concatButton = new QPushButton(contactForm);
    concatButton->setObjectName(QString::fromUtf8("concatButton"));
    /* Cancel button */
    cancelButton = new QPushButton(contactForm);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    QHBoxLayout *bottomHLayout = new QHBoxLayout();
    bottomHLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    bottomHLayout->addWidget(concatButton);
    bottomHLayout->addWidget(cancelButton);
    bottomHLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    /* Display label */
    displayLabel = new QLabel(contactForm);
    displayLabel->setObjectName(QString::fromUtf8("displayLabel"));

    QVBoxLayout *entireFormVLayout = new QVBoxLayout();
    entireFormVLayout->setObjectName(QString::fromUtf8("entireFormVLayout"));
    entireFormVLayout->addLayout(topHLayout);
    entireFormVLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    entireFormVLayout->addLayout(bottomHLayout);
    entireFormVLayout->addWidget(displayLabel);

    QGridLayout *formGridLayout = new QGridLayout(contactForm);
    formGridLayout->setObjectName(QString::fromUtf8("formGridLayout"));
    formGridLayout->addLayout(entireFormVLayout, 0, 0, 1, 1);

    retranslateUi(contactForm);
    QMetaObject::connectSlotsByName(contactForm);
}

void UI_PanelContact::retranslateUi(QWidget *contactForm)
{
    contactForm->setWindowTitle(QCoreApplication::translate("PanelContact", "Panel Contact", nullptr));
    categoryLabel->setText(QCoreApplication::translate("PanelContact", "Category: ", nullptr));
    websiteLabel->setText(QCoreApplication::translate("PanelContact", "Website: ", nullptr));
    concatButton->setText(QCoreApplication::translate("PanelContact", "CONCATENATE", nullptr));
    cancelButton->setText(QCoreApplication::translate("PanelContact", "CANCEL", nullptr));
    displayLabel->setText(QCoreApplication::translate("PanelContact", "display...", nullptr));
}
