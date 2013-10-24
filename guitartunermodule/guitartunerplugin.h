/**
 * Copyright (c) 2012 Nokia Corporation.
 */

#ifndef GUITARTUNERPLUGIN_H
#define GUITARTUNERPLUGIN_H

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class GuitarTunerPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
    
public:
    void registerTypes(const char *uri);
};

#endif // MYPLUGIN_H
