#include "message.h"

Message::Message(QString filePath)
{
    filePath = QDir::currentPath() + "/" + filePath;

    messagesFile = new QFile(filePath);
    if (!messagesFile->exists()) {
        qDebug() << filePath << " is not exist!";
    }
}

void Message::startRead() {
    if (messagesFile->open(QIODevice::ReadOnly))
    {
        do {
            emit readedLine(messagesFile->readLine());
        } while (!messagesFile->atEnd());
        messagesFile->close();
    } else {
        qDebug() << messagesFile->errorString();
    }
}
