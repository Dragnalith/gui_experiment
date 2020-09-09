# 2020/09/07
- I did not find any quick system independent may to make Qt being found by CMake
- I have added a cmake function to copy Qt dll next to build executable
- It is possible to setup debug in Qt sources by adding Qt source folder to debug file source property of the solution
- By using the windeployqt.exe as post build step you can automatically copy necessary dependency next to the built executable

# 2020/09/09
- Q_D is a macro to get the private pimpl pointer of a Qt class
- Q_Q is a macro to get the public class from a pimpl
- When an area is invalidate by the system, it generate an exposeEvent to the corresponding window. The window knows the root widget and use a QWidgetRepaintManager to recursively send paint event to the widget tree. It recursively call QWidgetPrivate::drawWidget which call "paintEvent" method.
- Because QWidget inherit from QPaintDevice, it is possible to create a QPainter using a QWidget
- Qt Widget style system seems to have baked a fixed number of ui element (menu, button, etc). So you can draw you custom widget using the baked ui element as primitive.
- [ ] Create custom widget with rectangle and position them  with custom layout
? Why MyRectangle is cropped to a region smaller than its parent window size
- [ ] Animate widget rendering