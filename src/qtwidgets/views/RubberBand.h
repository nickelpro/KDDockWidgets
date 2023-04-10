/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "View.h"

#include <QRubberBand>

namespace KDDockWidgets {

namespace qtwidgets {

class DOCKS_EXPORT RubberBand : public View_qtwidgets<QRubberBand>
{
    Q_OBJECT
public:
    explicit RubberBand(QWidget *parent = nullptr);
    ~RubberBand() override;
};

}

}