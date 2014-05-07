#ifndef Q_PIN_BALL_MACRO_H
#define Q_PIN_BALL_MACRO_H

namespace QPinBallMacro {
	enum PlayerId {
		ONE = 1100,
		TWO
	};

	enum VerticalDirection {
		UP = 1200,
		DOWN
	};

	enum HorizontalDirection {
		LEFT = 1250,
		RIGHT
	};

	enum BallCollision {
		FROM_UP = 1300,
		FROM_DOWN,
		FROM_LEFT,
		FROM_RIGHT
	};

	enum ViewId {
		VIEW_TOP = 1350,
		VIEW_BOTTOM,
		VIEW_LEFT,
		VIEW_RIGHT,
		VIEW_BALL,
		VIEW_PLAYER_ONE,
		VIEW_PLAYER_TWO
	};

	enum PosParam {
		POS_X = 1400,
		POS_Y
	};
}

#endif // Q_PIN_BALL_MACRO_H