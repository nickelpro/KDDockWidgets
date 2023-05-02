/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/
#include "KDDockWidgetsBindings_exports.h"
#include <core/Group.h>
#include <qstring.h>
#include <core/View.h>
#include <core/DockWidget.h>
#include <KDDockWidgets.h>
#include <FloatingWindow.h>
#include "core/Stack.h"
#include <TabBar.h>
#include <qpoint.h>
#include "core/TitleBar.h"
#include <MainWindow.h>
#include <Item_p.h>
#include <qrect.h>
#include <DropArea.h>
#include <core/Layout.h>
#include <qsize.h>

namespace KDDockWidgetsBindings_wrappersNS {
namespace KDDWBindingsCore {
class Group_wrapper : public ::KDDockWidgets::Core::Group
{
public:
    ~Group_wrapper();
    Group_wrapper(KDDockWidgets::Core::View *parent = nullptr);
    KDDockWidgets::Core::TitleBar *actualTitleBar() const;
    void actualTitleBarChanged();
    void addTab(KDDockWidgets::Core::DockWidget *arg__1, KDDockWidgets::InitialOption arg__2 = {});
    void addTab(KDDockWidgets::Core::FloatingWindow *floatingWindow, KDDockWidgets::InitialOption arg__2 = {});
    void addTab(KDDockWidgets::Core::Group *arg__1, KDDockWidgets::InitialOption arg__2 = {});
    bool allDockWidgetsHave(KDDockWidgets::DockWidgetOption arg__1) const;
    bool allDockWidgetsHave(KDDockWidgets::LayoutSaverOption arg__1) const;
    bool alwaysShowsTabs() const;
    bool anyDockWidgetsHas(KDDockWidgets::DockWidgetOption arg__1) const;
    bool anyDockWidgetsHas(KDDockWidgets::LayoutSaverOption arg__1) const;
    bool anyNonClosable() const;
    bool anyNonDockable() const;
    bool beingDeletedLater() const;
    QSize biggestDockWidgetMaxSize() const;
    bool containsDockWidget(KDDockWidgets::Core::DockWidget *w) const;
    bool containsMouse(QPoint globalPos) const;
    KDDockWidgets::Core::DockWidget *currentDockWidget() const;
    int currentIndex() const;
    int currentTabIndex() const;
    static int dbg_numFrames();
    KDDockWidgets::Core::FloatingWindow *detachTab(KDDockWidgets::Core::DockWidget *arg__1);
    KDDockWidgets::Core::DockWidget *dockWidgetAt(int index) const;
    int dockWidgetCount() const;
    QSize dockWidgetsMinSize() const;
    virtual QRect dragRect() const;
    virtual QRect dragRect_nocallback() const;
    KDDockWidgets::Core::FloatingWindow *floatingWindow() const;
    void focusedWidgetChanged();
    virtual void focusedWidgetChangedCallback();
    virtual void focusedWidgetChangedCallback_nocallback();
    bool hasNestedMDIDockWidgets() const;
    bool hasSingleDockWidget() const;
    bool hasTabsVisible() const;
    void hasTabsVisibleChanged();
    int indexOfDockWidget(const KDDockWidgets::Core::DockWidget *arg__1);
    void insertDockWidget(KDDockWidgets::Core::DockWidget *arg__1, int index);
    void insertWidget(KDDockWidgets::Core::DockWidget *arg__1, int index, KDDockWidgets::InitialOption arg__3 = {});
    bool isCentralFrame() const;
    bool isDockable() const;
    bool isEmpty() const;
    bool isFloating() const;
    void isFocusedChanged();
    virtual void isFocusedChangedCallback();
    virtual void isFocusedChangedCallback_nocallback();
    bool isInFloatingWindow() const;
    bool isInMainWindow() const;
    void isInMainWindowChanged();
    bool isMDI() const;
    void isMDIChanged();
    bool isMDIWrapper() const;
    bool isOverlayed() const;
    bool isTheOnlyFrame() const;
    KDDockWidgets::Core::Item *layoutItem() const;
    KDDockWidgets::Core::MainWindow *mainWindow() const;
    KDDockWidgets::Core::DockWidget *mdiDockWidgetWrapper() const;
    KDDockWidgets::Core::DropArea *mdiDropAreaWrapper() const;
    KDDockWidgets::Core::Group *mdiFrame() const;
    int nonContentsHeight() const;
    void numDockWidgetsChanged();
    void onDockWidgetCountChanged();
    void onDockWidgetTitleChanged();
    void removeWidget(KDDockWidgets::Core::DockWidget *arg__1);
    void renameTab(int index, const QString &arg__2);
    void restoreToPreviousPosition();
    void setCurrentDockWidget(KDDockWidgets::Core::DockWidget *arg__1);
    void setCurrentTabIndex(int index);
    void setLayout(KDDockWidgets::Core::Layout *arg__1);
    void setLayoutItem(KDDockWidgets::Core::Item *item);
    virtual void setParentView_impl(KDDockWidgets::Core::View *parent);
    virtual void setParentView_impl_nocallback(KDDockWidgets::Core::View *parent);
    KDDockWidgets::Core::Stack *stack() const;
    KDDockWidgets::Core::TabBar *tabBar() const;
    QString title() const;
    KDDockWidgets::Core::TitleBar *titleBar() const;
    static QString tr(const char *s, const char *c, int n);
    void unoverlay();
    void updateFloatingActions();
    void updateTitleAndIcon();
    void updateTitleBarVisibility();
    int userType() const;
    typedef QRect *(*Callback_dragRect)(void *);
    Callback_dragRect m_dragRectCallback = nullptr;
    typedef void (*Callback_focusedWidgetChangedCallback)(void *);
    Callback_focusedWidgetChangedCallback m_focusedWidgetChangedCallbackCallback = nullptr;
    typedef void (*Callback_isFocusedChangedCallback)(void *);
    Callback_isFocusedChangedCallback m_isFocusedChangedCallbackCallback = nullptr;
    typedef void (*Callback_setParentView_impl)(void *, KDDockWidgets::Core::View *parent);
    Callback_setParentView_impl m_setParentView_implCallback = nullptr;
};
}
}
extern "C" {
// KDDockWidgets::Core::Group::Group(KDDockWidgets::Core::View * parent)
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__constructor_View(void *parent_);
// KDDockWidgets::Core::Group::actualTitleBar() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__actualTitleBar(void *thisObj);
// KDDockWidgets::Core::Group::actualTitleBarChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__actualTitleBarChanged(void *thisObj);
// KDDockWidgets::Core::Group::addTab(KDDockWidgets::Core::DockWidget * arg__1, KDDockWidgets::InitialOption arg__2)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__addTab_DockWidget_InitialOption(void *thisObj, void *arg__1_, void *arg__2_);
// KDDockWidgets::Core::Group::addTab(KDDockWidgets::Core::FloatingWindow * floatingWindow, KDDockWidgets::InitialOption arg__2)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__addTab_FloatingWindow_InitialOption(void *thisObj, void *floatingWindow_, void *arg__2_);
// KDDockWidgets::Core::Group::addTab(KDDockWidgets::Core::Group * arg__1, KDDockWidgets::InitialOption arg__2)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__addTab_Group_InitialOption(void *thisObj, void *arg__1_, void *arg__2_);
// KDDockWidgets::Core::Group::allDockWidgetsHave(KDDockWidgets::DockWidgetOption arg__1) const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__allDockWidgetsHave_DockWidgetOption(void *thisObj, int arg__1);
// KDDockWidgets::Core::Group::allDockWidgetsHave(KDDockWidgets::LayoutSaverOption arg__1) const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__allDockWidgetsHave_LayoutSaverOption(void *thisObj, int arg__1);
// KDDockWidgets::Core::Group::alwaysShowsTabs() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__alwaysShowsTabs(void *thisObj);
// KDDockWidgets::Core::Group::anyDockWidgetsHas(KDDockWidgets::DockWidgetOption arg__1) const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__anyDockWidgetsHas_DockWidgetOption(void *thisObj, int arg__1);
// KDDockWidgets::Core::Group::anyDockWidgetsHas(KDDockWidgets::LayoutSaverOption arg__1) const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__anyDockWidgetsHas_LayoutSaverOption(void *thisObj, int arg__1);
// KDDockWidgets::Core::Group::anyNonClosable() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__anyNonClosable(void *thisObj);
// KDDockWidgets::Core::Group::anyNonDockable() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__anyNonDockable(void *thisObj);
// KDDockWidgets::Core::Group::beingDeletedLater() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__beingDeletedLater(void *thisObj);
// KDDockWidgets::Core::Group::biggestDockWidgetMaxSize() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__biggestDockWidgetMaxSize(void *thisObj);
// KDDockWidgets::Core::Group::containsDockWidget(KDDockWidgets::Core::DockWidget * w) const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__containsDockWidget_DockWidget(void *thisObj, void *w_);
// KDDockWidgets::Core::Group::containsMouse(QPoint globalPos) const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__containsMouse_QPoint(void *thisObj, void *globalPos_);
// KDDockWidgets::Core::Group::currentDockWidget() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__currentDockWidget(void *thisObj);
// KDDockWidgets::Core::Group::currentIndex() const
KDDockWidgetsBindings_EXPORT int c_KDDockWidgets__Core__Group__currentIndex(void *thisObj);
// KDDockWidgets::Core::Group::currentTabIndex() const
KDDockWidgetsBindings_EXPORT int c_KDDockWidgets__Core__Group__currentTabIndex(void *thisObj);
// KDDockWidgets::Core::Group::dbg_numFrames()
KDDockWidgetsBindings_EXPORT int c_static_KDDockWidgets__Core__Group__dbg_numFrames();
// KDDockWidgets::Core::Group::detachTab(KDDockWidgets::Core::DockWidget * arg__1)
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__detachTab_DockWidget(void *thisObj, void *arg__1_);
// KDDockWidgets::Core::Group::dockWidgetAt(int index) const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__dockWidgetAt_int(void *thisObj, int index);
// KDDockWidgets::Core::Group::dockWidgetCount() const
KDDockWidgetsBindings_EXPORT int c_KDDockWidgets__Core__Group__dockWidgetCount(void *thisObj);
// KDDockWidgets::Core::Group::dockWidgetsMinSize() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__dockWidgetsMinSize(void *thisObj);
// KDDockWidgets::Core::Group::dragRect() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__dragRect(void *thisObj);
// KDDockWidgets::Core::Group::floatingWindow() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__floatingWindow(void *thisObj);
// KDDockWidgets::Core::Group::focusedWidgetChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__focusedWidgetChanged(void *thisObj);
// KDDockWidgets::Core::Group::focusedWidgetChangedCallback()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__focusedWidgetChangedCallback(void *thisObj);
// KDDockWidgets::Core::Group::hasNestedMDIDockWidgets() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__hasNestedMDIDockWidgets(void *thisObj);
// KDDockWidgets::Core::Group::hasSingleDockWidget() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__hasSingleDockWidget(void *thisObj);
// KDDockWidgets::Core::Group::hasTabsVisible() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__hasTabsVisible(void *thisObj);
// KDDockWidgets::Core::Group::hasTabsVisibleChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__hasTabsVisibleChanged(void *thisObj);
// KDDockWidgets::Core::Group::indexOfDockWidget(const KDDockWidgets::Core::DockWidget * arg__1)
KDDockWidgetsBindings_EXPORT int c_KDDockWidgets__Core__Group__indexOfDockWidget_DockWidget(void *thisObj, void *arg__1_);
// KDDockWidgets::Core::Group::insertDockWidget(KDDockWidgets::Core::DockWidget * arg__1, int index)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__insertDockWidget_DockWidget_int(void *thisObj, void *arg__1_, int index);
// KDDockWidgets::Core::Group::insertWidget(KDDockWidgets::Core::DockWidget * arg__1, int index, KDDockWidgets::InitialOption arg__3)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__insertWidget_DockWidget_int_InitialOption(void *thisObj, void *arg__1_, int index, void *arg__3_);
// KDDockWidgets::Core::Group::isCentralFrame() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isCentralFrame(void *thisObj);
// KDDockWidgets::Core::Group::isDockable() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isDockable(void *thisObj);
// KDDockWidgets::Core::Group::isEmpty() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isEmpty(void *thisObj);
// KDDockWidgets::Core::Group::isFloating() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isFloating(void *thisObj);
// KDDockWidgets::Core::Group::isFocusedChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__isFocusedChanged(void *thisObj);
// KDDockWidgets::Core::Group::isFocusedChangedCallback()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__isFocusedChangedCallback(void *thisObj);
// KDDockWidgets::Core::Group::isInFloatingWindow() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isInFloatingWindow(void *thisObj);
// KDDockWidgets::Core::Group::isInMainWindow() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isInMainWindow(void *thisObj);
// KDDockWidgets::Core::Group::isInMainWindowChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__isInMainWindowChanged(void *thisObj);
// KDDockWidgets::Core::Group::isMDI() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isMDI(void *thisObj);
// KDDockWidgets::Core::Group::isMDIChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__isMDIChanged(void *thisObj);
// KDDockWidgets::Core::Group::isMDIWrapper() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isMDIWrapper(void *thisObj);
// KDDockWidgets::Core::Group::isOverlayed() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isOverlayed(void *thisObj);
// KDDockWidgets::Core::Group::isTheOnlyFrame() const
KDDockWidgetsBindings_EXPORT bool c_KDDockWidgets__Core__Group__isTheOnlyFrame(void *thisObj);
// KDDockWidgets::Core::Group::layoutItem() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__layoutItem(void *thisObj);
// KDDockWidgets::Core::Group::mainWindow() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__mainWindow(void *thisObj);
// KDDockWidgets::Core::Group::mdiDockWidgetWrapper() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__mdiDockWidgetWrapper(void *thisObj);
// KDDockWidgets::Core::Group::mdiDropAreaWrapper() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__mdiDropAreaWrapper(void *thisObj);
// KDDockWidgets::Core::Group::mdiFrame() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__mdiFrame(void *thisObj);
// KDDockWidgets::Core::Group::nonContentsHeight() const
KDDockWidgetsBindings_EXPORT int c_KDDockWidgets__Core__Group__nonContentsHeight(void *thisObj);
// KDDockWidgets::Core::Group::numDockWidgetsChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__numDockWidgetsChanged(void *thisObj);
// KDDockWidgets::Core::Group::onDockWidgetCountChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__onDockWidgetCountChanged(void *thisObj);
// KDDockWidgets::Core::Group::onDockWidgetTitleChanged()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__onDockWidgetTitleChanged(void *thisObj);
// KDDockWidgets::Core::Group::removeWidget(KDDockWidgets::Core::DockWidget * arg__1)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__removeWidget_DockWidget(void *thisObj, void *arg__1_);
// KDDockWidgets::Core::Group::renameTab(int index, const QString & arg__2)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__renameTab_int_QString(void *thisObj, int index, const char *arg__2_);
// KDDockWidgets::Core::Group::restoreToPreviousPosition()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__restoreToPreviousPosition(void *thisObj);
// KDDockWidgets::Core::Group::setCurrentDockWidget(KDDockWidgets::Core::DockWidget * arg__1)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__setCurrentDockWidget_DockWidget(void *thisObj, void *arg__1_);
// KDDockWidgets::Core::Group::setCurrentTabIndex(int index)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__setCurrentTabIndex_int(void *thisObj, int index);
// KDDockWidgets::Core::Group::setLayout(KDDockWidgets::Core::Layout * arg__1)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__setLayout_Layout(void *thisObj, void *arg__1_);
// KDDockWidgets::Core::Group::setLayoutItem(KDDockWidgets::Core::Item * item)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__setLayoutItem_Item(void *thisObj, void *item_);
// KDDockWidgets::Core::Group::setParentView_impl(KDDockWidgets::Core::View * parent)
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__setParentView_impl_View(void *thisObj, void *parent_);
// KDDockWidgets::Core::Group::stack() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__stack(void *thisObj);
// KDDockWidgets::Core::Group::tabBar() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__tabBar(void *thisObj);
// KDDockWidgets::Core::Group::title() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__title(void *thisObj);
// KDDockWidgets::Core::Group::titleBar() const
KDDockWidgetsBindings_EXPORT void *c_KDDockWidgets__Core__Group__titleBar(void *thisObj);
// KDDockWidgets::Core::Group::tr(const char * s, const char * c, int n)
KDDockWidgetsBindings_EXPORT void *c_static_KDDockWidgets__Core__Group__tr_char_char_int(const char *s, const char *c, int n);
// KDDockWidgets::Core::Group::unoverlay()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__unoverlay(void *thisObj);
// KDDockWidgets::Core::Group::updateFloatingActions()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__updateFloatingActions(void *thisObj);
// KDDockWidgets::Core::Group::updateTitleAndIcon()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__updateTitleAndIcon(void *thisObj);
// KDDockWidgets::Core::Group::updateTitleBarVisibility()
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__updateTitleBarVisibility(void *thisObj);
// KDDockWidgets::Core::Group::userType() const
KDDockWidgetsBindings_EXPORT int c_KDDockWidgets__Core__Group__userType(void *thisObj);
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__destructor(void *thisObj);
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
KDDockWidgetsBindings_EXPORT void c_KDDockWidgets__Core__Group_Finalizer(void *, void *cppObj, void *);
}