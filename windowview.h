#ifndef WINDOWVIEW_H
#define WINDOWVIEW_H

#include <QWidget>

namespace Ui {
class WindowView;
}

class WindowView : public QWidget
{
    Q_OBJECT

public:
    explicit WindowView(QWidget *parent = 0);
    ~WindowView();

private:
    Ui::WindowView *ui;
};

#endif // WINDOWVIEW_H
