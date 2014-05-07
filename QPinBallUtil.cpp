#include "QPinBallUtil.h"

void LoopTimer::start(int msec) {
	timer->start(msec);
}
void LoopTimer::stop() {
	timer->stop();
}
LoopTimer::LoopTimer() : timer(0) {
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
	timer->setSingleShot(false);
}
LoopTimer::~LoopTimer() {
	if(timer)
		delete timer;
	timer = 0;
}