#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>

class MyRectangle : public QWidget {
public:  
    MyRectangle(const QColor& color, QWidget* parent = nullptr)
        : QWidget(parent)
        , m_color(color)
    {
        setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
    }

    virtual QSize sizeHint() const override {
        return QSize(200, 150);
    }

    virtual void paintEvent(QPaintEvent* ev) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(m_color, 4));
        auto g = geometry();
        painter.drawRect(g);
    }
private:
    QColor m_color;
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);


    QWidget window;
    window.setWindowTitle("Window");
    window.setFixedSize(800, 600);
    QPushButton* button = new QPushButton(&window);
    button->setText("Press Me!");
    MyRectangle* rect = new MyRectangle(Qt::GlobalColor::green, &window);
    auto g = rect->geometry();
    g.setX(g.x() + 10);
    rect->setGeometry(g);

    window.show();

    return app.exec();
}