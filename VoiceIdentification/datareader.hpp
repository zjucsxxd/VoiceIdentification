#pragma once
#include <QObject>
#include <QUrl>
#include <QDir>
#include <QMessageBox>

class DataReader : public QObject {
	Q_OBJECT

public:
	DataReader(QObject * parent = Q_NULLPTR);
	~DataReader();
	void ReadWavData();


private:
	
};
