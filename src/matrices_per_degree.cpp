#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "matrix.h"
using namespace std;

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/matrices_per_degree.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    {
        Matrix a;
        const QMetaObject meta = Matrix::staticMetaObject;
        QObject *obj = meta.newInstance();
        QObject::connect(obj, SIGNAL(matrixChanged()), obj, SLOT(print()));
        QObject::connect(obj, SIGNAL(sizeChanged()), obj, SLOT(print()));
        meta.invokeMethod(obj, "degree", Q_ARG(int, 2));
        meta.invokeMethod(obj, "getElement", Q_ARG(int, 0), Q_ARG(int, 0));
        meta.invokeMethod(obj, "setElement", Q_ARG(QString, 0), Q_ARG(int, 0), Q_ARG(int, 0));
        meta.invokeMethod(obj, "getSize");
        meta.invokeMethod(obj, "setSize", Q_ARG(int, 3));
        meta.invokeMethod(obj, "reload", Q_ARG(int, 3));
    }


    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/matrices_per_degree.qml"));
    qmlRegisterType<Matrix>("custom.Matrix", 1, 0, "Matrix");
    view->showFullScreen();

    return app->exec();
}
