#include "datareader.hpp"
#include "dataprocess.hpp"

struct wav_header_t
{
	char chunkID[4]; //"RIFF" = 0x46464952
	unsigned long chunkSize; //28 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes] + sum(sizeof(chunk.id) + sizeof(chunk.size) + chunk.size)
	char format[4]; //"WAVE" = 0x45564157
	char subchunk1ID[4]; //"fmt " = 0x20746D66
	unsigned long subchunk1Size; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned long sampleRate;
	unsigned long byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
};

struct chunk_t
{
	char ID[4]; //"data" = 0x61746164
	unsigned long size;  //Chunk data bytes
};

DataReader::DataReader(QObject * parent) : QObject(parent) {

}

DataReader::~DataReader() {

}

std::complex<double> *DataReader::ReadWavData(char *fileName)
{
	FILE *fin = fopen(fileName, "rb");

	//Read WAV header
	wav_header_t header;
	fread(&header, sizeof(header), 1, fin);

	chunk_t chunk;

	while (true)
	{
		fread(&chunk, sizeof(chunk), 1, fin);
		if (*(unsigned int *)&chunk.ID == 0x61746164)
			break;
		//skip chunk data bytes
		fseek(fin, chunk.size, SEEK_CUR);
	}

	//Number of samples

	int sampleSize = header.bitsPerSample / 8;
	int samplesCount = chunk.size * 8 / header.bitsPerSample;
	_lenght = samplesCount / 2;

	short *left = new short[samplesCount / 2];			// левый канал
	memset(left, 0, sizeof(short) * samplesCount / 2);

	short *right = new short[samplesCount / 2];		// правый канал
	memset(right, 0, sizeof(short) * samplesCount / 2);

	//Reading data
	for (int i = 0; i < samplesCount; i++)
	{
		fread(&left[i], sampleSize, 1, fin);
		fread(&right[i], sampleSize, 1, fin);
	}
	fclose(fin);

	//Write data into the file
	FILE *fout = fopen("signal.txt", "w");
	FILE *foutL = fopen("left.txt", "w");
	FILE *foutR = fopen("right.txt", "w");
	FILE *fComplex = fopen("complex.txt", "w");

	for (int i = 0; i < samplesCount / 2; i++)
	{
		fprintf(foutL, "%d\n", left[i]);
		fprintf(foutR, "%d\n", right[i]);
		fprintf(fout, "%d\n", left[i]);
		fprintf(fout, "%d\n", right[i]);
	}
	fclose(foutL);
	fclose(fout);
	fclose(foutR);

	//write complex 
	std::complex<double> *signal = new std::complex<double>[samplesCount / 2];
	for (int i = 0; i < samplesCount / 2; i++)
	{
		signal[i] = { (double)left[i],(double)right[i] };
		fprintf(fComplex, "%f%+fi\n", real(signal[i]), imag(signal[i]));
	}

	DataProcess dp = new DataProcess();
	double norm = dp.Norm(signal, samplesCount / 2);

	fprintf(fComplex, "%f\n", norm);
	fclose(fComplex);

	QMessageBox msgBox;
	QString q = "Norm: " + QString::number(norm);
	msgBox.setText(q);
	msgBox.exec();

	return signal;
}

int DataReader::GetLength()
{
	return _lenght;
}

uint DataReader::BitToInt(QBitArray buf)
{
	uint value = 0;
	for (uint j = 0; j < buf.size(); j++)
	{
		value <<= 1;
		value += (int)buf.at(j);
	}
	return value;
}
