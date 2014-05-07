#include "QPinBall.h"
#include "QPinBallView.h"
#include "QPinBallController.h"


void MapController::keyPressEvent(char key) {
	Map* map = static_cast<Map*>(getModel());
	switch (key) {
	case 'W':	map->playerMove(QPinBallMacro::ONE, QPinBallMacro::UP); break;
	case 'S':	map->playerMove(QPinBallMacro::ONE, QPinBallMacro::DOWN); break;
	case 'A':	map->playerMove(QPinBallMacro::ONE, QPinBallMacro::LEFT); break;
	case 'D':	map->playerMove(QPinBallMacro::ONE, QPinBallMacro::RIGHT); break;
	case 'I':	map->playerMove(QPinBallMacro::TWO, QPinBallMacro::UP); break;
	case 'K':	map->playerMove(QPinBallMacro::TWO, QPinBallMacro::DOWN); break;
	case 'J':	map->playerMove(QPinBallMacro::TWO, QPinBallMacro::LEFT); break;
	case 'L':	map->playerMove(QPinBallMacro::TWO, QPinBallMacro::RIGHT); break;
	default: break;
	}
}
void MapController::keyReleaseEvent(char key) {
	Map* map = static_cast<Map*>(getModel());
	switch (key) {
	case 'W':	map->playerStop(QPinBallMacro::ONE, QPinBallMacro::UP); break;
	case 'S':	map->playerStop(QPinBallMacro::ONE, QPinBallMacro::DOWN); break;
	case 'A':	map->playerStop(QPinBallMacro::ONE, QPinBallMacro::LEFT); break;
	case 'D':	map->playerStop(QPinBallMacro::ONE, QPinBallMacro::RIGHT); break;
	case 'I':	map->playerStop(QPinBallMacro::TWO, QPinBallMacro::UP); break;
	case 'K':	map->playerStop(QPinBallMacro::TWO, QPinBallMacro::DOWN); break;
	case 'J':	map->playerStop(QPinBallMacro::TWO, QPinBallMacro::LEFT); break;
	case 'L':	map->playerStop(QPinBallMacro::TWO, QPinBallMacro::RIGHT); break;
	default: break;
	}
}