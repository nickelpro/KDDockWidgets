/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company
  <info@kdab.com> Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/


#pragma once

#include "View_flutter.h"
#include "views/StackViewInterface.h"

namespace KDDockWidgets {
namespace Views {

class DOCKS_EXPORT Stack_flutter : public View_flutter, public StackViewInterface
{
public:
    explicit Stack_flutter(Controllers::Stack *controller, View *parent = nullptr);

    int numDockWidgets() const override;
    void removeDockWidget(Controllers::DockWidget *) override;
    int indexOfDockWidget(const Controllers::DockWidget *) const override;

    bool isPositionDraggable(QPoint p) const override;
    void init() override;
    void setDocumentMode(bool) override;

public:
    void setCurrentDockWidget(int index) override;
    bool insertDockWidget(int index, Controllers::DockWidget *, const QIcon &,
                          const QString &title) override;
    void renameTab(int index, const QString &) override;
    void changeTabIcon(int index, const QIcon &) override;
    Controllers::DockWidget *dockwidgetAt(int index) const override;
    int currentIndex() const override;

private:
    Q_DISABLE_COPY(Stack_flutter)
};

}
}