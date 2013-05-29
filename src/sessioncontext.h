/***************************************************************************
 *   Copyright (C) 2012  Paul-Christian Volkmer
 *   <paul-christian.volkmer@mni.thm.de>
 *
 *   This file is part of ARSnovaDesktop.
 *
 *   ARSnovaDesktop is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   ARSnovaDesktop is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with ARSnovaDesktop.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef SESSIONCONTEXT_H
#define SESSIONCONTEXT_H

#include <QtCore>
#include "httpconnection.h"

/** @brief SessionContext holds the context of a session.
 *
 * Objects of this class will hold the context of a session.
 * This includes information about the latest responses and the session itself
 * They provide methods to enable other components to access all public
 * information about a session.
 *
 * @author Paul-Christian Volkmer <paul-christian.volkmer@mni.thm.de>
 */
class SessionContext : public QObject {

    Q_OBJECT

public:
    /** ViewType the session should be visible
     */
    enum ViewType {
        DIAGRAM_VIEW,
        ICON_VIEW
    };

    /** Creates session context for an unused connection
     * You are required to request a session for the given connection by yourself!
     * @param connection The connection to the servers session
     */
    explicit SessionContext ( AbstractConnection * connection );
    /** A static function that creates session context for a session key and given connection
     * @param connection The connection to the servers session
     * @param sessionKey The session key of the session it should connect to
     * @return A new session context
     */
    static SessionContext * create ( AbstractConnection * connection, QString sessionKey );
    /** Returns the session ID if SessionContext is valid
     * @return The session ID
     */
    QString sessionId();
    /** Indicates if the connected session is valid.
     * This will be TRUE if the server knows a session with the session key
     * used in the connection object.
     * @return Will return TRUE if valid
     */
    bool isValid();
    /** Returns the connection used in this session context
     * @return The Connection
     */
    AbstractConnection * connection();
    /** Sends signal with new view type and stores value
     * @param viewType New ViewType to be selected
     */
    void setViewType ( ViewType viewType );
    /** Returns actual view type
     * @return Actual view type
     */
    ViewType viewType();

private:
    QString _sessionId;
    bool _isValid;
    AbstractConnection * _connection;
    ViewType _viewType;

private slots:
    void onUnderstandingResponse ( UnderstandingResponse response );
    void onSessionResponse ( SessionResponse response );

signals:
    /** This signal is emitted when the session context successfully changed the session
     */
    void sessionChanged();

    /** This signal is emitted if the view type changes
     */
    void viewTypeChanged ( SessionContext::ViewType viewType );
};

#endif // SESSIONCONTEXT_H
