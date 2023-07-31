#ifndef INFO2_H
#define INFO2_H

#include <QWidget>

namespace Ui {
class info2;
}

class info2 : public QWidget
{
    Q_OBJECT

public:
    explicit info2(QWidget *parent = nullptr);
    ~info2();

private:
    Ui::info2 *ui;
};

#endif // INFO2_H
