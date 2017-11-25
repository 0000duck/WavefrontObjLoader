#include "UI/WavefrontObjLoader.h"
#include "UI/GLWidget.h"
#include "Rendering/MapRenderer.h"
#include "ObjectLoader/ObjLoader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	const int cSize = 1000;

	ObjLoader objLoader(cSize, cSize);
	std::string fileNameTest = "Wavefront/building/building.obj";
	objLoader.LoadOBJ(fileNameTest);

	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(format);

	WavefrontObjLoader mainWindow;
	GLWidget mapWidget(objLoader, mainWindow.getMapWidget());
	mapWidget.setFixedWidth(cSize);
	mapWidget.setFixedHeight(cSize);

	mainWindow.show();
    return a.exec();
}
