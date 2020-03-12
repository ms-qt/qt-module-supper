//
// Created by 毛华伟 on 2020/1/8.
//

#include "Clipboard.h"


Clipboard::Clipboard(QObject *parent) : QObject(parent)
{
    clipboard = QGuiApplication::clipboard();
}

void Clipboard::setText(QString text)
{
    clipboard->setText(text, QClipboard::Clipboard);
}
