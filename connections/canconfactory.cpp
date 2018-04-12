#include <QString>
#include "canconfactory.h"
#include "serialbusconnection.h"
#include "gvretserial.h"
#include "lawicelserial.h"

using namespace CANCon;

CANConnection* CanConFactory::create(type pType, QString pPortName)
{
    switch(pType) {
        case SOCKETCAN:
            return new SerialBusConnection(pPortName);
        case GVRET_SERIAL:
            return new GVRetSerial(pPortName);
        case LAWICEL_SERIAL:
            return new LawicelSerial(pPortName);
        default: {}
    }

    return NULL;
}
