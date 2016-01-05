/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "E330S")) {
        /* ks01lteskt */
        property_set("ro.build.fingerprint", "samsung/ks01lteskt/ks01lteskt:5.0.1/LRX22C/E330SKSUDOH2:user/release-keys");
        property_set("ro.build.description", "ks01lteskt-user 5.0.1 LRX22C E330SKSUDOH2 release-keys");
        property_set("ro.product.model", "SHV-E330S");
        property_set("ro.product.device", "ks01lteskt");
    } else if (strstr(bootloader, "E330K")) {
        /* ks01ltektt */
        property_set("ro.build.fingerprint", "samsung/ks01ltektt/ks01ltektt:5.0.1/LRX22C/E330KKSUDOH2:user/release-keys");
        property_set("ro.build.description", "ks01ltektt-user 5.0.1 LRX22C E330KKSUDOH2 release-keys");
        property_set("ro.product.model", "SHV-E330K");
        property_set("ro.product.device", "ks01ltektt");
    } else if (strstr(bootloader, "E330L")) {
        /* ks01ltelgt */
        property_set("ro.build.fingerprint", "samsung/ks01ltelgt/ks01ltelgt:5.0.1/LRX22C/E330LKSUDOH2:user/release-keys");
        property_set("ro.build.description", "ks01ltelgt-user 5.0.1 LRX22C E330LKSUDOH2 release-keys");
        property_set("ro.product.model", "SHV-E330L");
        property_set("ro.product.device", "ks01ltelgt");
    } else {
        /* ks01ltexx */
        property_set("ro.build.fingerprint", "samsung/ks01ltexx/ks01ltexx:5.0.1/LRX22C/I9506XXUDOH2:user/release-keys");
        property_set("ro.build.description", "ks01ltexx-user 5.0.1 LRX22C I9506XXUDOH2 release-keys");
        property_set("ro.product.model", "GT-I9506");
        property_set("ro.product.device", "ks01ltexx");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
