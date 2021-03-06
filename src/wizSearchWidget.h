#ifndef WIZSEARCHWIDGET_H
#define WIZSEARCHWIDGET_H

#include <QtGlobal>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>

// Wrap widget for qt widget and mac native search field
// refer to mac/wizSearchWidget.mm for osx NSSearchField

#ifdef Q_OS_MAC
class CWizSearchWidget;
#endif

#ifndef Q_OS_MAC

class CWizExplorerApp;

class CWizSearchWidget : public QWidget
{
    Q_OBJECT

public:
    CWizSearchWidget(CWizExplorerApp& app, QWidget* parent = 0);
    void clear();
    void focus();

    virtual QSize sizeHint() const;

public Q_SLOTS:
    void on_search_textChanged(const QString& strText);

private:
    QLineEdit* m_editSearch;

Q_SIGNALS:
    void doSearch(const QString& keywords);
};

#endif // Q_OS_MAC

class CWizExplorerApp;

class CWizSearchBox : public QWidget
{
    Q_OBJECT

private:
    CWizSearchWidget* s;

public:
    explicit CWizSearchBox(CWizExplorerApp& app, QWidget *parent = 0);
    virtual QSize sizeHint() const;

    void clear();
    void focus();

Q_SIGNALS:
    void doSearch(const QString& keywords);
};


#endif // WIZSEARCHWIDGET_H
