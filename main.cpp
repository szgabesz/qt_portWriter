#include <QCoreApplication>
#include "serialportwriter.h"
#include <QTextCodec>
#include <QSettings>

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

    bool notexit = true;
    do {
        QTextStream stream(stdin);
        QString line = stream.readLine();
        if (line != "exit") {
            QByteArray byteMsg = line.toUtf8();
            spw->writeData(byteMsg);
        } else {
            notexit = false;
        }
    } while (notexit);

    return a.exec();
}
