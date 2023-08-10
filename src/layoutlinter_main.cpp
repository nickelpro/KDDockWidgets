/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2020-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "Config.h"
#include "qtwidgets/ViewFactory.h"

#include "core/MainWindow.h"
#include "core/DockWidget.h"
#include "core/Platform.h"

#include <QDebug>
#include <QString>
#include <QGuiApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QFileInfo>

#include "nlohmann/json.hpp"

using namespace KDDockWidgets;
using namespace KDDockWidgets::Core;

struct LinterConfig
{
    std::vector<std::string> filesToLint;

    bool isEmpty() const
    {
        return filesToLint.empty();
    }
};

inline void from_json(const nlohmann::json &j, LinterConfig &ls)
{
    ls.filesToLint = j.value("files", std::vector<std::string>());
}

LinterConfig requestedLinterConfig(const QCommandLineParser &parser, const QString &configFile)
{
    LinterConfig c;

    const auto positionalArguments = parser.positionalArguments();
    if (configFile.isEmpty() && positionalArguments.isEmpty()) {
        qWarning() << "Expected either a config file or positional arguments";
        return {};
    } else if (!configFile.isEmpty() && !positionalArguments.isEmpty()) {
        qWarning() << "Expected either a config file or positional arguments, not both";
        return {};
    } else if (!positionalArguments.isEmpty()) {
        std::transform(positionalArguments.begin(), positionalArguments.end(), std::back_inserter(c.filesToLint),
                       [](const QString &str) {
                           return str.toStdString();
                       });
    } else {
        QFile f(configFile);
        if (!f.open(QIODevice::ReadOnly)) {
            qWarning() << "Failed to open" << configFile;
            return {};
        }
        const QByteArray jsonData = f.readAll();
        QDir::setCurrent(QFileInfo(configFile).path());
        nlohmann::json j = nlohmann::json::parse(jsonData, nullptr, /*DisableExceptions=*/true);
        from_json(j, c);
    }

    return c;
}

static bool lint(const QString &filename, RestoreOptions options)
{
    DockWidgetFactoryFunc dwFunc = [](const QString &dwName) {
        return Config::self().viewFactory()->createDockWidget(dwName)->asDockWidgetController();
    };

    MainWindowFactoryFunc mwFunc = [](const QString &mwName, MainWindowOptions mainWindowOptions) {
        return Platform::instance()->createMainWindow(mwName, {}, mainWindowOptions);
    };

    KDDockWidgets::Config::self().setDockWidgetFactoryFunc(dwFunc);
    KDDockWidgets::Config::self().setMainWindowFactoryFunc(mwFunc);

    LayoutSaver restorer(options);
    return restorer.restoreFromFile(filename);
}

int main(int argc, char *argv[])
{
    const auto frontends = Platform::frontendTypes();
    if (frontends.empty()) {
        qWarning() << "Error: Your KDDockWidgets installation doesn't support any frontend!";
        return -1;
    }

    // Just take the 1st frontend, any is fine
    KDDockWidgets::Core::Platform::tests_initPlatform(argc, argv, frontends[0]);

    QCommandLineParser parser;
    parser.setApplicationDescription("KDDockWidgets layout linter");
    parser.addHelpOption();
    QCommandLineOption opt = { { "c", "config" }, "Linter config file", "configfile" };
    parser.addOption(opt);
    parser.addPositionalArgument("layout", "layout json file");
    parser.process(*qApp);

    const LinterConfig lc = requestedLinterConfig(parser, parser.isSet(opt) ? parser.value(opt) : QString());
    if (lc.isEmpty()) {
        qWarning() << "Bailing out";
        return 3;
    }

    const auto options = RestoreOption_None;

    int exitCode = 0;
    for (const std::string &layout : lc.filesToLint) {
        if (!lint(QString::fromStdString(layout), options))
            exitCode = 2;
    }

    KDDockWidgets::Core::Platform::tests_deinitPlatform();
    return exitCode;
}
