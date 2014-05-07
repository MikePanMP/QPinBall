#ifndef Q_PIN_BALL_H
#define Q_PIN_BALL_H

#include "../../QMVC/MVC.h"

#include "QPinBallMacro.h"
#include "QPinBallUtil.h"

#include "QtCore/QObject"
#include "QtCore/QString"
#include "QtWidgets/QMessageBox"

class StaticObject;
class BallTimer;
class Ball;
class CollidingObject;
class Paddle;
class Wall;
class Goal;
class Map;
/*
 *
 */
class StaticObject : public QObject {
public:
	void setX(int v);
	int getX();
	void setY(int v);
	int getY();
	void setXL(int v);
	int getXL();
	void setYL(int v);
	int getYL();
public:
	int getLeftBound();
	int getRightBound();
	int getUpperBound();
	int getLowerBound();
public:
	StaticObject(int _x, int _y, int _xl, int _yl) 
		: x(_x), y(_y), xl(_xl), yl(_yl) {}
	virtual ~StaticObject() {}
private:
	int x; // x-coordinate of center
	int y; // y-coordinate of center
	int xl; // length
	int yl; // thickness
};
/*
 *
 */
class BallTimer : public LoopTimer {
public:
	virtual void loop();
public:
	BallTimer(Ball* _ball) : ball(_ball) {}
	virtual ~BallTimer() {}
public:
	Ball* ball;
};
/*
 *
 */
class Ball : public StaticObject {
	Q_OBJECT
private:
	enum { lebound = 0 };
	enum { ribound = 800 };
	enum { upbound = 0 };
	enum { dobound = 600 };
	enum { centerx = 400 };
	enum { centery = 300 };
private:
	enum { diameter = 10 };
	enum { xspeed = 1 };
	enum { yspeed = 1 };
	enum { ldi = -1 };
	enum { rdi = 1 };
	enum { udi = -1 };
	enum { ddi = 1 };
public:
	void reset();
	void start();
	void step();
	int nextX();
	int nextY();
	int getRadius();
public:
	Ball(int x, int y) 
		: StaticObject(x = centerx, y = centery, diameter, diameter), xdi(rdi), xsp(xspeed), ydi(ddi), ysp(yspeed) {
			timer = new BallTimer(this);
	}
	virtual ~Ball() {}
signals:
	void stepped();
public slots:
	void collideFrom(QPinBallMacro::BallCollision from);
private:
	int xdi;
	int xsp;
	int ydi;
	int ysp;
	BallTimer* timer;
};
/*
 *
 */
class CollidingObject : public StaticObject {
	Q_OBJECT
public:
	virtual void afterCollision() {}
public:
	void subscribeToBall(Ball* _ball);
public:
	CollidingObject(int x, int y, int xl, int yl) 
		: StaticObject(x, y, xl, yl), listened(false), leftOfBall(false), aboveBall(false), ball(0) {}
	virtual ~CollidingObject() {}
signals:
	void collideFrom(QPinBallMacro::BallCollision from);
public slots:
	void checkCollision();
private:
	//void updateBallPos();
	//void updateBallPosX();
	//void updateBallPosY();
private:
	bool listened;
	bool leftOfBall;
	bool aboveBall;
	Ball* ball;
};
/*
 * PaddleVTimer
 */
class PaddleVTimer : public LoopTimer {
public:
	virtual void loop();
public:
	PaddleVTimer(Paddle* _paddle) : paddle(_paddle) {}
	virtual ~PaddleVTimer() {}
public:
	Paddle* paddle;
};
/*
 * PaddleHTimer
 */
class PaddleHTimer : public LoopTimer {
public:
	virtual void loop();
public:
	PaddleHTimer(Paddle* _paddle) : paddle(_paddle) {}
	virtual ~PaddleHTimer() {}
public:
	Paddle* paddle;
};
/*
 * Paddle
 */
class Paddle : public CollidingObject {
private:
	enum { offset = 2 };
	enum { length = 100 };
	enum { thick = 5 };
	enum { alpha = 90 };
	enum { speed = 1 };
public:
	void playerMove(QPinBallMacro::HorizontalDirection hd);
	void playerStop(QPinBallMacro::HorizontalDirection hd);
	void playerMove(QPinBallMacro::VerticalDirection vd);
	void playerStop(QPinBallMacro::VerticalDirection vd);
public:
	void vstep();
	void hstep();
	int nextY();
	int nextX();
public:
	Paddle(int _id, int x, int y, int _upbound, int _dobound, int _lebound, int _ribound) 
		: CollidingObject(x, y, thick, length), id(_id), vdi(1), hdi(1), 
		upbound(_upbound), dobound(_dobound), lebound(_lebound), ribound(_ribound) {
			vtimer = new PaddleVTimer(this);
			htimer = new PaddleHTimer(this);
	}
	virtual ~Paddle() {}
private:
	int id;
	int vdi;
	int hdi;
	PaddleVTimer* vtimer;
	PaddleHTimer* htimer;
private:
	int upbound;
	int dobound;
	int lebound;
	int ribound;
};
/*
 * Wall
 */
class Wall : public CollidingObject {
	enum { width = 800 };
	enum { thick = 5 };
public:
	Wall(int y) 
		: CollidingObject(static_cast<int>(width/2), y, width, thick) {}
	virtual ~Wall() {}
};
/*
 * Goal
 */
class Goal : public CollidingObject {
private:
	enum { height = 600 };
	enum { thick = 5};
public:
	virtual void afterCollision() {
	}
public:
	Goal(int x) 
		: CollidingObject(x, static_cast<int>(height/2), thick, height) {}
	virtual ~Goal() {}
};
/*
 * Map
 */
class Map : public MVCModel {
	Q_OBJECT
private:
	enum { width = 800 };
	enum { height = 600 };
public:
	void gameStart();
public: // For Controller
	/* change to primitive
	void playerMove(QPinBallMacro::PlayerId pid, QPinBallMacro::VerticalDirection vd);
	void playerMove(QPinBallMacro::PlayerId pid, QPinBallMacro::HorizontalDirection hd);
	void playerStop(QPinBallMacro::PlayerId pid, QPinBallMacro::VerticalDirection vd);
	void playerStop(QPinBallMacro::PlayerId pid, QPinBallMacro::HorizontalDirection hd);
	*/
	void playerMove(int pid, int vhd);
	void playerStop(int pid, int vhd);
public: // For View
	/* change to primitive
	int getObjPos(QPinBallMacro::ViewId vid, QPinBallMacro::PosParam pos);
	*/
	int getObjPos(int vid, int posparam);
public:
	Map();
	virtual ~Map() {}
private slots:
	void ballStepped();
private:
	int PosX(StaticObject* obj);
	int PosY(StaticObject* obj);
	Paddle* getPlayer(QPinBallMacro::PlayerId pid);
	StaticObject* getObj(QPinBallMacro::ViewId vid);
private:
	Wall* top;
	Wall* bottom;
	Goal* left;
	Goal* right;
	Ball* ball;
	Paddle* player_one;
	Paddle* player_two;
};

#endif // Q_PIN_BALL_H