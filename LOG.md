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
? Why MyRectangle is cropped to a region smaller than its parent window size? How works cropping?
? Does geometry() relative to parent position?
- [ ] Animate widget rendering
? What is a slot?
  A method which can be connected to a signal

# 2020/09/10
? Is it possible to reuse Qt Quick scene graph?
? What is Qt Style Sheet
- Children region is computed on demand looping on all the children widget
- Children is not used for cropping the rendering of children. I have experience cropping where cropping area with the children region when the child is attached to the parent, even if afterward I am changing the geometry of the child. But of course if I change the children geometry, parent->childrenRegion will return a correct value.
- The cropping area issue is not computing during the set parent, because even if set parent is done after child change of geometry I got the same issue.
- The cropping area actually is correctly updated according to geometry only regarding its size. But the cropping area does not take children position into account.
- QWidget has a default size 640,480. This size is modified using the sizeHint when calling QWidget::show();
https://myprogrammingnotes.com/size-qt-widgets-determined.html
- I have discover QWidget::resize and QWidget::move to set size and position instead of QWidget::setGeometry. But it looks to do the same.
- I have tried to use QVBoxLayout. MyRectangle get completely stretched and the fact it is position has been manually modified create issue. In addition their are default margin, which is cumbersome.
- I found my I had cropping bug, it is because the painter coordinate system is relative the current widget and not its parent. So the correct rectangle to render it is not QWidget::geometry() because in that case the rectangle is relative to the parent.