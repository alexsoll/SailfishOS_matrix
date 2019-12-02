# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = matrices_per_degree

CONFIG += sailfishapp

SOURCES += src/matrices_per_degree.cpp \
    src/matrix.cpp

DISTFILES += qml/matrices_per_degree.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/matrices_per_degree.changes.in \
    rpm/matrices_per_degree.changes.run.in \
    rpm/matrices_per_degree.spec \
    rpm/matrices_per_degree.yaml \
    translations/*.ts \
    matrices_per_degree.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/matrices_per_degree-de.ts

HEADERS += \
    src/matrix.h
