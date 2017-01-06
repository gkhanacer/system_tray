#include <myclass.h>
#include <SystemTrayDialog.h>
#include <QtWidgets>
#include <QtTest/QtTest>

class SystemTrayDialogTest: public QObject {
    Q_OBJECT
private slots:
    void toUpper();
    void toUpper_data();

    // GUI TESTS
    void testGui();
    void testGui_data();
};

void SystemTrayDialogTest::toUpper()
{
    // QString str = "Hello";
    // QCOMPARE(str.toUpper(), QString("HELLO"));
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

void SystemTrayDialogTest::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void SystemTrayDialogTest::testGui()
{
    //QLineEdit lineEdit;
    //QTest::keyClicks(&lineEdit, "hello world");
    //QCOMPARE(lineEdit.text(), QString("hello world"));

    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;
    events.simulate(&lineEdit);
    QCOMPARE(lineEdit.text(), expected);
}

void SystemTrayDialogTest::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";
}

QTEST_MAIN(SystemTrayDialogTest)
#include "main.moc"
