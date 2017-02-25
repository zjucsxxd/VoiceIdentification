#include "voiceidentification.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VoiceIdentification w;
	w.show();

	return a.exec();
}
