#pragma once
#include <QObject>
#include <QUrl>
#include <QDir>
#include <QMessageBox>
#include <QBitArray>
#include <complex>

class DataReader : public QObject {
	Q_OBJECT

public:
	DataReader(QObject * parent = Q_NULLPTR);
	~DataReader();
	std::complex<double> *ReadWavData(char *fileName);
	int GetLength();


private:
	static uint BitToInt(QBitArray buf);
	int _lenght;
};
