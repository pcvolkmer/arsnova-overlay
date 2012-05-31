#include "stubconnection.h"

void StubConnection::requestLoggedIn() {
    emit this->requestFinished ( LoggedInResponse ( 3 ) );
}

void StubConnection::requestSession ( QString sessionKey ) {
    if ( sessionKey.isEmpty() ) {
        emit this->requestFinished ( SessionResponse ( QString(), "STUB" ) );
        return;
    }
    emit this->requestFinished ( SessionResponse ( "12345678", "STUB" ) );
}

void StubConnection::requestUnderstanding() {
    emit this->requestFinished ( UnderstandingResponse ( 1, 2, 3, 4 ) );
}