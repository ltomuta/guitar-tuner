/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

import QtQuick 1.1
import com.nokia.symbian 1.1

Window {
    id: root
    inPortrait: true

    Page {
        orientationLock: PageOrientation.LockPortrait
    }

    GuitarTunerPanel {
        anchors.fill: parent
    }
}
