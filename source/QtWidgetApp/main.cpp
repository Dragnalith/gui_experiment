#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>

class MyRectangle : public QWidget {
public:  
    MyRectangle(const QColor& color, QWidget* parent = nullptr)
        : QWidget(parent)
        , m_color(color)
    {
        resize(sizeHint());
    }

    virtual QSize sizeHint() const override {
        return QSize(200, 150);
    }

    virtual QSize minimumSizeHint() const override {
        return QSize(200, 150);
    }

    virtual void paintEvent(QPaintEvent* ev) override {
        auto rr = ev->rect();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(m_color, 4));
        auto g = geometry();
        QRect r(QPoint(), size());
        painter.drawRect(r);
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

//#define WITH_LAYOUT

int main(int argc, char** argv) {
    QApplication app(argc, argv);


    MyWidget window;
    window.setWindowTitle("Window");

#ifdef WITH_LAYOUT
    QVBoxLayout* layout = new QVBoxLayout(&window);
    QWidget* parent = nullptr;
#else
    QWidget* parent = &window;
#endif

    MyRectangle* rect = new MyRectangle(Qt::GlobalColor::green, parent);
    auto size = rect->size();
    auto g = rect->geometry();
    auto w = size.width();
    auto h = size.height();
    rect->resize(350, 220);
    rect->move(700, 700);

    auto size2 = rect->size();
    auto g2 = rect->geometry();

    MyPushButton* button = new MyPushButton(parent);
    button->setText("Press Me!");
    auto gb = button->geometry();
    auto gw = gb.width();
    //button->move(100, 0);

#ifdef WITH_LAYOUT
    layout->addWidget(button);
    layout->addWidget(rect);
#endif

    auto windowSize0 = window.size();
    window.show();
    auto windowSize = window.size();

    auto r = window.childrenRect();
    auto rg = window.childrenRegion();

    return app.exec();
}