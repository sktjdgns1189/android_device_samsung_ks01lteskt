$(call inherit-product, device/samsung/ks01lteskt/full_ks01lteskt.mk)

# Enhanced NFC
$(call inherit-product, vendor/dokdo/config/nfc_enhanced.mk)

# Inherit some common Dokdo-Project stuff.
$(call inherit-product, vendor/dokdo/config/common_full_phone.mk)

PRODUCT_DEVICE := ks01lteskt
PRODUCT_NAME := dokdo_ks01lteskt

# SH LANGUAGE SET
PRODUCT_DEFAULT_LANGUAGE := ko
PRODUCT_DEFAULT_REGION := KR

PRODUCT_LOCALES := en_US ko_KR en_GB en_CA en_AU en_NZ en_SG zh_CN zh_TW ja_JP fr_FR fr_BE fr_CA fr_CH it_IT it_CH es_ES de_DE de_AT de_CH de_LI nl_NL nl_BE cs_CZ pl_PL ru_RU # vi_VN

