#ifndef Q_PIN_BALL_UTIL_H
#define Q_PIN_BALL_UTIL_H

#include <QTimer>
/*
 * LoopTimer
 */
class LoopTimer : public QObject {
	Q_OBJECT
public:
	virtual void loop() {}
public:
	void start(int msec);
	void stop();
public:
	LoopTimer();
	virtual ~LoopTimer();
private slots:
	void timeout() {
		loop();
	}
private:
	QTimer* timer;
};

#endif // Q_PIN_BALL_UTIL_H