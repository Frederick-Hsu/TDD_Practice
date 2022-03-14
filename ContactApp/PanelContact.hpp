/*!
 *  \file   PanelContact.hpp
 *  \brief
 */

#pragma once

#include <QWidget>
#if defined (UTESTING)
    #include "../TestPanelContact/tst_testpanelcontact.hpp"
#endif

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

