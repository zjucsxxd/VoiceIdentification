#pragma once
#include <QObject>
#include <QAudioRecorder>
#include <QUrl>
#include <QDir>

class VoiceRecord : public QObject {
	Q_OBJECT

public:
	VoiceRecord(QObject * parent = Q_NULLPTR);
	~VoiceRecord();
	void StartRecord();
	void StopRecord();

private:
	QAudioRecorder *audioRecorder;
};
