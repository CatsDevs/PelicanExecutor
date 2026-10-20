#pragma once
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVariantMap>
class PelicanBridge final : public QObject {
 Q_OBJECT
public:
 explicit PelicanBridge(QObject *parent=nullptr);
 Q_INVOKABLE QVariantList listScripts() const;
 Q_INVOKABLE QString readScript(const QString &name) const;
 Q_INVOKABLE bool saveScript(const QString &name,const QString &content);
 Q_INVOKABLE bool deleteScript(const QString &name);
 Q_INVOKABLE QString appVersion() const;
 Q_INVOKABLE QVariantMap attachDemo(const QString &nickname) const;
 static QString uiHtml();
private:
 QString scriptsRoot() const;
 QString safeScriptPath(const QString &name) const;
};
