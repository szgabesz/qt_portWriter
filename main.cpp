#include <QCoreApplication>
#include <QTextCodec>
#include <QSettings>
#include <QObject>

#include "serialportwriter.h"
#include "message.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString iniFilePath = "./config/write.ini";
    QSettings* settings = new QSettings(iniFilePath, QSettings::IniFormat, NULL);

    QString portName = settings->value("portName").toString();
    int baudRate = settings->value("baudRate").toInt();
    QString parity = settings->value("parity").toString();
    QString stopBit = settings->value("stopBit").toString();
    QString flowControl = settings->value("flowControl").toString();

    SerialPortWriter* spw = new SerialPortWriter(portName, baudRate, parity, stopBit, flowControl);

    Message* msg = new Message("msg.txt");

    QObject::connect(msg, SIGNAL(readedLine(QByteArray)), spw, SLOT(writeData(QByteArray)));
    bool notexit = true;
        do {
            qDebug() << "Please press any buton if you want to re send the messages. (You can exit wih 'exit' message)";
            QTextStream stream(stdin);
            QString line = stream.readLine();

            if (line != "exit") {

                msg->startRead();
            } else {
                notexit = false;
            }
        } while (notexit);


    return a.exec();
}
