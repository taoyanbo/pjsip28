/* Activate Android specific settings in the 'config_site_sample.h' */
#define PJ_CONFIG_ANDROID 1
#define PJMEDIA_HAS_VIDEO	        0
#define PJMEDIA_HAS_OPENH264_CODEC	0
#define PJMEDIA_VIDEO_DEV_HAS_SDL       0
#define PJMEDIA_VIDEO_DEV_HAS_DSHOW     0
#define PJMEDIA_HAS_FFMPEG	        0
#define PJSIP_HAS_TLS_TRANSPORT 1
#define PJ_HAS_SSL_SOCK 1
#include <pj/config_site_sample.h>
