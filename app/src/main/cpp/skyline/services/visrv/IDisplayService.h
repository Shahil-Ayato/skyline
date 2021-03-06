// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::visrv {
    /**
     * @brief This is the base class for all IDisplayService variants with common functions
     */
    class IDisplayService : public BaseService {
      protected:
        /**
         * @brief This is the parcel used in OpenLayer/CreateStrayLayer
         */
        struct LayerParcel {
            u32 type; //!< The type of the layer
            u32 pid; //!< The PID that the layer belongs to
            u32 bufferId; //!< The buffer ID of the layer
            u32 _pad0_[3];
            u8 string[0x8]; //!< "dispdrv"
            u64 _pad1_;
        };
        static_assert(sizeof(LayerParcel) == 0x28);

      public:
        IDisplayService(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Creates a stray layer using a display's ID and returns a layer ID and the corresponding buffer ID
         */
        Result CreateStrayLayer(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Destroys a stray layer by it's ID
         */
        Result DestroyStrayLayer(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);
    };
}
