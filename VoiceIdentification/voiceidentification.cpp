#include "voiceidentification.h"

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

	DataReader d_reader = new DataReader();
	d_reader.ReadWavData();
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

