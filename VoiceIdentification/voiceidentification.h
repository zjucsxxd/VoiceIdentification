#ifndef VOICEIDENTIFICATION_H
#define VOICEIDENTIFICATION_H

#include <QtWidgets/QMainWindow>
#include "ui_voiceidentification.h"

class VoiceIdentification : public QMainWindow
{
	Q_OBJECT

public:
	VoiceIdentification(QWidget *parent = 0);
	~VoiceIdentification();

private:
	Ui::VoiceIdentificationClass ui;
};

#endif // VOICEIDENTIFICATION_H
