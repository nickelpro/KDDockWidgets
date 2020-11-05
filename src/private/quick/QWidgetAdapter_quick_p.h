/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2020 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

/**
 * @file
 * @brief A class that is QWidget when building for QtWidgets, and QObject when building for QtQuick.
 *
 * Allows to have the same code base supporting both stacks.
 *
 * @author Sérgio Martins \<sergio.martins@kdab.com\>
 */

#ifndef KDDOCKWIDGETS_QWIDGETADAPTERQUICK_P_H
#define KDDOCKWIDGETS_QWIDGETADAPTERQUICK_P_H

#include "../../docks_export.h"
#include "Item_p.h"

#include <QQuickItem>
#include <QObject>
#include <QCloseEvent>
#include <QSizePolicy>
#include <QQuickWindow>

QT_BEGIN_NAMESPACE
class QWindow;
class QQmlEngine;
QT_END_NAMESPACE

namespace KDDockWidgets {

namespace Private {

DOCKS_EXPORT QQuickItem* widgetForWindow(QWindow *window);

/// @brief Helper since QQuickItem::parentItem() has a different name than QWidget::parentWidget()
inline QQuickItem *parentWidget(QQuickItem *item)
{
    return item ? item->parentItem() : nullptr;
}

inline bool isMinimized(const QQuickItem *item)
{
    QWindow *window = item ? item->window() : nullptr;
    return KDDockWidgets::Private::isMinimized(window);
}

inline QRect geometry(const QQuickItem *item)
{
    QRect r(QPoint(0 , 0), item->size().toSize());
    r.moveTopLeft(QPointF(item->x(), item->y()).toPoint());
    return r;
}

inline QWindow *windowForWidget(const QQuickItem *item)
{
    return item ? item->window() : nullptr;
}

} // namespace Private

class FloatingWindow;
class DOCKS_EXPORT QWidgetAdapter : public QQuickItem
{
    Q_OBJECT
public:
    explicit QWidgetAdapter(QQuickItem *parent = nullptr, Qt::WindowFlags f = {});
    ~QWidgetAdapter() override;

    ///@brief returns the FloatingWindow this widget is in, otherwise nullptr
    FloatingWindow *floatingWindow() const;

    void setFlag(Qt::WindowType, bool on = true);

    int x() const { return int(QQuickItem::x()); }
    int y() const { return int(QQuickItem::y()); }
    int width() const { return int(QQuickItem::width()); }
    int height() const { return int(QQuickItem::height()); }

    virtual void setGeometry(QRect);
    QRect geometry() const;
    QRect rect() const;
    QPoint pos() const;
    void show();
    void setFixedHeight(int);
    void setFixedWidth(int);
    void raise();
    void update() {}

    QSize size() const { return QQuickItem::size().toSize(); }
    virtual QSize minimumSizeHint() const { return minimumSize(); }
    QSize minimumSize() const;
    QSize maximumSize() const;
    int minimumHeight() const { return minimumSize().height(); }
    int minimumWidth() const { return minimumSize().width(); }
    bool hasFixedWidth() const { return false; }
    bool hasFixedHeight() const { return false; }
    int maximumWidth() const { return maximumSize().width(); }
    int maximumHeight() const { return maximumSize().height(); }
    WId winId() const;

    void grabMouse();
    void releaseMouse();
    void setMinimumSize(QSize);
    void setMinimumSize(int w, int h);
    void setMaximumSize(QSize sz);
    void setMaximumSize(int w, int h);
    void updateGeometry();
    void resize(QSize);
    void resize(int w, int h);
    bool isWindow() const { return parentItem() == nullptr; }
    bool isMaximized() const;
    bool isActiveWindow() const;
    void showMaximized();
    void showMinimized();
    void showNormal();

    QWindow *windowHandle() const;
    QWidgetAdapter *window() const;
    QWidgetAdapter *parentWidget() const;
    QPoint mapToGlobal(QPoint pt) const;
    QPoint mapFromGlobal(QPoint) const;
    QPoint mapTo(const QQuickItem *parent, const QPoint &pos) const;
    bool testAttribute(Qt::WidgetAttribute) const;
    void setAttribute(Qt::WidgetAttribute, bool enabled = true);

    void setWindowTitle(const QString &);
    void setWindowIcon(const QIcon &);
    void close();
    QQuickItem *childAt(QPoint) const;
    void move(int x, int y);
    void move(QPoint);

    void setParent(QQuickItem*);
    void activateWindow();
    void setSizePolicy(QSizePolicy);
    QSizePolicy sizePolicy() const;
    Qt::FocusPolicy focusPolicy() const;
    void setFocusPolicy(Qt::FocusPolicy) {}
    void setFocusProxy(QQuickItem*);
    void setFocus(Qt::FocusReason);
    virtual QSize sizeHint() const;

    void setWindowFlag(int flag, bool enable = true);
    Qt::WindowFlags windowFlags() const;
    void setWindowOpacity(qreal);

    void render(QPainter *);

    static QQuickItem *createItem(QQmlEngine *, const QString &filename);
    static void makeItemFillParent(QQuickItem *item);
Q_SIGNALS:
    void parentChanged();
    void geometryUpdated(); // similar to QLayout stuff, when size constraints change
protected:
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    void raiseAndActivate();
    virtual bool onResize(QSize newSize);
    virtual void onLayoutRequest();
    virtual void onMousePress();
    virtual void onMouseMove(QPoint globalPos);
    virtual void onMouseRelease();
    virtual void onCloseEvent(QCloseEvent *);
    void itemChange(QQuickItem::ItemChange, const QQuickItem::ItemChangeData &) override;
private:
    QSize m_sizeHint;
    QSizePolicy m_sizePolicy = QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);;
    Qt::WindowFlags m_windowFlags;
    int m_widgetAttributes = 0; // Qt::WidgetAttribute
};

}

#endif
