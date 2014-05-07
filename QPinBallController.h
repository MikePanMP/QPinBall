#ifndef Q_PIN_BALL_CONTROLLER_H
#define Q_PIN_BALL_CONTROLLER_H

#include "../../QMVC/MVC.h"

#include "QPinBallMacro.h"
#include "QPinBallUtil.h"
#include "QPinBall.h"
#include "QPinBallView.h"

class StaticObject;
class StaticObjectView;
class StaticObjectController;
class Map;
class MapView;
class MapController;
/*
 * StaticObjectController
 */
class StaticObjectController : public MVCController {
public:
	virtual void keyPressEvent(char key) {
		MVCView* parent = getView()->getMVCParent();
		if (parent)
			parent->getController()->keyPressEvent(key);
	}
	virtual void keyReleaseEvent(char key) {
		MVCView* parent = getView()->getMVCParent();
		if (parent)
			parent->getController()->keyPressEvent(key);
	}
public:
	StaticObjectController(MVCView* view) : MVCController(view) {}
	virtual ~StaticObjectController() {}
};
/*
 * MapController
 */
class MapController : public MVCController {
public:
	virtual void keyPressEvent(char key);
	virtual void keyReleaseEvent(char key);
public:
	MapController(MVCView* view) : MVCController(view) {}
	virtual ~MapController() {}
};

#endif // Q_PIN_BALL_CONTROLLER_H