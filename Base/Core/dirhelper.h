#ifndef DIRHELPER_H
#define DIRHELPER_H

#include <QString>

class DirHelper
{
public:
   static DirHelper  *getInstance();

    QString appDataDir()const {return m_appDataDir;}
    QString userDataDir()const {return m_userDataDir;}

protected:
    DirHelper();

private:
    QString m_appDataDir;
    QString m_userDataDir;
};

#endif // DIRHELPER_H
