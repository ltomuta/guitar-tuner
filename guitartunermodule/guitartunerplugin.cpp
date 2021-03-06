/**
 * Copyright (c) 2012-2014 Microsoft Mobile.
 */

#include "guitartunerplugin.h"
#include "guitartuner.h"

void GuitarTunerPlugin::registerTypes(const char *uri)
{
    // @uri mymodule
    qmlRegisterType<GuitarTuner>(uri, 1, 0, "GuitarTuner");
    qRegisterMetaType<GuitarTuner::String>("String");
}
