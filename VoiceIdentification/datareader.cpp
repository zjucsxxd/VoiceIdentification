#include "datareader.hpp"

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
	//[WORD wExtraFormatBytes;]
	//[Extra format bytes]
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

void DataReader::ReadWavData()
{
	
	FILE *fin = fopen("sample.wav", "rb");

	//Read WAV header
	wav_header_t header;
	fread(&header, sizeof(header), 1, fin);

	chunk_t chunk;

	while (true)
	{
		fread(&chunk, sizeof(chunk), 1, fin);
		printf("%c%c%c%c\t" "%li\n", chunk.ID[0], chunk.ID[1], chunk.ID[2], chunk.ID[3], chunk.size);
		if (*(unsigned int *)&chunk.ID == 0x61746164)
			break;
		//skip chunk data bytes
		fseek(fin, chunk.size, SEEK_CUR);
	}

	//Number of samples

	int sample_size = header.bitsPerSample / 8;
	int samples_count = chunk.size * 8 / header.bitsPerSample;
	printf("Samples count = %i\n", samples_count);

	int *left = new int[samples_count / 2];			// левый канал
	memset(left, 0, sizeof(int) * samples_count / 2);

	int *right = new int[samples_count / 2];		// правый канал
	memset(right, 0, sizeof(int) * samples_count / 2);

	//Reading data
	for (int i = 0; i < samples_count; i++)
	{
		fread(&left[i], sample_size, 1, fin);
		fread(&right[i], sample_size, 1, fin);
	}

	//Write data into the file
	FILE *foutL = fopen("left.txt", "w");
	FILE *foutR = fopen("right.txt", "w");
	for (int i = 0; i < samples_count / 2; i++)
	{
		fprintf(foutL, "%d\n", left[i]);
		fprintf(foutR, "%d\n", right[i]);
	}
	fclose(fin);
	fclose(foutL);
	fclose(foutR);

	QMessageBox msgBox;
	QString q = "Done";
	msgBox.setText(q);
	msgBox.exec();
}
