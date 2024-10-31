#ifndef MYTRANSLATOR_H
#define MYTRANSLATOR_H

#include <QObject>
#include <QGuiApplication>
#include <QQuickView>
#include <QTranslator>
#include "mylang.h"

class MyTranslator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)

public:
    MyTranslator(QGuiApplication* app) { mApp = app; }

    QString getEmptyString() { return ""; }

signals:
    void languageChanged();

public slots:
    void updateLanguage(int lang){
        switch(lang){
        case MyLang::TR:
            mTranslator.load("lang_tr", ":/translator");
            mApp->installTranslator(&mTranslator);
            break;
        case MyLang::AR:
            mTranslator.load("lang_ar", ":/translator");
            mApp->installTranslator(&mTranslator);
            break;
        default:
            mApp->removeTranslator(&mTranslator);
            break;
        }
        emit languageChanged();
    }

private:
    QGuiApplication* mApp;
    QTranslator mTranslator;
};

#endif // MYTRANSLATOR_H
