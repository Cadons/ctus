/*
 * Copyright (c) 2024 Matteo Cadoni
 * This file is part of libtusclient, licensed under the MIT License.
 * See the LICENSE file in the project root for more information.
 */

#ifndef INCLUDE_TUSSTATUS_H_
#define INCLUDE_TUSSTATUS_H_

#include "ctus.h"

namespace TUS {
    enum class EXPORT_LIBTUSCLIENT TusStatus {
        READY,
        UPLOADING,
        FAILED,
        FINISHED,
        PAUSED,
        CANCELED
    };
}
#endif // INCLUDE_TUSSTATUS_H_
