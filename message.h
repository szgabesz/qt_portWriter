#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QObject>
#include <QByteArray>
#include <QDir>

class Message : public QObject
{
    Q_OBJECT
private:
    QFile *messagesFile;

public:
    explicit Message(QString filePath);
    void startRead();

signals:
    void readedLine(QByteArray);

public slots:
};

#endif // MESSAGE_H
