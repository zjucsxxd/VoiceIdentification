#include "dataprocess.hpp"
#include <complex>

DataProcess::DataProcess(QObject * parent) : QObject(parent) {

}

DataProcess::~DataProcess() {

}

double DataProcess::Norm(std::complex<double> *signal, int length)
{
	double result = 0;
	for (int i = 0; i < length; i++)
	{
		result += signal[i].real() * signal[i].real() + signal[i].imag() * signal[i].imag();
	}
	double norm = sqrt(result);

	return norm;
}

double DataProcess::Calculate(std::complex<double>* signal1, std::complex<double>* signal2, int length1, int length2)
{
	std::complex<double> result;
	double max = 0;

	for (int t = 0; t < length1 - length2; t++)
	{
		for (int i = 0; i < length2; i++)
		{
			result += signal2[i] * conj(signal1[i+t]);
		}
		result = result / (Norm(signal1, length1) * Norm(signal2, length2));
		if (result.real() > max)
		{
			max = result.real();
		}
	}

	
	return max;
}
