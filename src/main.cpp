/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include <QtCore/QDebug>
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeView>

#include "guitartunerplugin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Construct and register the guitar tuner plug-in
    GuitarTunerPlugin guitarTunerPlugin;
    guitarTunerPlugin.registerTypes("GuitarTuner");

    QDeclarativeView view;

#ifdef Q_OS_SYMBIAN
    view.setAttribute(Qt::WA_NoSystemBackground);
#endif

#ifdef MEEGO_EDITION_HARMATTAN
    qDebug() << "isHarmattan => true";
    view.rootContext()->setContextProperty("isHarmattan", true);
#else
    view.rootContext()->setContextProperty("isHarmattan", false);
#endif

    view.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    QObject::connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));
    view.setSource(QUrl("qrc:/main.qml"));

#if defined(Q_OS_SYMBIAN) || defined(MEEGO_EDITION_HARMATTAN) || defined(Q_WS_SIMULATOR)
    view.showFullScreen();
    qDebug() << "Running on mobile or in the simulator.";
#else
    view.setGeometry(100, 100, 360, 640);
    view.show();
#endif

    return app.exec();
}
