/*
* kinetic-c
* Copyright (C) 2014 Seagate Technology.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
*/

#ifndef _KINETIC_CONNECTION_H
#define _KINETIC_CONNECTION_H

#include "kinetic_types.h"

bool KineticConnection_Connect(KineticConnection* connection,
    const char* host,
    int port,
    bool nonBlocking,
    int64_t clusterVersion,
    int64_t identity,
    const char* key);

void KineticConnection_Disconnect(KineticConnection* const connection);

void KineticConnection_IncrementSequence(KineticConnection* const connection);

void KineticConnection_ConfigureHeader(KineticConnection* const connection,
    KineticProto_Header* const header);

#endif // _KINETIC_CONNECTION_H
