#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>




class ColorfulCircle : public QWidget {
public:
    //Конструктор класса.
    ColorfulCircle(QWidget *parent = nullptr) : QWidget(parent) {
        mGreenCircle = QPixmap("g1.png");
        mYellowCircle = QPixmap("y3.png");
        mRedCircle = QPixmap("r2.png");

        mCurrentCircle = mGreenCircle;

    }
        //Фиксация размера круга при изминении параметров.
    QSize sizeHint() const override {
        return QSize(100, 100);
    }
        //Фиксация размера круга при изминении параметров.
    QSize minimumSizeHint() const override {
        return sizeHint();
    }
        //Рисование круга.
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawPixmap(rect(), mCurrentCircle);
    }

    //Зафиксированные методы.
public slots:
    void setGreen();
    void setYellow();
    void setRed();

    //Параметры круга.
private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap mCurrentCircle;
};


//Функции обновления цвета.
void ColorfulCircle::setGreen() {
       mCurrentCircle = mGreenCircle;
       update();
   }

void ColorfulCircle::setYellow() {
       mCurrentCircle = mYellowCircle;
       update();
   }

void ColorfulCircle::setRed() {
       mCurrentCircle = mRedCircle;
       update();
   }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Созданные объекты.
    auto *window = new QWidget;
    auto *slider = new QSlider(Qt::Horizontal, window);
    auto *circle = new ColorfulCircle(window);
    auto *spinbox = new QSpinBox(window);
    auto *layout = new  QVBoxLayout(window);

    //Фиксация объектов по размеру окна.
    window->setFixedSize(200,250);
    layout->addWidget(circle);
    layout->addWidget(slider);
    layout->addWidget(spinbox);

    //Диапозон размера слайдера и счетчика.
    slider->setRange(0,100);
    spinbox->setRange(0,100);

    //Лямбды связывания объектов слайдер + счетчик, счетчик + слайдер, слайдер + цвет круга.
    QObject::connect(slider, &QSlider::valueChanged, [slider, circle](int newValue) {
           if (newValue <= 33) {
               circle->setGreen();
           } else if (newValue <= 66) {
               circle->setYellow();
           } else {
               circle->setRed();
           }
       });
    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);

    //Запуск окна.
    window->show();


    return a.exec();
}
