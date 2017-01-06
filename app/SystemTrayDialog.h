#ifndef SYSTEMTRAYDIALOG_H
#define SYSTEMTRAYDIALOG_H


#include <QSystemTrayIcon>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QDialog>

QT_BEGIN_NAMESPACE
class QAction;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QSpinBox;
class QTextEdit;
QT_END_NAMESPACE

class SystemTrayDialog : public QDialog
{
  Q_OBJECT

public:
  SystemTrayDialog(QWidget *parent = 0);
  ~SystemTrayDialog();

  void setVisible(bool visible) Q_DECL_OVERRIDE;

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
  void createActions();
  void createTrayIcon();
  void setIcon();

  QIcon icon;

  QAction *remoteOfficeAction;
  QAction *quitAction;

  QSystemTrayIcon *trayIcon;
  QMenu *trayIconMenu;

private slots:
  void quitApplication();
};

#endif // QT_NO_SYSTEMTRAYICON

#endif // SYSTEMTRAYDIALOG_H
