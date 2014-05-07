#include "QPinBall.h"
#include "QPinBallView.h"
#include "QPinBallController.h"

void StaticObjectView::selfUpdate() {
	Map* model = static_cast<Map*>(getModel());
	int x = model->getObjPos(vid, QPinBallMacro::POS_X);
	int y = model->getObjPos(vid, QPinBallMacro::POS_Y);

	setPos(x, y);
}

StaticObjectView::StaticObjectView(Map* model, QPinBallMacro::ViewId _vid, const char* image, MVCView* parent) 
	: MVCView(model, MVCMacro::VIEW_TYPE_PIXMAP, parent), vid(_vid) {
		init();
		displayImage(image);
		selfUpdate();
}

void MapView::selfUpdate() {
}

MapView::MapView(Map* map) : MVCView(map, MVCMacro::VIEW_TYPE_PIXMAP) {
	init();
	displayImage("Resources/map.png");
	top = new StaticObjectView(map, QPinBallMacro::VIEW_TOP, "Resources/wall.png", this);
	bottom = new StaticObjectView(map, QPinBallMacro::VIEW_BOTTOM, "Resources/wall.png", this);
	left = new StaticObjectView(map, QPinBallMacro::VIEW_LEFT, "Resources/goal.png", this);
	right = new StaticObjectView(map, QPinBallMacro::VIEW_RIGHT, "Resources/goal.png", this);
	ball = new StaticObjectView(map, QPinBallMacro::VIEW_BALL, "Resources/ball.png", this);
	player_one = new StaticObjectView(map, QPinBallMacro::VIEW_PLAYER_ONE, "Resources/paddle.png", this);
	player_two = new StaticObjectView(map, QPinBallMacro::VIEW_PLAYER_TWO, "Resources/paddle.png", this);
}