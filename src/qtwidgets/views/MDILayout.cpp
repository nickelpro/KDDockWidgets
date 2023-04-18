/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "MDILayout.h"
#include "kddockwidgets/core/MDILayout.h"

using namespace KDDockWidgets;
using namespace KDDockWidgets::qtwidgets;

MDILayout::MDILayout(Core::MDILayout *controller, Core::View *parent)
    : qtwidgets::View<QWidget>(controller, Core::ViewType::MDILayout, qtcommon::View_qt::asQWidget(parent))
    , m_controller(controller)
{
    Q_ASSERT(controller);
}

MDILayout::~MDILayout()
{
    if (!freed())
        m_controller->viewAboutToBeDeleted();
}
