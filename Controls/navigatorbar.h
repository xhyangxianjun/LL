#ifndef NAVIGATORBAR_H
#define NAVIGATORBAR_H

#include "controls_global.h"
#include "basewidget.h"
#include <vector>
#include <map>
#include <QMap>

#include "subtab.h"

struct NaviTableItem
{
    QString name_;
    QString url_;
    NaviTableItem(){}
    NaviTableItem(const QString& name,const QString& url):
        name_(name),
        url_(url)
    {}
};

class QPushButton;
class QVBoxLayout;
class CONTROLSSHARED_EXPORT NavigatorBar : public BaseWidget
{
    Q_OBJECT
public:
    explicit NavigatorBar(QWidget *parent = 0);

    //添加导航条
    void addCSubTab(CSubTab *csubTab);
    CSubTab *addCSubTab(CSubTab::CSubTabType = CSubTab::Root_Tab);

    void addButtonToTab(const int &id,const QString &text);
    void setSubTabButtons(const int &id,const QStringList &textList);

    CSubTab *csubTab(int id){return m_csubTabs.value(id);}

signals:
    void navigatorSectionChanged(int  priButton,int secButon);
    void subTabSectionChanged(int id,int button);

private slots:
    void tabCurrentBtnChanged(const int &id);

private:
    void createWg();

private:
    QMap<int ,CSubTab *> m_csubTabs;
    QVBoxLayout  *m_mainLayout;
};


#endif // NAVIGATORBAR_H
