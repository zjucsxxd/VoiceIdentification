#include "voiceidentification.h"

VoiceIdentification::VoiceIdentification(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	voiceRecord = new VoiceRecord();
	//connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
	connect(ui.startRecordButton, SIGNAL(clicked()), this, SLOT(RecordSlot()));
	connect(ui.stopRecordButton, SIGNAL(clicked()), this, SLOT(StopRecordSlot()));
	connect(ui.playButton, SIGNAL(clicked()), this, SLOT(PlaySlot()));
	connect(ui.pauseButton, SIGNAL(clicked()), this, SLOT(PauseSlot()));
	
	QMessageBox msgBox;
	msgBox.setText(QDir::currentPath());
	msgBox.exec();
}

VoiceIdentification::~VoiceIdentification()
{
	delete mediaPlayer;
	delete voiceRecord;
}

void VoiceIdentification::RecordSlot()
{
	voiceRecord->StartRecord();
	//timer->start(100);
}

void VoiceIdentification::StopRecordSlot()
{
	voiceRecord->StopRecord();
}

void VoiceIdentification::PlaySlot()
{
	mediaPlayer = new QMediaPlayer(this);
	mediaPlayer->setMedia(QUrl::fromLocalFile(QDir::currentPath() + "/sample.wav"));
	mediaPlayer->play();
}

void VoiceIdentification::PauseSlot()
{
	mediaPlayer->pause();
}

void VoiceIdentification::onTimeout()
{	
	QTime time = ui.timeEdit->time().addMSecs(-1);
	ui.timeEdit->setTime(time);
	//ui.timeEdit->time().addMSecs(1);

}

