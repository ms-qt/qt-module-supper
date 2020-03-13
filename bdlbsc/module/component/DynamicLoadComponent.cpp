//
// Created by maohuawei on 2020/2/15.
//

#include <QDebug>
#include <QFileInfo>
#include <bdlbsc/module/component/DynamicLoadComponent.h>

namespace bdlbsc
{

    void DynamicLoadComponent::clear()
    {
        m_engine->trimComponentCache();
        m_engine->clearComponentCache();
    }

    DynamicLoadComponent::DynamicLoadComponent(QObject *parent) : QObject(parent)
    {
        connect(&m_fileWatch, SIGNAL(fileChanged(QString)), this, SLOT(onFileChanged(QString)));
        m_engine = qmlEngine();
    }

    DynamicLoadComponent::~DynamicLoadComponent() {}

    QString DynamicLoadComponent::url()
    {
        return m_url;
    }

    void DynamicLoadComponent::setUrl(QString url)
    {
        qDebug() << "void DynamicLoadComponent::setUrl(QString url)";
        QString file = url;
        if (file.startsWith("file:")) {

            qDebug() << "file : " << file;
#ifdef Q_OS_WIN
            QFileInfo fileInfo(file.remove("file:///"));
#endif

#ifdef Q_OS_UNIX
            QFileInfo fileInfo(file.remove("file://"));
#endif

            if (fileInfo.isFile()) {
                m_fileWatch.addPath(file);
                if (!m_monitorFiles.contains(file))
                    m_monitorFiles.append(file);

                qDebug() << " url : " << url;

                m_url = url;
                emit statusChanged();
            }

        } else {
            m_url = url;
            emit statusChanged();
        }
    }

    void DynamicLoadComponent::onFileChanged(QString file)
    {
        qDebug() << "void DynamicLoadComponent::onFileChanged(QString file)";
        qDebug() << "file : " << file;
        foreach (QString file, m_monitorFiles) {
            m_fileWatch.addPath(file);
        }
        qDebug() << "Watch file: " << m_fileWatch.files();
        emit statusChanged();
    }
} // namespace bdlbsc
