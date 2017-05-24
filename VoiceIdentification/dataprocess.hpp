#pragma once
#include <QObject>
#include <complex>
#include <fftw3.h>


class DataProcess : public QObject {
	Q_OBJECT

public:
	DataProcess(QObject * parent = Q_NULLPTR);
	~DataProcess();
	double Norm(std::complex<double> *signal, int length);
	double Calculate(std::complex<double> *signal1, std::complex<double> *signal2, int length1, int length2);
	std::complex<double> *Fft(std::complex<double>* signal, int length);
	void SmoothFft(double *input, double *output, int n, int window);

private:
	
};
