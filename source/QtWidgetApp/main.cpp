#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>

class MyRectangle : public QWidget {
public:  
    MyRectangle(const QColor& color, QWidget* parent = nullptr)
        : QWidget(parent)
        , m_color(color)
    {
        //setGeometry(0, 0, 200, 150);
    }

    virtual QSize sizeHint() const override {
        return QSize(200, 150);
    }

    virtual void paintEvent(QPaintEvent* ev) override {
        auto rr = ev->rect();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(m_color, 4));
        auto g = geometry();
        painter.drawRect(g);
    }
private:
    QColor m_color;
};

class MyPushButton : public QPushButton
{
public:
    MyPushButton(QWidget* parent)
        : QPushButton(parent)
    {}

    virtual void paintEvent(QPaintEvent* ev) override {
        auto rr = ev->rect();

        QPushButton::paintEvent(ev);
    }
}; 

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget* parent = nullptr)
        : QWidget(parent)
    {}

    virtual QSize sizeHint() const override {
        return QSize(800, 800);
    }

    virtual void paintEvent(QPaintEvent* ev) override {
        auto rr = ev->rect();

        QWidget::paintEvent(ev);
    }
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);


    MyWidget window;
    window.setWindowTitle("Window");
    MyPushButton* button = new MyPushButton(&window);
    auto gb = button->geometry();
    auto gw = gb.width();
    gb.setX(gb.x() + 100);
    gb.setWidth(gw);
    button->setGeometry(gb);
    button->setText("Press Me!");
    MyRectangle* rect = new MyRectangle(Qt::GlobalColor::green, &window);
    auto size = rect->size();
    auto g = rect->geometry();
    auto w = g.width();
    auto h = g.height();
    g.setX(g.x() + 50);
    g.setY(g.y() + 20);
    g.setWidth(w);
    g.setHeight(h);
    rect->setGeometry(g);
    auto g2 = rect->geometry();

    auto windowSize0 = window.size();
    window.show();
    auto windowSize = window.size();

    auto r = window.childrenRect();
    auto rg = window.childrenRegion();

    return app.exec();
}