#include "bridge.h"
#include <QApplication>
#include <QWebEngineView>
#include <QWebChannel>
#include <QUrl>
int main(int argc,char *argv[]){QApplication app(argc,argv);QApplication::setApplicationName("PelicanExecutor");QApplication::setOrganizationName("Pelican");QWebEngineView view;view.setWindowTitle("PelicanExecutor");view.resize(1180,760);auto *channel=new QWebChannel(&view);auto *bridge=new PelicanBridge(&view);channel->registerObject(QStringLiteral("pelican"),bridge);view.page()->setWebChannel(channel);view.setHtml(PelicanBridge::uiHtml(),QUrl(QStringLiteral("qrc:/pelican/")));view.show();return app.exec();}
