#pragma once
#include <QObject>
#include <QUrl>
#include <QDir>
#include <QMessageBox>
#include <QBitArray>
#include <complex>
#include <cmath>    
#define PI 3.14159265

class DataReader : public QObject {
	Q_OBJECT

public:
	DataReader(QObject * parent = Q_NULLPTR);
	~DataReader();
	std::complex<double> *ReadWavData(char *fileName);
	int GetLength();


private:
	static uint BitToInt(QBitArray buf);
	//static double Smooth(short num1, short num2, int i);
	int _lenght;
	void Smooth(short *input, double *output, int n, int window);
};
