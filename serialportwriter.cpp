#define QDEBUG 1
#include "serialportwriter.h"
#include <QThread>

SerialPortWriter::SerialPortWriter(QString portName, int baudRate, QString parity, QString stopBit, QString flowControl)
{
    parityList << "EvenParity" << "OddParity" << "SpaceParity" << "MarkParity" << "UnknownParity" << "NoParity";
    flowControlList << "HardwareControl" << "HardwareControl" << "NoFlowControl";
    stopBitList << "OneStop" << "OneAndHalfStop" << "TwoStop";

    serial = new QSerialPort();

    serial->setPortName(portName);
    setBaudRate(baudRate);
    setParity(parity);
    setStopBit(stopBit);
    setFlowControl(flowControl);
}

void SerialPortWriter::setStopBit(QString stopBit)
{
    switch (stopBitList.indexOf(stopBit)) {
    case 0:
        serial->setStopBits(QSerialPort::OneStop);
        break;
    case 1:
        serial->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    case 2:
        serial->setStopBits(QSerialPort::TwoStop);
        break;
    default:
        serial->setStopBits(QSerialPort::OneStop);
        break;
    }
}

void SerialPortWriter::setFlowControl(QString flowControl)
{
    switch (flowControlList.indexOf(flowControl)) {
    case 0:
        serial->setFlowControl(QSerialPort::HardwareControl);
        break;
    case 1:
        serial->setFlowControl(QSerialPort::HardwareControl);
        break;
    case 2:
        serial->setFlowControl(QSerialPort::NoFlowControl);
        break;
    default:
        serial->setFlowControl(QSerialPort::NoFlowControl);
        break;
    }
}

void SerialPortWriter::setParity(QString parity)
{
    switch (parityList.indexOf(parity)) {
    case 0:
        serial->setParity(QSerialPort::EvenParity);
        break;
    case 1:
        serial->setParity(QSerialPort::OddParity);
        break;
    case 2:
        serial->setParity(QSerialPort::SpaceParity);
        break;
    case 3:
        serial->setParity(QSerialPort::MarkParity);
        break;
    case 4:
        serial->setParity(QSerialPort::UnknownParity);
        break;
    default:
        serial->setParity(QSerialPort::NoParity);
        break;
    }
}

void SerialPortWriter::setBaudRate(int baudRate)
{
    switch (baudRate) {
    case 1200:
        serial->setBaudRate(QSerialPort::Baud1200, QSerialPort::AllDirections);
        break;
    case 2400:
        serial->setBaudRate(QSerialPort::Baud2400, QSerialPort::AllDirections);
        break;
    case 4800:
        serial->setBaudRate(QSerialPort::Baud4800, QSerialPort::AllDirections);
        break;
    case 9600:
        serial->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
        break;
    case 19200:
        serial->setBaudRate(QSerialPort::Baud19200, QSerialPort::AllDirections);
        break;
    case 38400:
        serial->setBaudRate(QSerialPort::Baud38400, QSerialPort::AllDirections);
        break;
    case 57600:
        serial->setBaudRate(QSerialPort::Baud57600, QSerialPort::AllDirections);
        break;
    case 115200:
        serial->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
        break;
    default:
        serial->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
        break;
    }
}

void SerialPortWriter::writeData(QByteArray msg)
{
    if (serial->open(QIODevice::WriteOnly)) {
        if (QDEBUG) qDebug() << "send message: " << msg;
        serial->write(msg);
        if (QDEBUG) qDebug() << "wait for written";
        serial->waitForBytesWritten(10);
        serial->close();
    } else {
        qDebug() << " ERROR: " << serial->errorString();
    }
}
