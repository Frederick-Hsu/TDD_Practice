/*!
 *  \file   PanelContact.hpp
 *  \brief
 */

#pragma once

#include <QWidget>

class UI_PanelContact;

class PanelContact : public QWidget
{
    Q_OBJECT
#if defined (UTESTING)
    friend class TestPanelContact;
#endif
public:
    PanelContact(QWidget *parent = nullptr);
    ~PanelContact();
private:
    UI_PanelContact *ui;
private slots:
    void on_concatButton_Clicked();
    void on_cancelButton_Clicked();
};

