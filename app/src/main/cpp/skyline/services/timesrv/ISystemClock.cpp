// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include "ISteadyClock.h"
#include "ISystemClock.h"

namespace skyline::service::timesrv {
    ISystemClock::ISystemClock(const SystemClockType clockType, const DeviceState &state, ServiceManager &manager) : type(clockType), BaseService(state, manager) {}

    Result ISystemClock::GetCurrentTime(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u64>(static_cast<u64>(std::time(nullptr)));
        return {};
    }

    Result ISystemClock::GetSystemClockContext(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u64>(static_cast<u64>(std::time(nullptr)));
        response.Push(SteadyClockTimePoint{static_cast<u64>(std::time(nullptr))});
        return {};
    }
}
