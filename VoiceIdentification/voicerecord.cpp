#include "voicerecord.hpp"

VoiceRecord::VoiceRecord(QObject * parent) : QObject(parent) {
	audioRecorder = new QAudioRecorder(this);

	//  configure recorder  //
	QAudioEncoderSettings audioSettings;
	audioSettings.setCodec("audio/PCM");
	audioSettings.setQuality(QMultimedia::HighQuality);
	audioSettings.setChannelCount(1);
	audioSettings.setSampleRate(44100);
	audioSettings.setBitRate(16);
	audioRecorder->setEncodingSettings(audioSettings);

	//  set destination  //
	audioRecorder->setOutputLocation(QUrl::fromLocalFile(QDir::currentPath() + "/sample.wav"));
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