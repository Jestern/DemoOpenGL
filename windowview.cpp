#include "windowview.h"
#include "ui_windowview.h"

WindowView::WindowView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowView)
{
    ui->setupUi(this);
}

WindowView::~WindowView()
{
    delete ui;
}
