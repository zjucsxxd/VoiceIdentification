#include "voiceidentification.h"
#include "dataprocess.hpp"

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
	connect(ui->playButton, SIGNAL(clicked()), this, SLOT(PlaySlot()));
	connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(LoadSlot()));
	connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(PauseSlot()));
}

VoiceIdentification::~VoiceIdentification()
{
	delete mediaPlayer;
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
	//mediaPlayer = new QMediaPlayer(this);
	//mediaPlayer->setMedia(QUrl::fromLocalFile(QDir::currentPath() + "/sample.wav"));	
	DataReader dReader = new DataReader();
	std::complex<double> *signal1 = dReader.ReadWavData("template.wav");
	int length1 = dReader.GetLength();
	std::complex<double> *signal2 = dReader.ReadWavData("sample.wav");
	int length2 = dReader.GetLength();
	DataProcess dataProcess = new DataProcess();
	dataProcess.Calculate(signal1, signal2, length1, length2);
	
}

void VoiceIdentification::PlaySlot()
{
	ui->timeEdit->setTime(nullTime);
	mediaPlayer->play();
	timer->start(1);
}

void VoiceIdentification::PauseSlot()
{
	mediaPlayer->stop();
	timer->stop();
	mediaPlayer->setMedia(QMediaContent());
}

void VoiceIdentification::onTimeout()
{
	time = ui->timeEdit->time().addMSecs(1);
	ui->timeEdit->setTime(time);
}

