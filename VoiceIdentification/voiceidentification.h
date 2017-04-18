#ifndef VOICEIDENTIFICATION_H
#define VOICEIDENTIFICATION_H

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include "ui_voiceidentification.h"
#include "voicerecord.hpp"

class VoiceIdentification : public QMainWindow
{
	Q_OBJECT

public:
	VoiceIdentification(QWidget *parent = 0);
	~VoiceIdentification();


private slots:
	void RecordSlot();
	void StopRecordSlot();
	void PlaySlot();
	void LoadSlot();
	void PauseSlot();
	void onTimeout();

private:
	Ui::VoiceIdentificationClass *ui;
	VoiceRecord *voiceRecord;
	QMediaPlayer *mediaPlayer;
	QTimer *timer;
	QTime time;
	QTime nullTime;
};

#endif // VOICEIDENTIFICATION_H
