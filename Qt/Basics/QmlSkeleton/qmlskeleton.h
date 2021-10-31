#ifndef QMLSKELETON_H
#define QMLSKELETON_H

#include <QObject>

class QmlSkeleton : public QObject
{
    Q_OBJECT

public slots:
    QString sayHello(const QString& name);

};

#endif // QMLSKELETON_H
