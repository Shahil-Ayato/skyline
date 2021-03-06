// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::am {
    /**
     * @brief This is used to control the audio's volume
     * @url https://switchbrew.org/wiki/Applet_Manager_services#IAudioController
     */
    class IAudioController : public BaseService {
      private:
        float mainAppletVolume{1.0f}; //!< The volume that is expected to be used for the main applet
        float libraryAppletVolume{1.0f}; //!< The volume that is expected to be used for the library applet

      public:
        IAudioController(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Sets the expected volumes for an application
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetExpectedMasterVolume
         */
        Result SetExpectedMasterVolume(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Returns the main applet volume that is expected by the application
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetMainAppletExpectedMasterVolume
         */
        Result GetMainAppletExpectedMasterVolume(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Returns the library applet volume that is expected by the application
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetLibraryAppletExpectedMasterVolume
         */
        Result GetLibraryAppletExpectedMasterVolume(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x0, IAudioController, SetExpectedMasterVolume),
            SFUNC(0x1, IAudioController, GetMainAppletExpectedMasterVolume),
            SFUNC(0x2, IAudioController, GetLibraryAppletExpectedMasterVolume)
        )
    };
}
