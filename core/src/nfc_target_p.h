/*
 * Copyright (C) 2018-2020 Jolla Ltd.
 * Copyright (C) 2018-2020 Slava Monich <slava.monich@jolla.com>
 * Copyright (C) 2020 Open Mobile Platform LLC.
 *
 * You may use this file under the terms of BSD license as follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. Neither the names of the copyright holders nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NFC_TARGET_PRIVATE_H
#define NFC_TARGET_PRIVATE_H

#include "nfc_types_p.h"

#include <nfc_target.h>

typedef enum nfc_reactivate_status {
    NFC_REACTIVATE_STATUS_SUCCESS,   /* Reactivation successful */
    NFC_REACTIVATE_STATUS_GONE,      /* Target is done */
    NFC_REACTIVATE_STATUS_TIMEOUT    /* Reactivation timed out */
} NFC_REACTIVATE_STATUS;

typedef
void
(*NfcTargetReactivateFunc)(
    NfcTarget* target,
    NFC_REACTIVATE_STATUS status,
    void* user_data);

void
nfc_target_deactivate(
    NfcTarget* target)
    NFCD_INTERNAL;

gboolean
nfc_target_can_reactivate(
    NfcTarget* target)
    NFCD_INTERNAL;

gboolean
nfc_target_reactivate(
    NfcTarget* target,
    NfcTargetSequence* seq,
    NfcTargetReactivateFunc func,
    GDestroyNotify destroy,
    void* user_data)
    NFCD_INTERNAL;

void
nfc_target_set_reactivate_timeout(
    NfcTarget* target,
    guint ms)
    NFCD_INTERNAL;

guint
nfc_target_generate_id(
    NfcTarget* target)
    NFCD_INTERNAL;

gulong
nfc_target_add_gone_handler(
    NfcTarget* target,
    NfcTargetFunc func,
    void* user_data)
    NFCD_INTERNAL;

NfcTargetSequence*
nfc_target_sequence_ref(
    NfcTargetSequence* seq)
    NFCD_INTERNAL;

void
nfc_target_sequence_unref(
    NfcTargetSequence* seq)
    NFCD_INTERNAL;

void nfc_target_sequence_set_flags(
    NfcTargetSequence* seq,
    NFC_SEQUENCE_FLAGS flags)
    NFCD_INTERNAL;

#endif /* NFC_TARGET_PRIVATE_H */

/*
 * Local Variables:
 * mode: C
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
