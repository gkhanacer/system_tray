#include "SystemTrayDialog.h"

#ifndef QT_NO_SYSTEMTRAYICON

#include <QAction>
#include <QCoreApplication>
#include <QCloseEvent>
#include <QMenu>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>

SystemTrayDialog::SystemTrayDialog(QWidget *parent)
  : QDialog(parent)
{
  icon = QIcon(":/images/logo200_200.png");
  createActions();
  createTrayIcon();
  setIcon();

  trayIcon->show();

  setWindowTitle(tr("Remote Office"));
  resize(400, 300);
}

SystemTrayDialog::~SystemTrayDialog()
{

}

void SystemTrayDialog::setVisible(bool visible) {
//  minimizeAction->setEnabled(visible);
//  maximizeAction->setEnabled(!isMaximized());
//  remoteOfficeAction->setEnabled(isMaximized() || !visible);
  QDialog::setVisible(visible);
}

void SystemTrayDialog::closeEvent(QCloseEvent *event) {
#ifdef Q_OS_OSX
    if (!event->spontaneous() || !isVisible()) {
        return;
    }
#endif
    if (trayIcon->isVisible()) {
        //qApp->processEvents();
        trayIcon->showMessage(tr("Remote Office"), tr("The program will keep running in the "
                             "system tray. To terminate the program, "
                             "choose Quit in the context menu."));
        hide();
        event->ignore();
        qDebug("trayIcon message is showed.");
    }
}

void SystemTrayDialog::setIcon() {

  trayIcon->setIcon(icon);
  setWindowIcon(icon);
  trayIcon->setToolTip("Remote Office");
}

void SystemTrayDialog::createActions() {
  remoteOfficeAction = new QAction(tr("&Remote Office"), this);
  connect(remoteOfficeAction, &QAction::triggered, this, &QWidget::showNormal);

  quitAction = new QAction(tr("&Quit"), this);
  connect(quitAction, &QAction::triggered, this, &SystemTrayDialog::quitApplication);
}

void SystemTrayDialog::createTrayIcon() {
  trayIconMenu = new QMenu(this);
  trayIconMenu->addAction(remoteOfficeAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(quitAction);

  trayIcon = new QSystemTrayIcon(this);
  trayIcon->setContextMenu(trayIconMenu);
}

void SystemTrayDialog::quitApplication() {
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Quit", "Are you sure you want to exit the program?",
                                QMessageBox::Yes|QMessageBox::No);
  if (reply == QMessageBox::Yes) {
    qDebug() << "Yes was clicked";
    QCoreApplication::quit();
  } else {
    qDebug() << "Yes was *not* clicked";
  }
}

#endif
