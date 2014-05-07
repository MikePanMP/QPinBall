#include "QPinBall.h"

#include "QPinBallMacro.h"
#include "QPinBallUtil.h"

void StaticObject::setX(int v) { 
	x = v; 
}
int StaticObject::getX() { 
	return x; 
}
void StaticObject::setY(int v) { 
	y = v; 
}
int StaticObject::getY() { 
	return y; 
}
void StaticObject::setXL(int v) { 
	xl = v; 
}
int StaticObject::getXL() { 
	return xl; 
}
void StaticObject::setYL(int v) { 
	yl = v; 
}
int StaticObject::getYL() { 
	return yl; 
}
int StaticObject::getLeftBound() {
	return x - static_cast<int>(xl/2);
}
int StaticObject::getRightBound() {
	return x + static_cast<int>(xl/2);
}
int StaticObject::getUpperBound() {
	return y - static_cast<int>(yl/2);
}
int StaticObject::getLowerBound() {
	return y + static_cast<int>(yl/2);
}

void BallTimer::loop() {
	ball->step();
}

void Ball::reset() {
	setX(centerx);
	setY(centery);
	emit stepped();
}

void Ball::start() {
	timer->start(8);
}

void Ball::step() {
	setX( nextX() );
	setY( nextY() );
	emit stepped();
}

int Ball::nextX() {
	int newx = xdi * xsp + getX();
	
	if (newx < lebound)
		newx = lebound;
	else if (newx > ribound)
		newx = ribound;
		
	return newx;
}
int Ball::nextY() {
	int newy = ydi * ysp + getY();
	
	if (newy < upbound)
		newy = upbound;
	else if (newy > dobound)
		newy = dobound;

	return newy;
}

int Ball::getRadius() {
	return static_cast<int>(diameter/2);
}

void Ball::collideFrom(QPinBallMacro::BallCollision from) {
	//QMessageBox::about(0, QString(""), QString("%1").arg(from));
	switch (from) {
	case QPinBallMacro::FROM_UP:	ydi = ddi; break;
	case QPinBallMacro::FROM_DOWN:	ydi = udi; break;
	case QPinBallMacro::FROM_LEFT:	xdi = rdi; break;
	case QPinBallMacro::FROM_RIGHT:	xdi = ldi; break;
	default: break;
	}
}

void CollidingObject::subscribeToBall(Ball* _ball) {
	if (!listened) {
		ball = _ball;
		//updateBallPos();
		connect(
			ball, SIGNAL(stepped()),
			this, SLOT(checkCollision()));
		connect(
			this, SIGNAL(collideFrom(QPinBallMacro::BallCollision)),
			ball, SLOT(collideFrom(QPinBallMacro::BallCollision)));
		listened = true;
	}
}

void CollidingObject::checkCollision() {
	int bx = ball->getX();
	int by = ball->getY();
	int bnx = ball->nextX();
	int bny = ball->nextY();
	//int r = ball->getRadius();
	int r = 0;
	
	if (bnx > getRightBound() + r || bnx < getLeftBound() - r ||
		bny > getLowerBound() + r || bny < getUpperBound() - r ) {
			//updateBallPos();
			return;
	}

	if (bx > getRightBound() + r)
		emit collideFrom(QPinBallMacro::FROM_LEFT);
	else if (bx < getLeftBound() - r )
		emit collideFrom(QPinBallMacro::FROM_RIGHT);

	if (by > getLowerBound() + r)
		emit collideFrom(QPinBallMacro::FROM_UP);
	else if (by < getUpperBound() - r )
		emit collideFrom(QPinBallMacro::FROM_DOWN);

	afterCollision();
}
/*
void CollidingObject::updateBallPos() {
	updateBallPosX();
	updateBallPosY();
}
void CollidingObject::updateBallPosX() {
	leftOfBall = ( getX() < ball->getX() );
}
void CollidingObject::updateBallPosY() {
	aboveBall = ( getY() < ball->getY() );
}
*/
void PaddleVTimer::loop() {
	paddle->vstep();
}

void PaddleHTimer::loop() {
	paddle->hstep();
}

void Paddle::playerMove(QPinBallMacro::HorizontalDirection hd) {
	htimer->stop();
	switch (hd) {
	case QPinBallMacro::LEFT:	hdi = -1; break;
	case QPinBallMacro::RIGHT:	hdi = 1; break;
	default: break;
	}
	htimer->start(10);
}
void Paddle::playerStop(QPinBallMacro::HorizontalDirection hd) {
	htimer->stop();
}
void Paddle::playerMove(QPinBallMacro::VerticalDirection vd) {
	vtimer->stop();
	switch (vd) {
	case QPinBallMacro::UP:		vdi = -1; break;
	case QPinBallMacro::DOWN:	vdi = 1; break;
	default: break;
	}
	vtimer->start(10);
}
void Paddle::playerStop(QPinBallMacro::VerticalDirection vd) {
	vtimer->stop();
}

void Paddle::vstep() {
	setY( nextY() );
	checkCollision();
}
void Paddle::hstep() {
	setX( nextX() );
	checkCollision();
}

int Paddle::nextY() {
	int newy = vdi * speed + getY();
	if ( newy < upbound )
		newy = upbound;
	else if ( newy > dobound )
		newy = dobound;
	return newy;
}
int Paddle::nextX() {
	int newx = hdi * speed + getX();
	if ( newx < lebound )
		newx = lebound;
	else if ( newx > ribound )
		newx = ribound;
	return newx;
}

void Map::gameStart() {
	ball->start();
}
/*
void Map::playerMove(QPinBallMacro::PlayerId pid, QPinBallMacro::VerticalDirection vd) {
	getPlayer(pid)->playerMove(vd);
	selfChanged();
}
void Map::playerMove(QPinBallMacro::PlayerId pid, QPinBallMacro::HorizontalDirection hd) {
	getPlayer(pid)->playerMove(hd);
	selfChanged();
}
void Map::playerStop(QPinBallMacro::PlayerId pid, QPinBallMacro::VerticalDirection vd) {
	getPlayer(pid)->playerStop(vd);
	selfChanged();
}
void Map::playerStop(QPinBallMacro::PlayerId pid, QPinBallMacro::HorizontalDirection hd) {
	getPlayer(pid)->playerStop(hd);
	selfChanged();
}
*/
void Map::playerMove(int pid, int vhd) {
	switch (vhd) {
	case QPinBallMacro::UP:
	case QPinBallMacro::DOWN:
		getPlayer(static_cast<QPinBallMacro::PlayerId>(pid)
			)->playerMove(static_cast<QPinBallMacro::VerticalDirection>(vhd)); break;
	case QPinBallMacro::LEFT:
	case QPinBallMacro::RIGHT:
		getPlayer(static_cast<QPinBallMacro::PlayerId>(pid)
			)->playerMove(static_cast<QPinBallMacro::HorizontalDirection>(vhd)); break;
	default: break;
	}
	selfChanged();
}
void Map::playerStop(int pid, int vhd) {
	switch (vhd) {
	case QPinBallMacro::UP:
	case QPinBallMacro::DOWN:
		getPlayer(static_cast<QPinBallMacro::PlayerId>(pid)
			)->playerStop(static_cast<QPinBallMacro::VerticalDirection>(vhd)); break;
	case QPinBallMacro::LEFT:
	case QPinBallMacro::RIGHT:
		getPlayer(static_cast<QPinBallMacro::PlayerId>(pid)
			)->playerStop(static_cast<QPinBallMacro::HorizontalDirection>(vhd)); break;
	default: break;
	}
	selfChanged();
}

Map::Map() {
	int thick = 5;
	top = new Wall(static_cast<int>(thick/2));
	bottom = new Wall(static_cast<int>(height-thick/2));
	left = new Goal(static_cast<int>(thick/2));
	right = new Goal(static_cast<int>(width-thick/2));
	//ball = new Ball(static_cast<int>(width/2), static_cast<int>(height/2));
	ball = new Ball(100, 100);
	player_one = new Paddle(1, static_cast<int>(width/4), static_cast<int>(height/2), 
		static_cast<int>(height/6), static_cast<int>(height/6*5),
		static_cast<int>(thick*2), static_cast<int>(width/8*3));
	player_two = new Paddle(2, static_cast<int>(width/4*3), static_cast<int>(height/2), 
		static_cast<int>(height/6), static_cast<int>(height/6*5),
		static_cast<int>(width/8*5), static_cast<int>(width-thick*2));

	top->subscribeToBall(ball);
	bottom->subscribeToBall(ball);
	left->subscribeToBall(ball);
	right->subscribeToBall(ball);
	player_one->subscribeToBall(ball);
	player_two->subscribeToBall(ball);

	connect(
		ball, SIGNAL(stepped()),
		this, SLOT(ballStepped()));
}

void Map::ballStepped() {
	selfChanged();
}

int Map::PosX(StaticObject* obj) {
	return obj->getX() - static_cast<int>(obj->getXL()/2);
}
int Map::PosY(StaticObject* obj) {
	return obj->getY() - static_cast<int>(obj->getYL()/2);
}

Paddle* Map::getPlayer(QPinBallMacro::PlayerId pid) { 
	if ( pid == QPinBallMacro::ONE )
		return player_one;
	else if ( pid == QPinBallMacro::TWO )
		return player_two;
	else
		return 0;
}

StaticObject* Map::getObj(QPinBallMacro::ViewId vid) {
	switch (vid) {
	case QPinBallMacro::VIEW_TOP:			return top; break;
	case QPinBallMacro::VIEW_BOTTOM:		return bottom; break;
	case QPinBallMacro::VIEW_LEFT:			return left; break;
	case QPinBallMacro::VIEW_RIGHT:			return right; break;
	case QPinBallMacro::VIEW_BALL:			return ball; break;
	case QPinBallMacro::VIEW_PLAYER_ONE:	return player_one; break;
	case QPinBallMacro::VIEW_PLAYER_TWO:	return player_two; break;
	default:								return 0; break;
	}
}
int Map::getObjPos(int vid, int posparam) {
	StaticObject* obj = getObj(QPinBallMacro::ViewId(vid));
	if (!obj)
		return -1;
	switch (posparam) {
	case QPinBallMacro::POS_X:	return PosX(obj);
	case QPinBallMacro::POS_Y:	return PosY(obj);
	default:					return -1;
	}
}
/*
int Map::getObjPos(QPinBallMacro::ViewId vid, QPinBallMacro::PosParam pos) {
	StaticObject* obj = getObj(vid);
	if (!obj)
		return -1;
	switch (pos) {
	case QPinBallMacro::POS_X:	return PosX(obj);
	case QPinBallMacro::POS_Y:	return PosY(obj);
	default:					return -1;
	}
}
*/
