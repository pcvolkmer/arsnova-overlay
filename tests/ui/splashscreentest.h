/***************************************************************************
 *   Copyright (C) 2012  Paul-Christian Volkmer
 *   <paul-christian.volkmer@mni.thm.de>
 *
 *   This file is part of ARSnovawidget.
 *
 *   ARSnovawidget is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   ARSnovawidget is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with ARSnovawidget.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef SPLASHSCREENTEST_H
#define SPLASHSCREENTEST_H

#include <QTest>
#include <memory>

#include "ui/splashscreen.h"

class SplashScreenTest : public QObject {

    Q_OBJECT

public:
    explicit SplashScreenTest ( QObject* parent = 0 );

private:
    std::shared_ptr<SplashScreen> splashScreen;

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testShouldShowSplashScreen();

};

#endif // SPLASHSCREENTEST_H
