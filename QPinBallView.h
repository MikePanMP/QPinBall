#ifndef Q_PIN_BALL_VIEW_H
#define Q_PIN_BALL_VIEW_H

#include "../../QMVC/MVC.h"

#include "QPinBallMacro.h"
#include "QPinBallUtil.h"
#include "QPinBall.h"
#include "QPinBallController.h"

class StaticObject;
class StaticObjectView;
class StaticObjectController;
class Map;
class MapView;
class MapController;
/*
 * StaticObjectView
 */
class StaticObjectView : public MVCView {
public:
	virtual void selfUpdate();
	virtual MVCController* defaultController() {
		return new StaticObjectController(this);
	}
public:
	StaticObjectView(Map* model, QPinBallMacro::ViewId _vid, const char* image, MVCView* parent = 0);
	virtual ~StaticObjectView() {}
private:
	QPinBallMacro::ViewId vid;
};
/*
 * MapView
 */
class MapView : public MVCView {
	enum { width = 800 };
	enum { height = 600 };
public:
	virtual void selfUpdate();
	virtual MVCController* defaultController() {
		return new MapController(this);
	}
public:
	MapView(Map* map);
	virtual ~MapView() {}
private:
	StaticObjectView* top;
	StaticObjectView* bottom;
	StaticObjectView* left;
	StaticObjectView* right;
	StaticObjectView* ball;
	StaticObjectView* player_one;
	StaticObjectView* player_two;
};

#endif // Q_PIN_BALL_VIEW_H