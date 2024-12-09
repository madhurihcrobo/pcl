#include <QApplication>
#include "QVTKOpenGLWindow.h"

int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  QVTKOpenGLWindow window;
  window.show();
  return app.exec();
}
