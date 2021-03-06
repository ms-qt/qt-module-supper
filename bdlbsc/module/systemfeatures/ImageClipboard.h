﻿#ifndef IMAGECLIPBOARD_H
#define IMAGECLIPBOARD_H

#include <QClipboard>
#include <QImage>
#include <QObject>

// 图片复制剪切板

class ImageClipboard : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool hasImage READ hasImage NOTIFY imageChanged)
  Q_PROPERTY(QImage image READ image NOTIFY imageChanged)

 public:
  explicit ImageClipboard(QObject* parent = nullptr);

  bool hasImage() const;
  QImage image() const;

  Q_INVOKABLE bool saveImage(const QUrl& localPath);

 private:
  QClipboard* m_clipboard;

 signals:
  void imageChanged();
};

#endif  // IMAGECLIPBOARD_H
