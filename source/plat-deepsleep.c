/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2017 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "deepSleepMgr.h"

#define DEBUG_PLAT

#ifdef DEBUG_PLAT
#define DEBUG_MSG(x,y...) printf(x,##y)
#else
#define DEBUG_MSG(x,y...) {;}
#endif

static DeepSleep_Return_Status_t deepSleepStatus = DEEPSLEEPMGR_NOT_INITIALIZED;

/**
 * @brief Initialize the underlying DeepSleep module.
 *
 * This function must initialize all aspects of the DeepSleep Management module.
 *
 * @param None.
 * @return    Return Code.
 * @retval    0 if successful.
 */
DeepSleep_Return_Status_t PLAT_DS_INIT(void)
{
    if (DEEPSLEEPMGR_NOT_INITIALIZED == deepSleepStatus) {
        deepSleepStatus = DEEPSLEEPMGR_ALREADY_INITIALIZED;
        // NOTE: RPi don't have any deep sleep support; DEEPSLEEPMGR_INIT_FAILURE is not required.
        DEBUG_MSG("PLAT_DS_INIT: RPi don't have any deep sleep support.\r\n");
        return DEEPSLEEPMGR_SUCCESS;
    }
    return DEEPSLEEPMGR_ALREADY_INITIALIZED;
}



DeepSleep_Return_Status_t PLAT_DS_TERM(void)
{
    if (DEEPSLEEPMGR_ALREADY_INITIALIZED == deepSleepStatus) {
        deepSleepStatus = DEEPSLEEPMGR_NOT_INITIALIZED;
        DEBUG_MSG("PLAT_DS_INIT: RPi don't have any deep sleep support.\r\n");
        return DEEPSLEEPMGR_SUCCESS;
    }
    return DEEPSLEEPMGR_NOT_INITIALIZED;
}

/**
 * @brief Set the Deep Sleep mode.
 *
 * This function sets the current power state to Deep Sleep
 *
 * @param [in]  deep_sleep_timeout timeout for the deepsleep in seconds
 * @return    Return Code.
 * @retval    0 if successful.
 */
DeepSleep_Return_Status_t PLAT_DS_SetDeepSleep(uint32_t deep_sleep_timeout, bool *isGPIOWakeup, bool networkStandby)
{
    if (NULL == isGPIOWakeup) {
        return DEEPSLEEPMGR_INVALID_ARGUMENT;
    }
    if (DEEPSLEEPMGR_ALREADY_INITIALIZED == deepSleepStatus) {
        // FIXME: RPi don't have any deep sleep support.
        DEBUG_MSG("PLAT_DS_SetDeepSleep: RPi don't have any deep sleep support.\r\n");
        return DEEPSLEEPMGR_SET_FAILURE;
    }
    return DEEPSLEEPMGR_NOT_INITIALIZED;
}


/**
 * @brief Wake up from DeepSleep
 *
 * Function to exit from deepsleep
 *
 * @param None
 * @return None
 */
DeepSleep_Return_Status_t PLAT_DS_DeepSleepWakeup(void)
{
    if (DEEPSLEEPMGR_ALREADY_INITIALIZED == deepSleepStatus) {
        // FIXME: RPi don't have any deep sleep support.
        DEBUG_MSG("PLAT_DS_DeepSleepWakeup: RPi don't have any deep sleep support.\r\n");
        return DEEPSLEEPMGR_WAKEUP_FAILURE;
    }
    return DEEPSLEEPMGR_NOT_INITIALIZED;
}

DeepSleep_Return_Status_t  PLAT_DS_GetLastWakeupReason(DeepSleep_WakeupReason_t *wakeupReason)
{
    if (NULL == wakeupReason) {
        return DEEPSLEEPMGR_INVALID_ARGUMENT;
    }
    if (DEEPSLEEPMGR_ALREADY_INITIALIZED == deepSleepStatus) {
        // FIXME: RPi don't have any deep sleep support.
        DEBUG_MSG("PLAT_DS_GetLastWakeupReason: RPi don't have any deep sleep support.\r\n");
        *wakeupReason = DEEPSLEEP_WAKEUPREASON_UNKNOWN;
        return DEEPSLEEPMGR_SUCCESS;
    }
    return DEEPSLEEPMGR_NOT_INITIALIZED;
}

DeepSleep_Return_Status_t PLAT_DS_GetLastWakeupKeyCode(DeepSleepMgr_WakeupKeyCode_Param_t *wakeupKeyCode)
{
    if (NULL == wakeupKeyCode) {
        return DEEPSLEEPMGR_INVALID_ARGUMENT;
    }
    if (DEEPSLEEPMGR_ALREADY_INITIALIZED == deepSleepStatus) {
        // TODO: RPi don't have any deep sleep support. Get the last wakeup key code fi available.
        DEBUG_MSG("PLAT_DS_GetLastWakeupKeyCode: RPi don't have any deep sleep support.\r\n");
        wakeupKeyCode->keyCode = 0;
        return DEEPSLEEPMGR_SUCCESS;
    }
    return DEEPSLEEPMGR_NOT_INITIALIZED;
}
