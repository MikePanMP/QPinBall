#include "QPinBall.h"
#include "QPinBallView.h"

int main(int argc, char *argv[])
{
	MVCApp* app = new MVCApp(argc, argv);
	
	Map model;
	MapView view(&model);
	
	app->addItem(&view);
	app->setFixedSize(803, 603);
	app->show();

	view.setFocus();
	model.gameStart();

	return app->exec();
}
