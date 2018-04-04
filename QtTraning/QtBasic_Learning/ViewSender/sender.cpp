/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <string.h>
#include <QtWidgets>
#include <QtNetwork>

#include <QApplication>
#include <QDesktopWidget>

#include "sender.h"

Sender::Sender(QWidget *parent)
    : QWidget(parent)
{
    strcpy(imageType, "JPG");
    port = 9248;
    T = 16;

    //shotSize.setHeight(360);
    //shotSize.setWidth(640);
    shotSize.setHeight(180);
    shotSize.setWidth(320);

    viewLabel = new QLabel();
    pixmap = new QPixmap();
    datagram = new QByteArray();
    buffer = new QBuffer(datagram);
//    buffer->open(QIODevice::WriteOnly);

    startButton = new QPushButton(tr("Start"));
    pauseButton = new QPushButton(tr("Pause"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(pauseButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    timer = new QTimer(this);
//! [0]
    udpSocket = new QUdpSocket(this);
//! [0]

    connect( startButton, SIGNAL(clicked()), this, SLOT(startS()));
    connect( pauseButton, SIGNAL(clicked()), this, SLOT(pauseS()));
    connect( quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect( timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget( viewLabel );
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("View Sender"));
}

Sender::~Sender()
{
    delete startButton;
    delete pauseButton;
    delete quitButton;

    delete buttonBox;
    delete udpSocket;

    delete viewLabel;
    delete pixmap;
    delete buffer;
    delete datagram;

    delete timer;
    delete mainLayout;
}


void Sender::broadcastDatagram()
{
//! [1]
//!

//    *(pixmap) = QPixmap::grabWindow(
//                QApplication::desktop()->winId());

    *(pixmap) = QPixmap::grabWindow(
                QApplication::desktop()->winId(),
                200, 300, shotSize.width(), shotSize.height());

// Debug
//    viewLabel->setPixmap( *pixmap );

    datagram->clear();
    buffer->open(QIODevice::WriteOnly);
    pixmap->save(buffer, imageType);

    qDebug() << datagram->size();
    udpSocket->writeDatagram(datagram->data(), datagram->size(),
                             QHostAddress::Broadcast, port);
    buffer->close();
}


void Sender::startS()
{
    startButton->setEnabled(false);
    timer->start(T);
}

void Sender::pauseS()
{
    startButton->setEnabled(true);
    timer->stop();
}
