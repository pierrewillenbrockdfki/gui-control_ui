#ifndef CONTROLBOTPLUGIN_H
#define CONTROLBOTPLUGIN_H

#include <QtGui>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class ControlUiPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")

public:
    ControlUiPlugin(QObject *parent = 0);
    virtual ~ControlUiPlugin();

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget* createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized; 
};

#endif /* CONTROLBOTPLUGIN_H */  
