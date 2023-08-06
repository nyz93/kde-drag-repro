#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <KSystemClipboard>
#include <QMimeData>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    auto clip = KSystemClipboard::instance();
    auto data = new QMimeData();
    data->setText("test");
    clip->setMimeData(data, QClipboard::Clipboard);

    qInfo() << "OK" << clip << endl;

    return app.exec();
}
