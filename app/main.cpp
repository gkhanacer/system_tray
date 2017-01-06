#include <QApplication>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMessageBox>
#include "SystemTrayDialog.h"


int main(int argc, char *argv[]) {

    /* Initialize resources */
    Q_INIT_RESOURCE(systemtray);

    /* QApplication instance is created to give management to QT. */
    QApplication app(argc, argv);

    /* Checking whether system support system tray. */
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Remote Office"),
          QObject::tr("System tray is not avaible for this system."));
        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);

    QWidget *hideWidget = new QWidget();

    SystemTrayDialog window(hideWidget);
    // window.show();

    /* Giving application management to QT. */
    return app.exec();
}

#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform.");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
