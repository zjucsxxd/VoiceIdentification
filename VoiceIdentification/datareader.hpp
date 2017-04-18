#pragma once
#include <QObject>

class DataReader : public QObject {
	Q_OBJECT

public:
	DataReader(QObject * parent = Q_NULLPTR);
	~DataReader();

private:
	
};
