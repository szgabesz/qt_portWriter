#ifndef SERIALPORTWRITER_H
#define SERIALPORTWRITER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

class SerialPortWriter : public QObject
{
    Q_OBJECT
private:
    QSerialPort* serial;
    QStringList parityList, flowControlList, stopBitList;

    void setBaudRate(int baudRate);
    void setStopBit(QString stopBit);
    void setParity(QString parity);
    void setFlowControl(QString flowControl);
public:
    explicit SerialPortWriter(QString portName, int baudRate, QString parity, QString stopBit, QString flowControl);

signals:

public slots:
    void writeData(QByteArray msg);
};

#endif // SERIALPORTWRITER_H
