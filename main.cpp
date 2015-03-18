#include <QCoreApplication>

#include "downloadmanager.h"
#include <QTimer>
#include "sstream"
#include <QDateTime>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    DownloadManager manager2015;
    QDate first2015(2006,01,01);
    QDate end(2012,01,01);
    int tot = 0;
    //today.currentDate().toString("yyyy-MM-dd")
    while(first2015.toString("yyyy-MM-dd") != end.toString("yyyy-MM-dd"))
    {
        QString UrlBase("http://www.aspiturf.com/PTcoursejourdetinsertdatecsv.php?datejour=");
        UrlBase.append(first2015.toString("yyyy-MM-dd"));
        QUrl url(UrlBase);
        manager2015.doDownload(url);
        tot++;
        first2015 = first2015.addDays(1);
    }
    manager2015.setNb(tot);
    qDebug() << "2015 request sent : ";
    qDebug() << tot;
    app.exec();
}
