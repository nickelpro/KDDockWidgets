/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

import 'package:KDDockWidgets/View_mixin.dart';
import 'package:KDDockWidgets/PositionedWidget.dart';
import 'package:KDDockWidgetsBindings/Bindings.dart' as KDDockWidgetBindings;
import 'package:flutter/material.dart';

import 'DockWidget.dart';
import 'TabBar.dart' as kddw;
import 'TitleBar.dart';

class Group extends KDDockWidgetBindings.Group_flutter with View_mixin {
  late final KDDockWidgetBindings.Group m_controller;

  Group(KDDockWidgetBindings.Group? group, KDDockWidgetBindings.View? parent)
      : super(group, parent: parent) {
    m_controller = group!;
    initMixin(this, color: Colors.greenAccent, debugName: "Group");

    print("Group CTOR");
  }

  Widget createFlutterWidget() {
    return GroupWidget(kddwView, this, key: widgetKey);
  }

  TitleBar titleBarView() {
    return KDDockWidgetBindings.View_flutter.fromCache(
        m_controller.titleBar().view().thisCpp) as TitleBar;
  }

  kddw.TabBar tabBarView() {
    return KDDockWidgetBindings.View_flutter.fromCache(
        m_controller.stack().tabBar().view().thisCpp) as kddw.TabBar;
  }

  DockWidget? dockWidgetView() {
    final dw = m_controller.currentDockWidget();
    if (dw.thisCpp.address != 0) // Add "isNullptr"
      return KDDockWidgetBindings.View_flutter.fromCache(dw.view().thisCpp)
          as DockWidget;

    print("Group: No dock widget in the Group!");
    return null;
  }
}

class GroupWidget extends PositionedWidget {
  final Group groupView;
  GroupWidget(var kddwView, this.groupView, {Key? key})
      : super(kddwView, key: key);

  @override
  State<PositionedWidget> createState() {
    return GroupPositionedWidgetState(kddwView, groupView);
  }
}

class GroupPositionedWidgetState extends PositionedWidgetState {
  final Group groupView;

  GroupPositionedWidgetState(var kddwView, this.groupView) : super(kddwView);

  @override
  Widget buildContents() {
    final titleBarWidget = groupView.titleBarView().flutterWidget;
    final tabBarWidget = groupView.tabBarView().flutterWidget;
    final dockWidgetWidget = groupView.dockWidgetView()?.flutterWidget;

    return Column(
      children: [
        titleBarWidget,
        tabBarWidget,
        if (dockWidgetWidget != null)
          dockWidgetWidget
        else
          Expanded(child: Container(color: kddwView.m_color))
      ],
    );
  }
}