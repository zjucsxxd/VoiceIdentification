#include "dataprocess.hpp"

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

	for (int i = 0; i < length2; i++)
	{
		result += signal2[i] * conj(signal1[i]);
	}
	result = result / (Norm(signal1, length1) * Norm(signal2, length2));
	
	return result.real();
}

std::complex<double> *DataProcess::Fft(std::complex<double> *signal, int length)
{
	std::complex<double> *result = new std::complex<double>[length];
	std::complex<double> *resultCut = new std::complex<double>[5000];	
	double *inputReal = new double[5000];
	double *inputImag = new double[5000];
	double *resultReal = new double[5000];
	double *resultImag = new double[5000];
	// создаем план для библиотеки fftw
	fftw_plan plan = fftw_plan_dft_1d(length, (fftw_complex*)&signal[0], (fftw_complex*)&result[0], FFTW_FORWARD, FFTW_ESTIMATE);

	// преобразование Фурье lib.exe /DEF:D:\fftw\libfftw3-3.def /OUT:D:\fftw\libfftw3-3.lib /MACHINE:IX86
	fftw_execute(plan);
	fftw_destroy_plan(plan);

	for (int i = 0; i < 5000; i++)
	{
		inputReal[i] = abs(result[i].real());
		inputImag[i] = abs(result[i].imag());
	}

	// выводим в файл результат преобразования Фурье (должна получиться Дельта-функция)
	SmoothFft(inputReal, resultReal, 5000, 5);
	SmoothFft(inputImag, resultImag, 5000, 5);
	FILE *fout = fopen("spektr1.txt", "w");
	for (size_t i = 0; i < 5000; ++i)
	{
		resultCut[i] = {resultReal[i],resultImag[i]};
		fprintf(fout, "%f\n", abs(resultReal[i]));
		//fprintf(fout, "%f\n", resultS[i]/*, signal[i].imag()*/);
	}
	fclose(fout);

	free(result);
	free(resultImag);
	free(resultReal);

	return resultCut;
}

void DataProcess::SmoothFft(double* input, double* output, int n, int window)
{
	int i, j, z, k1, k2, hw;
	double tmp;
	if (fmod(window, 2) == 0) window++;
	hw = (window - 1) / 2;
	output[0] = input[0];

	for (i = 1;i < n;i++)
	{
		tmp = 0;
		if (i < hw)
		{
			k1 = 0;
			k2 = 2 * i;
			z = k2 + 1;
		}
		else if ((i + hw) > (n - 1))
		{
			k1 = i - n + i + 1;
			k2 = n - 1;
			z = k2 - k1 + 1;
		}
		else
		{
			k1 = i - hw;
			k2 = i + hw;
			z = window;
		}

		for (j = k1;j <= k2;j++)
		{
			tmp = tmp + input[j];
		}
		output[i] = tmp / z;
	}
}



