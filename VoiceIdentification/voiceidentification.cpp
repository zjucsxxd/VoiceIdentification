#include "voiceidentification.h"
#include "dataprocess.hpp"

#define Count 10

VoiceIdentification::VoiceIdentification(QWidget *parent)
	: QMainWindow(parent)
{
	nullTime.setHMS(0, 0, 0, 0);
	ui->setupUi(this);
	voiceRecord = new VoiceRecord();
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
	connect(ui->startRecordButton, SIGNAL(clicked()), this, SLOT(RecordSlot()));
	connect(ui->stopRecordButton, SIGNAL(clicked()), this, SLOT(StopRecordSlot()));
	connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(LoadSlot()));
}

VoiceIdentification::~VoiceIdentification()
{
	delete voiceRecord;
}

void VoiceIdentification::RecordSlot()
{
	ui->timeEdit->setTime(nullTime);
	voiceRecord->StartRecord();
	timer->start(1);
}

void VoiceIdentification::StopRecordSlot()
{
	voiceRecord->StopRecord();
	timer->stop();
}

void VoiceIdentification::LoadSlot()
{
	DataReader dReader = new DataReader();
	DataProcess dataProcess = new DataProcess();
	FILE *fout = fopen("result.txt", "w");
	std::complex<double> *signal[Count];
	std::complex<double> *spectr[Count];
	std::complex<double> *input = dReader.ReadWavData("t1.wav");
	int l = dReader.GetLength();
	std::complex<double> *inputSpectr = dataProcess.Fft(input, l);
	int length[Count];
	bool done = false;
	/*
	for (int i = 0; i < Count; i++)
	{
		std::string name = "t" + std::to_string(i + 1) + ".wav";
		signal[i] = dReader.ReadWavData(&name[0u]);
		length[i] = dReader.GetLength();
		spectr[i] = dataProcess.Fft(signal[i], length[i]);

		double result = dataProcess.Calculate(inputSpectr, spectr[i], 5000, 5000);
		fprintf(fout, "%d : %f\n", i, result);
		if (result > 0.8)
		{
			QMessageBox msgBox;
			QString q = "Authentication complete! " + QString::number(i);
			msgBox.setText(q);
			msgBox.exec();
			done = true;
			break;
		}		
	}
	if (!done)
	{
		QMessageBox msgBox;
		QString q = "Authentication failed!";
		msgBox.setText(q);
		msgBox.exec();
	}
	*/
	//delete length;
	//delete inputSpectr;

	fclose(fout);
}

void VoiceIdentification::onTimeout()
{
	time = ui->timeEdit->time().addMSecs(1);
	ui->timeEdit->setTime(time);
}

