#include "voicerecord.hpp"

VoiceRecord::VoiceRecord(QObject * parent) : QObject(parent) {
	audioRecorder = new QAudioRecorder(this);

	//  configure recorder  //
	QAudioEncoderSettings audioSettings;
	audioSettings.setCodec("audio/PCM");
	audioSettings.setQuality(QMultimedia::HighQuality);
	audioRecorder->setEncodingSettings(audioSettings);

	//  set destination  //
	//audioRecorder->setOutputLocation(QUrl::fromLocalFile("D:/sample.wav"));
	audioRecorder->setOutputLocation(QUrl::fromLocalFile(QDir::currentPath() + "/sample.wav"));
	//audioRecorder->setOutputLocation(QDir::current()("sample.wav"));
}

VoiceRecord::~VoiceRecord() {
	delete audioRecorder;
}

void VoiceRecord::StartRecord()
{
	audioRecorder->record();
}

void VoiceRecord::StopRecord()
{
	audioRecorder->stop();
}