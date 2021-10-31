#include "widgetskeleton.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);  
  WidgetSkeleton window;
  window.resize(500, 200);
  window.setWindowTitle("WidgetSkeleton");
  window.show();
  return app.exec();
}
