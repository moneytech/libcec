#pragma once
/*
 * This file is part of the libCEC(R) library.
 *
 * libCEC(R) is Copyright (C) 2011-2012 Pulse-Eight Limited.  All rights reserved.
 * libCEC(R) is an original work, containing original code.
 *
 * libCEC(R) is a trademark of Pulse-Eight Limited.
 *
 * This program is dual-licensed; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 * Alternatively, you can license this library under a commercial license,
 * please contact Pulse-Eight Licensing for more information.
 *
 * For more information contact:
 * Pulse-Eight Licensing       <license@pulse-eight.com>
 *     http://www.pulse-eight.com/
 *     http://www.pulse-eight.net/
 */

#include "CECCommandHandler.h"

namespace CEC
{
  class CVLCommandHandler : public CCECCommandHandler
  {
  public:
    CVLCommandHandler(CCECBusDevice *busDevice);
    virtual ~CVLCommandHandler(void) {};

    bool InitHandler(void);

    int HandleDeviceVendorCommandWithId(const cec_command &command);
    int HandleStandby(const cec_command &command);
    bool TransmitActiveSource(const cec_logical_address iInitiator, uint16_t iPhysicalAddress);
    bool TransmitPendingActiveSourceCommands(void);

    int HandleVendorCommand(const cec_command &command);
    bool PowerUpEventReceived(void);
    bool SupportsDeviceType(const cec_device_type type) const { return type != CEC_DEVICE_TYPE_RECORDING_DEVICE; };
    cec_device_type GetReplacementDeviceType(const cec_device_type type) const { return type == CEC_DEVICE_TYPE_RECORDING_DEVICE ? CEC_DEVICE_TYPE_PLAYBACK_DEVICE : type; }

  private:
    PLATFORM::CMutex m_mutex;
    bool             m_bActiveSourcePending;
    bool             m_bPowerUpEventReceived;
  };
};
