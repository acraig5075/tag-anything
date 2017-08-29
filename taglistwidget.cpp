#include "taglistwidget.h"
#include <QMenu>

TagListWidget::TagListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);

    QObject::connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
}

void TagListWidget::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Delete", this, SLOT(removeSelectedItem()));

    myMenu.exec(globalPos);
}

void TagListWidget::removeSelectedItem()
{
    QList<QListWidgetItem *> selection = selectedItems();
    if (!selection.isEmpty())
    {
        QListWidgetItem *item = selection[0];
        delete item;
    }
}

QStringList TagListWidget::toStringList()
{
    QStringList tags;
    for (int i = 0; i < count(); ++i)
    {
        tags.push_back(item(i)->text());
    }

    return tags;
}
